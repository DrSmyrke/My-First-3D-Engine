#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;
// стартовые параметры
int WindW=500;		// Ширина окна
int WindH=500;		// Высота окна
bool curs=false;	// Наличие програмного курсора
int mbut;		// Кнопка мыши
int mbutstat;		// Статус нажатия кнопки мыши
int campxz;		// Положение камеры в четверти плоскости XZ
GLfloat X=0.0f;		// Перевести экран в направлении x
GLfloat Y=0.0f;		// Перевести экран в направлении y
GLfloat Z=0.0f;		// Перевести экран в направлении z
GLfloat rotX=0.0f;	// Поворот экрана по оси x
GLfloat rotY=0.0f;	// Поворот экрана по оси y
GLfloat rotZ=0.0f;	// Поворот экрана по оси z
GLfloat rotLx=0.0f;	// Перевести экран влево или вправо
GLfloat rotLy=0.0f;	// Перевести экран вверх или вниз
GLfloat rotLz=0.0f;	// Перевести экран в зум

GLfloat r;

// отрисовка земли
void drawGround(){float fex=20,step=1,y=-0.4;int iLine;glLineWidth(1);glColor3f(0.108,0.108,0.108);glBegin(GL_LINES);for(iLine=-fex;iLine<=fex;iLine+=step){glVertex3f(iLine,y,fex);glVertex3f(iLine,y,-fex);glVertex3f(fex,y,iLine);glVertex3f(-fex,y,iLine);}glEnd();}

// Инициализация OpenGL
void init(void){
glClearColor(0.0, 0.0, 0.0, 0.0);
glShadeModel(GL_FLAT);
glEnable(GL_LINE_SMOOTH);
glHint(GL_LINE_SMOOTH_HINT,GL_NICEST); // Установка сглаживания линний
}

// отрисовка экрана
void display(void){ 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
drawGround();
glLineWidth(3);glColor3f(0.0f, 0.6f, 0.9f);glutWireCube(10.0);


//glPushMatrix();
//glRotatef(rotX,1.0,0.0,0.0); // Rotate on x
//glRotatef(rotY,0.0,1.0,0.0); // Rotate on y
//glRotatef(rotZ,0.0,0.0,1.0); // Rotate on z
//glTranslatef(X, Y, Z); 	// Translates the screen left or right, 
			// up or down or zoom in zoom out
// Draw the positive side of the lines x,y,z
//glBegin(GL_LINES);
//glColor3f (0.0, 1.0, 0.0); // Green for x axis
//glVertex3f(0,0,0);
//glVertex3f(10,0,0);
//glColor3f(1.0,0.0,0.0); // Red for y axis
//glVertex3f(0,0,0);
//glVertex3f(0,10,0);
//glColor3f(0.0,0.0,1.0); // Blue for z axis
//glVertex3f(0,0,0); 
//glVertex3f(0,0,10);
//glEnd();

// Dotted lines for the negative sides of x,y,z
//glEnable(GL_LINE_STIPPLE); 	// Enable line stipple to use a 
				// dotted pattern for the lines
//glLineStipple(1, 0x0101); 	// Dotted stipple pattern for the lines
//glBegin(GL_LINES); 
//glColor3f (0.0, 1.0, 0.0); 	// Green for x axis
//glVertex3f(-10,0,0);
//glVertex3f(0,0,0);
//glColor3f(1.0,0.0,0.0); 	// Red for y axis
//glVertex3f(0,0,0);
//glVertex3f(0,-10,0);
//glColor3f(0.0,0.0,1.0); 	// Blue for z axis
//glVertex3f(0,0,0);
//glVertex3f(0,0,-10);
//glEnd();
//glDisable(GL_LINE_STIPPLE); 	// Disable the line stipple
//glPopMatrix(); 		// Don't forget to pop the Matrix
glutSwapBuffers();
}

// Процедура перемещения мыши
void motion(int x,int y){
// Движение камеры при нажатии правой кнопки мыши
if(mbut==2 and mbutstat==0){
float ly=WindH/180;

//rotLx=0.0f;rotLy=0.0f;rotLz=0.0f;
//int r=(WindH/2-y)/2;
if(y<WindH/2 and y>0){r++;}
//if(y>WindH/2){r=(WindH-y)*ly;}
rotLx=0.2f;
cout << r << "\n";
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(r,rotLx,rotLy,rotLz);
//gluLookAt(rotLx,rotLy,rotLz,0.0,0.0,0.0,0.0,1.0,0.0);
//cout << x << "\n";
//cout << y << "\n";
//cout << WindW << "\n";
//cout << WindH << "=\n";
glutPostRedisplay();
}
}

// Процедура событий мыши
void mouse(int button,int state,int x,int y){
mbut=button;
mbutstat=state;
//mouseX=x;mouseY=y;
//if(button==0 and state==0){plz--;}
//if(button==2 and state==0){plz++;}
//Bmouse=button;
//Mstate=state;
//cout << state << "\n";
//cout << button << "\n";
//cout << x << "\n";
//cout << y << "\n";
}

// Процедура отображения
void reshape(int w,int h){
glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity(); 
gluPerspective(75,(GLfloat)w/(GLfloat)h,0.10,100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt (rotLx,rotLy,15.0+rotLz,0.0,0.0,0.0,0.0,1.0, 0.0);
WindW=w;
WindH=h;
}

// This function is used for the navigation keys
void keyboard (unsigned char key, int x, int y)
{
switch (key) {   // x,X,y,Y,z,Z uses the glRotatef() function
case 'x': // Rotates screen on x axis 
rotX -= 0.5f;
break;
case 'X': // Opposite way 
rotX += 0.5f;
break;
case 'y': // Rotates screen on y axis
rotY -= 0.5f;
break;
case 'Y': // Opposite way
rotY += 0.5f; 
break; 
case 'z': // Rotates screen on z axis
rotZ -= 0.5f;
break;
case 'Z': // Opposite way
rotZ += 0.5f;
break;
// j,J,k,K,l,L uses the gluLookAt function for navigation
case 'j':
rotLx -= 0.2f; 
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt (rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
break;
case 'J':
rotLx += 0.2f;
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt (rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
break; 
case 'k':
rotLy -= 0.2f;
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt (rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
break;
case 'K':
rotLy += 0.2f;
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt (rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
break;
case 'l': 	// It has a special case when the rotLZ becomes 
		// less than -15 the screen is viewed from the opposite side
// therefore this if statement below does not allow rotLz be less than -15
if(rotLz + 14 >= 0)
rotLz -= 0.2f;   
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();  
gluLookAt (rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0,0.0, 1.0, 0.0); 
break;
case 'L':
rotLz += 0.2f;
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt (rotLx, rotLy, 15.0 + rotLz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
break;
case 'b': // Rotates on x axis by -90 degree
rotX -= 90.0f;
break;
case 'B': // Rotates on y axis by 90 degree
rotX += 90.0f; 
break;
case 'n': // Rotates on y axis by -90 degree
rotY -= 90.0f;
break;
case 'N': // Rotates on y axis by 90 degree
rotY += 90.0f;
break;
case 'm': // Rotates on z axis by -90 degree
rotZ -= 90.0f; 
break;
case 'M': // Rotates on z axis by 90 degree
rotZ += 90.0f;
break;
case 'o': // Default, resets the translations vies from starting view
case 'O': 
X=Y=0.0f;
Z=0.0f;
rotX=0.0f;
rotY=0.0f;
rotZ=0.0f;
rotLx=0.0f;
rotLy=0.0f;
rotLz=0.0f;
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(rotLx, rotLy, 15.0f + rotLz, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);  
break;
}
glutPostRedisplay(); // Redraw the scene
}


void specialKey(int key, int x, int y) { 
switch(key){
case GLUT_KEY_LEFT: // Rotate on x axis
X -= 0.1f;
break;
case GLUT_KEY_RIGHT: // Rotate on x axis (opposite)
X += 0.1f;
break;
case GLUT_KEY_UP: // Rotate on y axis 
Y += 0.1f;
break;
case GLUT_KEY_DOWN: // Rotate on y axis (opposite)
Y -= 0.1f;
break; 
case GLUT_KEY_PAGE_UP: // Rotate on z axis
Z -= 0.1f;
break;
case GLUT_KEY_PAGE_DOWN:// Rotate on z axis (opposite)
Z += 0.1f;
break;
}
glutPostRedisplay();
}

int main(int argc,char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(WindW,WindH);
glutCreateWindow("112233"); 
init();
glutReshapeFunc(reshape); 
glutDisplayFunc(display); 
glutKeyboardFunc(keyboard);
glutSpecialFunc(specialKey);
glutMotionFunc(motion);
glutMouseFunc(mouse);
// отрисовка курсора
if(curs){glutSetCursor(GLUT_CURSOR_NONE);}
//glutFullScreen();// полноэкранный режим
//cout << glutGet(GLUT_SCREEN_WIDTH) << "\n";
glutMainLoop();
return 0;
}   
