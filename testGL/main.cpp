#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <time.h>
#include <ctime> 
#include "imageloader.h"
using namespace std;


float carX=0;

float z=-60.0;
float z1=-60.0;
float z2=-60.0;
float a=0.0;
float _angle = 0.0;
float x = 90.0;


float coinPos1=-60.0;
float coinPos2=-50.0;


GLuint _textureId;
GLuint _textureId1;
GLuint _textureId2;
GLuint backview;
GLuint frontview;
GLuint leftview;
GLuint rightview;
GLuint topview;

GLuint extra;

void update(int value)
{
	coinPos1+=.04;
	coinPos2+=.02;

	z+=.05;
	z1+=.05;
	z2+=.05;
	
	if(coinPos1>=10){
	
		coinPos1=-60.0;
	
	}
	
	if (z>=10  )
	{
		z=-60.0;
		z1=-60.0;
	}
	if (z2>=20)
	{
		z2=-60.0;
	}

	if(coinPos2>=0)
	{
		coinPos2=-60;
	}
	
	glutPostRedisplay();
	glutTimerFunc(1, update, 0);
}

void cylinder(float r,float l)
	#define c 3.14/180
{
	float x,y,z; int d;
	glBegin(GL_QUAD_STRIP);
	for( d=0;d<=362;d+=1)
	{
		x=r*cos(c*d);
		z=r*sin(c*d);
		y=0;
		glVertex3f(x,y,z);

		y=l;
		glVertex3f(x,y,z);
	}
	glEnd();
}

void sky()
{
	glPushMatrix();

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTranslatef(0.0,0.0,-61.0);

			glBegin(GL_QUADS);
				glColor3f(1.0,1.0,1.0);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-50,0,0);
				glTexCoord2f(1.0,0.0);
				glVertex3f( 50,0,0);
				glTexCoord2f(1.0, 1.0);
				glVertex3f( 50,10,-20);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-50,10,-10);
			glEnd();

		glPopMatrix();

}

void road()
{
			

		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTranslatef(0.0,0.0,-1.0);

			glBegin(GL_QUADS);
				glColor3f(1.0,1.0,1.0);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-2,0,0);
				glTexCoord2f(0.0,2.0);
				glVertex3f( 2,0,0);
				glTexCoord2f(2.0, 2.0);
				glVertex3f( 2,0,-60);
				glTexCoord2f(2.0, 0.0);
				glVertex3f(-2,0,-60);
			glEnd();

		glPopMatrix();


		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId2);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
			glTranslatef(0.0,0.0,z);
	
			glBegin(GL_QUADS);
			glColor3f(1.0,1.0,1.0);
				glVertex3f(1,0.01,0);
				glVertex3f(0.8,0.01,0);
				glVertex3f(0.8,0.01,-5);
				glVertex3f(1,0.01,-5);
			glEnd();

		glPopMatrix();


		glPushMatrix();

			glTranslatef(0.0,0.0,z1);
			glBegin(GL_QUADS);
				glVertex3f(-1,0.01,0);
				glVertex3f( -0.8,0.01,0);
				glVertex3f( -0.8,0.01,-5);
				glVertex3f(-1,0.01,-5);
			glEnd();
	
		glPopMatrix();

		
}

void coin()
{
	
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(-.5, 0.5,coinPos1);
	glutSolidTorus(0.1, .20,8.0, 5);

	glPopMatrix();

	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(1, 0.5,coinPos2);
	glutSolidTorus(0.1, .20,8.0, 5);

	glPopMatrix();


}
void car()

{
	
	glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, backview);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();

			
	
			//glTranslatef(0.0,0.0,10);
	
			glBegin(GL_QUADS);
			glColor3f(1.0,1.0,1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(carX-.3,0.2,-2);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(carX+.3,0.2,-2);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(carX+.3,.7,-2);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(carX-.3,.7,-2);
			glEnd();

		glPopMatrix();


		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, frontview);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();

			
	
			//glTranslatef(0.0,0.0,10);
	
			glBegin(GL_QUADS);
			glColor3f(1.0,1.0,1.0);

				//glTexCoord2f(0.0, 0.0);
				glVertex3f(carX-.3,0.2,-4);
				//glTexCoord2f(1.0, 0.0);
				glVertex3f(carX+.3,0.2,-4);
				//glTexCoord2f(1.0, 1.0);
				glVertex3f(carX+.3,.7,-4);
				//glTexCoord2f(0.0, 1.0);
				glVertex3f(carX-.3,.7,-4);
			glEnd();

		glPopMatrix();

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, leftview);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();

			
	
			//glTranslatef(0.0,0.0,10);
	
			glBegin(GL_QUADS);
			glColor3f(1.0,1.0,1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(carX-.3,0.2,-2);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(carX-.3,0.7,-2);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(carX-.3,.7,-4);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(carX-.3,.2,-4);
			glEnd();

		glPopMatrix();

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, rightview);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();

			
	
			//glTranslatef(0.0,0.0,10);
	
			glBegin(GL_QUADS);
			glColor3f(1.0,1.0,1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(carX+.3,0.2,-2);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(carX+.3,0.7,-2);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(carX+.3,.7,-4);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(carX+.3,.2,-4);
			glEnd();

		glPopMatrix();

		glPushMatrix();

			//middleTop
	
			//glTranslatef(0.0,0.0,10);
	
			glBegin(GL_QUADS);
			glColor3f(0.0,0.0,0.0);

				//glTexCoord2f(0.0, 0.0);
				glVertex3f(carX-.3,0.7,-2);
				//glTexCoord2f(1.0, 0.0);
				glVertex3f(carX+.3,0.7,-2);
				//glTexCoord2f(1.0, 1.0);
				glVertex3f(carX+.3,.7,-4);
				//glTexCoord2f(0.0, 1.0);
				glVertex3f(carX-.3,.7,-4);
			glEnd();

		glPopMatrix();

		


		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, extra);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
			//glTranslatef(0.0,0.0,10);
	
			glBegin(GL_QUADS);
			glColor3f(1.0,1.0,1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(carX-.2,0.8,-2.2);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(carX+.2,0.8,-2.2);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(carX+.2,.8,-3.2);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(carX-.2,.8,-3.2);
			glEnd();

		glPopMatrix();


}


void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	gluLookAt(0, 2.5, .5, 0.0,0,-6, 0.0, 1.0, 1.0);
	
	sky();
	road();
	coin();
	car();
	cylinder();

	glFlush();
	glutSwapBuffers();
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}



void keypressHandler(unsigned char key, int x, int y) 
{
	switch (key) 
{
	case 'a':
		if(carX>-1)
		{
			carX-=0.02;
		}
		

		glutPostRedisplay();
		break;

	case 'd':
		if(carX<1)
		{
			carX+=0.02;

		}
		

		glutPostRedisplay();

		}
}

void initialize() {
	
	glClearColor(0.0, 1.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 100.0);
	Image* image = loadBMP("F:\\images\\texture1.bmp");
	Image* image2 = loadBMP("F:\\images\\texture2.bmp");
	//Image* back = loadBMP("F:\\images\\back.bmp");
	//Image* front = loadBMP("F:\\images\\front.bmp");
	//Image* left = loadBMP("F:\\images\\left.bmp");
	//Image* right = loadBMP("F:\\images\\right.bmp");
	//Image* top = loadBMP("F:\\images\\top.bmp");
	
	_textureId = loadTexture(image);
	_textureId1 = loadTexture(image2);

//	backview= loadTexture(back);
	// frontview= loadTexture(front);
	// leftview= loadTexture(left);
	// rightview= loadTexture(right);
	// topview= loadTexture(top);
	//delete image;
	//delete image2;
	//delete back;
	//delete front;
	//delete left;
	//delete right;
//	delete top;
}

void lightSetting()
{
float lightAmbient[4] = {0.0, 0.0, 0.0, 1.0};
	float lightDiffuse[4] = {1.0, 1.0, 1.0, 1.0};
	float lightSpecular[4] = {1.0, 1.0, 1.0, 1.0};
	float lightPosition[4] = {3.0, 6.0, 7.0, 1.0};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	float materialSpecular[4] = {1.0, 1.0, 1.0, 1.0};
	float materialShininess[1] = {100};

	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 330);
	
	glutCreateWindow("Textures");
	initialize();
	lightSetting();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(keypressHandler);
	glutTimerFunc(30, update, 0);
	glutMainLoop();
	return 0;
}
