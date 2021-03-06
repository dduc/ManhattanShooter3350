// Amir Bakhtar
// 4/3/18
// Manhattan Shooter Main Menu, tutorial, and credits

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include "fonts.h"
#include "game.h"

using namespace std;

extern bool inGame;
extern bool inMainMenu;
extern int menuPosition;
extern int key; 

void renderPointer(const int, GLuint);
void renderMainMenu(const int, const int, GLuint);
void renderTutorial(const int, const int, GLuint);
void renderCredits(const int, const int, GLuint);

void renderPointer(const int xres, GLuint texture) { 
	int arrowX;
	int arrowY;
	if (menuPosition == 1) {
		arrowX = xres/2 - 165;
		arrowY = 345;
	} else if (menuPosition == 2) {
		arrowX = xres/2 - 130;
		arrowY = 295;
	} else if (menuPosition == 3) {
		arrowX = xres/2 - 130;
		arrowY = 245;
	} else if (menuPosition == 4) {
		arrowX = xres/2 - 100;
		arrowY = 195;
	}
	float sh = 20.0;
	float sw = sh*1.666667;
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(arrowX, arrowY, 0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glColor4ub(255,255,255,255);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex2i(-sw,-sh);
	glTexCoord2f(0.0f, 0.0f); glVertex2i(-sw, sh);
	glTexCoord2f(1.0f, 0.0f); glVertex2i( sw, sh);
	glTexCoord2f(1.0f, 1.0f); glVertex2i( sw,-sh);
	glEnd();
	glPopMatrix();	
}

void renderMainMenu(const int xres, const int yres, GLuint texture) { 
	   int sh = yres/2;
	   int sw = (sh*1.33333);
	   glPushMatrix();
	   glTranslatef(xres/2, yres/2, 0);
	   glBindTexture(GL_TEXTURE_2D, texture);
	   glEnable(GL_ALPHA_TEST);
	   glAlphaFunc(GL_GREATER, 0.0f);
	   glColor4ub(255,255,255,255);
	   glBegin(GL_QUADS);
	   glTexCoord2f(0.0f, 1.0f); glVertex2i(-sw,-sh);
	   glTexCoord2f(0.0f, 0.0f); glVertex2i(-sw, sh);
	   glTexCoord2f(1.0f, 0.0f); glVertex2i( sw, sh);
	   glTexCoord2f(1.0f, 1.0f); glVertex2i( sw,-sh);
	   glEnd();
	   glPopMatrix();
}

void renderTutorial(const int xres, const int yres, GLuint texture) { 
	   int sh = yres/2;
	   int sw = (sh*1.33333);
	   glPushMatrix();
	   glTranslatef(xres/2, yres/2, 0);
	   glBindTexture(GL_TEXTURE_2D, texture);
	   glEnable(GL_ALPHA_TEST);
	   glAlphaFunc(GL_GREATER, 0.0f);
	   glColor4ub(255,255,255,255);
	   glBegin(GL_QUADS);
	   glTexCoord2f(0.0f, 1.0f); glVertex2i(-sw,-sh);
	   glTexCoord2f(0.0f, 0.0f); glVertex2i(-sw, sh);
	   glTexCoord2f(1.0f, 0.0f); glVertex2i( sw, sh);
	   glTexCoord2f(1.0f, 1.0f); glVertex2i( sw,-sh);
	   glEnd();
	   glPopMatrix();
}

void renderCredits(const int xres, const int yres, GLuint texture) { 
	   int sh = yres/2;
	   int sw = (sh*1.33333);
	   glPushMatrix();
	   glTranslatef(xres/2, yres/2, 0);
	   glBindTexture(GL_TEXTURE_2D, texture);
	   glEnable(GL_ALPHA_TEST);
	   glAlphaFunc(GL_GREATER, 0.0f);
	   glColor4ub(255,255,255,255);
	   glBegin(GL_QUADS);
	   glTexCoord2f(0.0f, 1.0f); glVertex2i(-sw,-sh);
	   glTexCoord2f(0.0f, 0.0f); glVertex2i(-sw, sh);
	   glTexCoord2f(1.0f, 0.0f); glVertex2i( sw, sh);
	   glTexCoord2f(1.0f, 1.0f); glVertex2i( sw,-sh);
	   glEnd();
	   glPopMatrix();
}

/*
// Prototypes
void main_menu(int, int);
void tutorial(int,* int);
void credits(int, int);
void mainmenu(GLuint, int, int);
void rWithoutAlpha(GLuint, int, int);
void rWithAlpha(GLuint, int, int, int, int);
int menu_position;
int start_game;
unsigned int red = 0xff0000

void main_menu(int xres, int yres)
{
int highlight_x;
int highlight_y;

if (gl.menu_position == 1)
{
highlight_x = xres/2;
highlight_y = yres*0.4;
}
else if (gl.menu_position == 2)
{
highlight_x = xres/2;
highlight_y = yres*0.3;
}
else if (gl.menu_position == 3)
{
highlight_x = xres/2;
highlight_y = yres*0.2;
}
else if (gl.menu_position == 4)
{
highlight_x = xres/2;
highlight_y = yres*0.1;
}

// Main Menu Background
rWithoutAlpha(gl.mainmenuBackground, gl.xres, gl.yres);

if (gl.keys[XK_Return])
{
if (gl.menu_position == 1)
{
gl.display_startgame = true;
gl.keys[XK_Return] = false;
}
else if (gl.menu_position == 2)
{
gl.display_startgame = false;
gl.display_tutorial = true;
gl.keys[XK_Return] = false;
}
else if (gl.menu_position == 3)
{
gl.display_startgame = false;
gl.display_credits = true;
}
else if (gl.menu_position == 4)
{
gl.display_startgame = false;
gl.done = 1;
}
}

void mainmenu(GLuint texture, int xres, int yres)
{
glPushMatrix();
glColor3f(1 ,1 ,1);
glBindTexture(GL_TEXTURE_2D, texture);
glBegin(GL_QUADS);
glTexCoord2f(0.0, 0.0); glVertex2i(0,0);
glTexCoord2f(0.0, 0.0); glVertex2i(0,yres);
glTexCoord2f(0.0, 0.0); glVertex2i(xres,yres);
glTexCoord2f(0.0, 0.0); glVertex2i(xres,0);
glEnd();
glPopMatrix();
}
}

void credits(int xres, int yres)
{
	// Background from main menu

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, gl.mainmenuBackground);
	glAlphaFunc(GL_GREATER, 0.0f);
	glColor4ub(242,242,242,242);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0); glVertex2i(0,0);
	glTexCoord2f(0.0, 0.0); glVertex2i(0,yres);
	glTexCoord2f(1.0, 0.0); glVertex2i(xres,yres);
	glTexCoord2f(1.0, 1.0); glVertex2i(xres,0);
	glEnd();
	glPopMatrix();

	Rect r;

	r.bot = yres*.69;
	r.left = xres/2;
	r.center = yres/2;

	//unsigned int red = 0xff0000
	ggprint40(&r, 16, red, "The Homies");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Partner 1 - fill in person's role here");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Amir");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Partner 2");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Dirk aka Rhaekon");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Partner 3");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Omar da GOAT");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Partner 4");
	ggprint12(&r, 16, red, "                                                                        ");
	ggprint40(&r, 16, red, "Princess Kenny the legend");
	ggprint12(&r, 16, red, "                                                                        ");


	if (gl.keys[XK_Return])
	{
		if (gl.display_credits)
		{
			gl.display_credits = false;
			gl.display_mainmenu = true;
			gl.keys[XK_Return] = false;
		}
	}
}
*/
