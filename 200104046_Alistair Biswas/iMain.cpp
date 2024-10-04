#include "iGraphics.h"

int mposx,  mposy, ex, ey;
int screenHeight=500, screenWidth=500;
int x=0, y=0, dy=10, score=0;

bool pop = true, blast = false, over= false;

char bc[4][30] = {"image\\red_balloon.bmp", "image\\green_balloon.bmp", "image\\shooting_pointer.bmp", "image\\explosion.bmp"};
char num[100];

void iDraw()
{

	iClear();

	iSetColor(0, 255, 0);
	iText(380, 480, "Alistair", GLUT_BITMAP_9_BY_15);
	iSetColor(255, 255, 255);
	iText(380, 460, "Score : ", GLUT_BITMAP_8_BY_13);

	sprintf(num, "%d", score);
	iText(450, 460, num, GLUT_BITMAP_8_BY_13);

	if (pop)
	{
		iShowBMP2(x+100, screenHeight+y, bc[0], 0);
	}
	
	if (!pop)
	{
		iShowBMP2(x+300, screenHeight+y, bc[1], 0);
	}

	iShowBMP2(mposx-25, mposy-25, bc[2], 0);

	if (blast)
	{
		iShowBMP2(ex, ey, bc[3], 0);
	}

	if (over)
	{
		iSetColor(255, 0, 0);
		iText(150, 250, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{

	mposx = mx;
	mposy = my;

}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if ( (mx >= 100 && mx <= 180) && (my <= screenHeight+y+100 && my >= screenHeight+y) )
		{
			pop = false;
			blast = true;

			y = 0;
			dy = 5;

			ex = mx-40;
			ey = my-40;

			score += 20;
		}
		else if ( (mx >= 300 && mx <= 380) && (my <= screenHeight+y+100 && my >= screenHeight+y) ) 
		{
			pop = true;
			blast = true;

			y = 0;
			dy = 10;

			ex = mx-40;
			ey = my-40;

			score += 10;
		}
		
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}

}

void iKeyboard(unsigned char key)
{

	if (key == '\r')
	{
		
	}

}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
				
	}

	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}

void move()
{

	y -= dy;

}

void explosion()
{

	blast = false;

}

void gameOver()
{

	if (screenHeight+y == 0)
	{
		over = true;
	}

}


int main()
{

	iSetTimer(50, move);

	iSetTimer(1000, explosion);
	
	iSetTimer(0, gameOver);

	iInitialize(screenWidth, screenHeight, "Balloon Shooting");
	
	iStart();

	return 0;

}