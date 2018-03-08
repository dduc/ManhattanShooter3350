/* Author: Dirk Duclos



Tasks Assigned:
  1. Basic AI for mafia
  2. Colission detection



*/
#include"fonts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include <ctime>
#include <sstream>


const double oobillion = 1.0 / 1e9;
double timeDiff(struct timespec *start, struct timespec *end)
{
	//return the difference in two times.
	return (double)(end->tv_sec - start->tv_sec ) +
		(double)(end->tv_nsec - start->tv_nsec) * oobillion;
}

// vector
struct Vec {
	float x, y, z;
        
};

// make an object to check for colission
struct Shape {
	//int left,right,top,bottom;
        float width, height;
	float radius;
	Vec center;
	struct timespec end;
};



//Function to convert RGB value to hex
unsigned long createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

//Function to display name on screen
void displayName(int x, int y, float r, float g, float b, const char *text)
{

    // Clears screen of asteroids program objects (ship, asteroids, etc)
    //glClear(GL_COLOR_BUFFER_BIT);
    
    // Make a new box to store text
    Rect r2;
    
    // Location of text on screen
    r2.bot = x;
    r2.left = y;

    //Call RGB converter function to get Hex function parameter for ggprint
    unsigned long hexrgb = createRGB(r,g,b);
    ggprint16(&r2, 16, hexrgb, text);
}

//Draw objects

void drawShape()
{       
        struct timespec start;
	clock_gettime(CLOCK_REALTIME, &start);
	Shape s;
	s.center.x=0;
        s.center.y=0;
        s.center.z=0;
 	//s.left = 200;
	//s.bottom = 200;
	glColor3ub(255,0,0);
	glPushMatrix();
	glTranslatef(s.center.x, s.center.y, s.center.z);
	float w = 100;
	float h = 20;
	glBegin(GL_QUADS);
		glVertex2i(-w, -h);
		glVertex2i(-w,  h);
		glVertex2i( w,  h);
		glVertex2i( w, -h);
	glEnd();
	glPopMatrix();
	struct timespec end;
	clock_gettime(CLOCK_REALTIME, &end);
	static double runningTime = timeDiff(&start, &end);
	std::stringstream ss;
	ss.precision(9);
	ss << std::fixed << runningTime;
	const char* str = ss.str().c_str();
	// Make a new box to store text
        Rect r3;
            
        // Location of text on screen
        r3.bot = 100;
        r3.left = 300;
	ggprint16(&r3, 20, 0x00fff00, str);


}

