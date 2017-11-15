#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;
int WindW=500;		// Ширина окна
int WindH=500;		// Высота окна
int SC_TIMER=100;	// Время обновления экрана в мили секундах
bool curs=false;	// Наличие програмного курсора
int mouseX,mouseY;	// Координаты курсора
float mAng=0;		// Угол поворота камеры
float fConst=2;		// Коэффицент скорости поворота камеры
float pi=3.14;		// Пи
float speedCam=0.1;	// Скорость вращения камеры

float relsx=(0,20,40,70);
float relsy=(0,40,-30,70);

float plx=0;
float ply=0;
float plz=0;
float rotLx=0.0f;float rotLy=0.0f;float rotLz=0.0f;

int Bmouse=1;
int Mstate=1;
int vagonW=200;
int vagonH=60;
int vagonD=60;

//if(w<=h){glOrtho(-nRange,nRange,-nRange*h/w,nRange*h/w,-nRange,nRange);}else{glOrtho(-nRange,nRange,-nRange*w/h,nRange*w/h,-nRange,nRange);}

void timf(int value){glutPostRedisplay();glutTimerFunc(SC_TIMER,timf,0);}
// Процедура отображения
void Reshape(int w,int h){
glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity(); 
gluPerspective(75,(GLfloat)w/(GLfloat)h,0.10,100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(0.0,10.0,15.0,0.0,0.0,0.0,0.0,1.0,0.0);
WindW=w;
WindH=h;
}
void motion(int x,int y){
float r;

//if(y<WindH/2){r=y/(WindH/180);}
//if(y>WindH/2){r=0-(((WindH/2)+y)/(WindH/180));}
//rotLx=0.2f;
cout << r << "\n";

//if(x>WindW/2){mAng=-fConst;}else{mAng=fConst;}
//считаем изменение координат курсора, относительно старых
//int deltaX=x-mouseX;
//int deltaY=y-mouseY;
//запоминаем текущие координаты
//mouseX=x;mouseY=y;
//изменяем широту и долготу
//float longitude=longitude+deltaX*speedCam; //долгота, фи
//float latitude=latitude+deltaY*speedCam; 	//широта, тэта
//ограничиваем широту(тэта)
//if(latitude>pi/2) latitude = pi/2;
//if(latitude<-pi/2) latitude = -pi/2;
//считаем x,y,z
//rotLx = sin(latitude)*cos(longitude);
//rotLy = sin(latitude)*sin(longitude);
//rotLz = cos(latitude);
//glMatrixMode(GL_MODELVIEW);
//glLoadIdentity();
//gluLookAt(plx,ply,plz,rotLx,rotLy,rotLz,0,1,0);

//glRotatef(r,rotLx,rotLy,rotLz);

mouseX=x;mouseY=y;
//if(x<WindW/2){vang=0.1;}
//if(x>WindW/2){vang=-0.1;}
//cout << x << "\n";
//cout << y << "\n";
}
void mouse(int button,int state,int x,int y){
//mouseX=x;mouseY=y;
//if(button==0 and state==0){plz--;}
//if(button==2 and state==0){plz++;}
//Bmouse=button;
//Mstate=state;
//cout << button << "\n";
}

// отрисовка земли
void drawGround(){float fex=20,step=1,y=-0.4;int iLine;glLineWidth(1);glColor3f(0.108,0.108,0.108);glBegin(GL_LINES);for(iLine=-fex;iLine<=fex;iLine+=step){glVertex3f(iLine,y,fex);glVertex3f(iLine,y,-fex);glVertex3f(fex,y,iLine);glVertex3f(-fex,y,iLine);}glEnd();}
void drawrels(){
float fex=20,step=1,y=-0.4;int iLine;
glLineWidth(3);glColor3f(0.68,0.68,0.68);glBegin(GL_LINES);for(iLine=-fex;iLine<=fex;iLine+=step){glVertex3f(iLine,y,fex);glVertex3f(iLine,y,-fex);glVertex3f(fex,y,iLine);glVertex3f(-fex,y,iLine);}glEnd();
}

// Инициализация OpenGL
void init(void){
glClearColor(0.0, 0.0, 0.0, 0.0);
//glShadeModel(GL_FLAT);
//glEnable(GL_LINE_SMOOTH);
glHint(GL_LINE_SMOOTH_HINT,GL_NICEST); // Установка сглаживания линний
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


drawGround();
drawrels();

//glShadeModel(GL_SMOOTH);
glLineWidth(2);
glColor3ub(138,138,138);
glBegin(GL_LINES);
glVertex3f(0,0,0);
glVertex3f(WindW,0,0);
glVertex3f(0,0,0);
glVertex3f(0,WindH,0);
glVertex3f(0,0,0);
glVertex3f(0,0,400);
glEnd();
glLineWidth(3);
glColor3f(0.0f, 0.6f, 0.9f);

glutWireCube(10.0);




glFlush();
glutSwapBuffers();
}
void Keyboard(unsigned char key, int x, int y){
#define ESCAPE '\033'
if(key==ESCAPE){exit(0);}
switch(key){
case 'w':
plz++;
break;
case 's':
plz--;
break;
case 'a':
plx++;
break;
case 'd':
plx--;
break;
}

//cout << key << "\n";
}

int main(int argc, char **argv) {
glutInit(&argc,argv); ///инициализируем glut
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowSize(WindW,WindH);
glutInitWindowPosition(100,100);
glutCreateWindow("start");
init();
glutDisplayFunc(display);
glutTimerFunc(SC_TIMER,timf,0);
glutReshapeFunc(Reshape);
glutKeyboardFunc(Keyboard);
glutMouseFunc(mouse);
glutMotionFunc(motion);
glutPassiveMotionFunc(motion);
// отрисовка курсора
if(curs){glutSetCursor(GLUT_CURSOR_NONE);}

//glutFullScreen();// полноэкранный режим
cout << glutGet(GLUT_SCREEN_WIDTH) << "\n";
glutMainLoop();
return 0;
}
