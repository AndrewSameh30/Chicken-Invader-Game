#include <stdio.h>
#include <math.h>
#include <random>
#include <glut.h>

// A power up can appear at a random
//positionand in that case the player should try to acquire that power up, if successful, the
//player becomes immune to bullets fired from the enemy.

//The game
//ends either if the player loses all lives or the health bar of the enemy becomes empty or zero.



//2) The enemy should have at least 3 primitive type. for example, irregular 2D polygons as seen in
//the figure above.


float dx = 0;
float dy = 0;
float xflag = -2;
float yflag = -1;
int counterx = 1;
int countery = 1;

float bulletPosition = 4;
float playerPositionX = 0;
float playerPositionY = 0;

float enemyBullet = 0;
float enemyBulletX;
float enemyBulletY;
int lives = 3;
int PlayerFlag = 1;

float PowerUpX;
float PowerUpY;

int playercolor = 1;
float healthBarLength = 40;

int powerUpFlag = 0;

void Anim()
{
	
	enemyBullet -= 1;
	if (enemyBullet < -200)
	{
		enemyBullet = 0;
	}
	
	bulletPosition += 4;
	
	//if (counterx%10 == 0) //	start of drawing and dimming phase
	if(dx>240 || dx<-30)
	{

		xflag *= -1;
		
		dx += xflag;

		counterx++;
		for (int i = 0; i < 20000000; i++);
	}
	else
	{
		dx += xflag;
		
		counterx++;
		for (int i = 0; i < 20000000; i++);
	}
	if (countery % 15 == 0) //	start of drawing and dimming phase
	{
	
		yflag *= -1;
	
		dy += yflag;
		countery++;
		for (int i = 0; i < 20000000; i++);
	}
	else
	{

		dy += yflag;
		countery++;
		for (int i = 0; i < 20000000; i++);
	}

	glutPostRedisplay();
}





void Key(unsigned char key, int x, int y) {


	int selectedBar = 1;
	// check the selected bar, to decide which variable to control: bar1Y, bar2Y or bar3Y
	switch (selectedBar) {
	case 1:
		// if the key 'a' is pressed, increment bar1Y until it reaches the top limit of its support
		if (key == ' ')
			bulletPosition=4;
		if (key == 'a' || key == 'A')
			playerPositionX -= 4;
		if (key == 'd' || key == 'D')
			playerPositionX += 4;
		if (key == 'w' || key == 'W')
			playerPositionY += 4;
		if (key == 's' || key == 'S')
			playerPositionY -= 4;


		// if the key 'z' is pressed, decrement bar1Y until it reaches the bottom limit of its support
		/*if (key == 'z' && bar1Y > -270)
			bar1Y--;
		break;
	case 2:
		// if the key 'a' is pressed, increment bar2Y until it reaches the top limit of its support
		if (key == 'a' && bar2Y < 90)
			bar2Y++;
		// if the key 'z' is pressed, decrement bar2Y until it reaches the bottom limit of its support
		if (key == 'z' && bar2Y > -90)
			bar2Y--;
		break;
	case 3:
		// if the key 'a' is pressed, increment bar3Y until it reaches the top limit of its support
		if (key == 'a' && bar3Y < 20)
			bar3Y++;
		// if the key 'z' is pressed, decrement bar3Y until it reaches the bottom limit of its support
		if (key == 'z' && bar3Y > -20)
			bar3Y--;*/
		break;
	}

	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();
}

/*void Timer(int value) {
	// set the ball's Y coordinate to a random number between 10 and 780 (since the window's height is 800)
	ballY = rand() % 780 + 10;

	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(20 * 1000, Timer, 0);
}*/

void Circle(float x,float y,float radius) {
	//float x, y;
	int i;
	float pi = 3.14;
	//GLfloat radius;
	int triangleAmount = 40;
	GLfloat twicePI = 2.0 * pi;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(238, 139, 21);
	//x = 0; y = -70; radius = 20;

	twicePI = 2.0 * pi;

	glPushMatrix();

	//glVertex2f(x1, y1);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x + (radius * cos(i * twicePI / triangleAmount)),
			y + (radius * sin(i * twicePI / triangleAmount)));
	}

	//glPushMatrix();


	glPushMatrix();

	/*glBegin(GL_POLYGON);
	glVertex3f(-50.0f, -50.0f, 0.0f);
	glVertex3f(-50.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -50.0f, 0.0f);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();*/

	glEnd();
	glutSwapBuffers();
}

void Square(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x+w, y, 0.0f);
	glVertex3f(x+w, y+h, 0.0f);
	glVertex3f(x, y+h, 0.0f);
	glEnd();
}

void RightFeather(float x, float y, float l) {
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.0f);
	glVertex3f(x, y + 2, 0.0f);

	glVertex3f(x + l, y + 4, 0.0f);
	glVertex3f(x + l + 2, y, 0.0f);
	glVertex3f(x + l, y - 4, 0.0f);

	glVertex3f(x, y - 2, 0.0f);
	glEnd();
}

void LeftFeather(float x, float y, float l) {
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5, 0.0f);
	glVertex3f(x, y+2, 0.0f);

	glVertex3f(x - l, y + 4, 0.0f);
	glVertex3f(x - l - 2, y, 0.0f);
	glVertex3f(x - l, y - 4, 0.0f);

	glVertex3f(x, y - 2, 0.0f);
	glEnd();
}

void Legs(float x, float y) {
	glBegin(GL_LINES);
	glVertex3f(x, y , 0.0f);
	glVertex3f(x, y-5, 0.0f);
	glEnd();
}

void PowerUp(float x,float y) {


	glBegin(GL_TRIANGLES);

	glVertex3f(x, y, 0);
	glVertex3f(x+10, y, 0);
	glVertex3f(x+5, y+10, 0);
	glEnd();
}

void Chicken(float x, float y)
{
	Circle(x + dx, y + 160 + dy, 10);
	RightFeather(x + 10 + dx, y + 160 + dy, 5);
	LeftFeather(x - 10 + dx, y + 160 + dy, 5);
	Circle(x + dx, y + 170 + dy, 5);
	Legs(x + 5 + dx, y + 150 + dy);
	Legs(x - 5 + dx, y + 150 + dy);
}

void Player(float x, float y, int flag, int color) {
	if (flag == 0) {
		
		for (int i = 0; i < 10; i++) {
	glBegin(GL_LINES);
			glVertex3f(x, y + i,0);
			glVertex3f(x + 10, y + i,0);
	glEnd();
		}
		
	}
	else
	{
		if (color == 1) {
			glColor3f(1.0, 0.0, 1.0);
		}
		else
		{
			glColor3f(1.0, 1.0, 1.0);
		}
			Square(150 + x, 50 + y, 20, 20);
			Square(157 + x, 60 + y, 6, 20);
			Legs(152 + x, 50 + y);
			Legs(168 + x, 50 + y);
			Circle(152 + x, 55 + y, 5);
			Circle(168 + x, 55 + y, 5);

	}
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	/*glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(150.0f, 200.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(100.0f, 100.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(200.0f, 100.0f, 0.0f);
	glEnd();*/

	//for (int j = 1; j <= 3; j++) {
		//for (int i = 1; i <= 5; i++) {
			/*Circle(i * 50 + dx, j * 40 + 160 + dy, 10);
			RightFeather(i * 50 + 10 +dx, j * 40 + 160 + dy, 5);
			LeftFeather(i * 50 - 10 + dx, j * 40 + 160 + dy, 5);
			Circle(i * 50+dx, j*40+170 + dy, 5);
			Legs(i * 50 + 5 + dx, j * 40 + 150 + dy);
			Legs(i * 50 - 5 + dx, j * 40 + 150 + dy);*/
	int i = 1;
	int j = 1;
	if (healthBarLength > 0) {
		Chicken(i * 50, j * 40);
	}
			int r = rand();
			if (r % 30 == 0)
			{
				glColor3f(0.0, 0.0, 1.0);
				Square(i * 50 +dx, j * 40 + 170 + enemyBullet, 4, 4);
				
				enemyBulletX = i * 50;
				enemyBulletY = j * 40 + 170 + enemyBullet;
				if (enemyBulletX > 150 + playerPositionX && enemyBulletX < 150 + playerPositionX + 20 && enemyBulletY >=70+ playerPositionY && enemyBulletY <=100+ playerPositionY && powerUpFlag == 0)
				{
					Player(150 + playerPositionX, 60 + playerPositionY, 0, playercolor);
					PlayerFlag = 0;
					lives--;
				}
			}
		//}
	//}
	if (PlayerFlag == 1) {
		Player(playerPositionX, playerPositionY, 1, playercolor);
	}
	//glColor3f(1.0, 0.0, 1.0);
	//Square(150 + playerPositionX, 50, 20, 20);
	//Square(157 + playerPositionX, 60, 6, 20);
	if (enemyBulletX > 150 + playerPositionX && enemyBulletX < 150 + playerPositionX + 20 && enemyBulletY >= 70+ playerPositionY && enemyBulletY <= 100+ playerPositionY && powerUpFlag==0)
	{
		lives--;
	}
	glColor3f(1.0, 1.0, 1.0);
	Square(157+ playerPositionX, 64+ bulletPosition + playerPositionY, 4, 4);

	//LIVES
	for (int i = 0; i < lives; i++) {
		glColor3f(0.0f, 1.0f, 0.0f);
		Square(270+i*10, 290, 4, 4);
	}
	//Square(280, 290, 4, 4);
	//Square(290, 290, 4, 4);

	//Health bar
	int healthBar = rand();
	//printf("%f\n%f\n%f\n%f\n", (50+dx), (150 + playerPositionX), (200 + dy), 80 + bulletPosition);
	//printf("===========================================================\n");
	if ((50+dx) > 150 + playerPositionX && (50 + dx) < 150 + playerPositionX + 20 && (200+dy) >= 60 + bulletPosition+playerPositionY && (200 + dy) <= 80 + bulletPosition+playerPositionY)
	{
		healthBarLength -= 5;
		glColor3f(1.0f, 0.0f, 0.0f);
		Square(0, 290, healthBarLength, 4);
	}
	else {
		glColor3f(1.0f, 0.0f, 0.0f);
		Square(0, 290, healthBarLength, 4);
	}
	/*if (healthBar % 100 < 5)
	{
		healthBarLength -= 5;
		glColor3f(1.0f, 0.0f, 0.0f);
		Square(0, 290, healthBarLength, 4);
	}*/

	/*Circle(100, 160, 10);
	Circle(100, 170, 5);

	Circle(200, 160, 10);
	Circle(200, 170, 5);*/

	//PowerUp
	int powerUp = rand();
	PowerUpX = rand()%300;
	PowerUpY = rand() % 300;
	if (powerUp % 100 < 10)
	{
		powerUpFlag = 0;

		PowerUp(PowerUpX, PowerUpY);
	}
	if (PowerUpX > 150 + playerPositionX && PowerUpX < 150 + playerPositionX + 20 && PowerUpY >= 70+playerPositionY && PowerUpY <= 100+ playerPositionY)
	{
		powerUpFlag = 1;
		playercolor += 1;
		playercolor = playercolor % 2;
	}
	

	/*glBegin(GL_TRIANGLES);
		
		glColor3f(1.0f, 0.0f, 0.0f);
		
		glVertex3f(150.0f, 200.0f, 0.0f);
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(100.0f, 100.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(200.0f, 100.0f, 0.0f);
	glEnd();*/

	glFlush();
}
void display2(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 0.0f);
	glEnd();
	glFlush();
}

void main(int argc, char** argr) {
	glutInit(&argc, argr);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Chicken Invader by Andrew Sameh");
	glutDisplayFunc(Display);
	glutKeyboardFunc(Key);
	glutIdleFunc(Anim);

	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 300, 0.0, 300);

	glutMainLoop();
}


