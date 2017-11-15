#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
using namespace std;
int mouseX,mouseY;	// Координаты курсора
int WindW=500;		// Ширина окна
int WindH=500;		// Высота окна
float walkSpeed=0.1;	//Скорость ходьбы
bool move[4];	//Массив движения по сторонам
bool flyMode=false;	//Режим полета
bool jumpMode=false;	//Прыжок
float jumpSpeed=0.9;	//Скорость прыжка
float jumpSila=2;	//Сила прыжка
float massa=0.001;	//Масса игрока
float speedDown=0;	//Скорость падения (Не менять!!!)
bool runMode=false;	//Режим бега
float runSpeed=0.2;	//Скорость бега
#include "libs/functions.cpp"
#include "libs/mouse.cpp"
#include "libs/keyboard.cpp"
#include "libs/init.cpp"
#include "libs/reshape.cpp"
#include "libs/camera.cpp"
#include "libs/text.cpp"
int SC_TIMER=1000;	// Время в мили секундах
int frames,fps,framestotal;
bool curs=false;	// Наличие програмного курсора



void timer(int value){
	fps=frames;
	framestotal+=frames;
	frames=0;
	//cout << fps << "\n";
	glutTimerFunc(SC_TIMER,timer,0);
}



void display(){
	glLoadIdentity();
	glClearColor(0.5,0.5,0.5,0.5);
	Control(0.2,0.2,mousecam);	//вычисление позиции и поворота камеры
	UpdateCamera();	//перемещение камеры в новое место
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	drawGround();
	glShadeModel(GL_SMOOTH);
	glLineWidth(2);
	glColor3ub(255,252,0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(WindW,0,0);
	glColor3ub(255,159,0);
	glVertex3f(0,0,0);
	glVertex3f(0,WindH,0);
	glColor3ub(51,166,0);
	glVertex3f(0,0,0);
	glVertex3f(0,0,400);
	glEnd();
	glLineWidth(3);
	glColor3f(0.0, 0.6, 0.9);
	glutWireCube(10.0);
	glFlush();

//glShadeModel(GL_SMOOTH);
glLineWidth(1);
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
	printText("X",10,0.1,0,255,255,255);
	printText("Y",0.1,10,0,255,255,255);
	printText("Z",0.1,0,10,255,255,255);
	//char* buf;
	//sprintf(buf,"FPS: %i F: %i",fps,framestotal);
	//cout << buf << "\n";
	//$buf=sprintf "FPS: %i F: %2d",$fps,$frametotal;
	//string buf=sprintf("FPS: %i F: %i",fps,framestotal);
	//char* buf;
	//printf("FPS: %i F: %i",fps,framestotal);
	//ScreenText(toString(buf),10,20,255,159,0,1,50,50,50,170,12);
	//ScreenText("FLY mode: $fly",10,32,255,159,0,1,50,50,50,170,12);
	//ScreenText("RUN mode: $run",10,44,255,159,0,1,50,50,50,170,12);
	//ScreenText("JUMP mode: $jump",10,56,255,159,0,1,50,50,50,170,12);
	//ScreenText("speedDown: ",10,68,255,159,0,1,50,50,50,170,12);
	//$buf=sprintf "POS: [%i,%i,%i]",$camX,$camY,$camZ;
	//ScreenText($buf,10,80,255,159,0,1,50,50,50,170,12);
	glutSwapBuffers();
	if(!flyMode){
		if(camY>1){
			speedDown+=massa*9.8;
			camY-=speedDown;
			if(jumpMode and camY<(camY+jumpSila)){
				camY+=jumpSpeed-speedDown;
			}
			if(camY<1){camY=1;jumpMode=false;}
		}else{
			camY=1;
			speedDown=0;
			if(jumpMode){
				camY+=jumpSpeed;
			}
		}
	}else{
		jumpMode=false;
	}
	if(move[0]){
		if(camPitch!=90 and camPitch!=-90){
			if(runMode){
				moveCamera(walkSpeed+runSpeed,0.0);
				moveCameraUp(walkSpeed+runSpeed,0.0);
			}else{
				moveCamera(walkSpeed,0.0);	//Идем вперед
				moveCameraUp(walkSpeed,0.0);	//Двигаемся вверх/вниз
			}
		}
	}
	if(move[1]){
		if(camPitch!=90 and camPitch!=-90){
			moveCamera(walkSpeed,180.0);	//Идем назад
			moveCameraUp(walkSpeed,180.0);	//Двигаемся вверх/вниз
		}
	}
	if(move[3]){moveCamera(walkSpeed,270);}
	if(move[2]){moveCamera(walkSpeed,90);}
	//FPS
	frames++;
}
void Idle(){
//	if($menu){display();}
//	glRotatef($r,$rotLx,$rotLy,$rotLz);
	glutPostRedisplay();
}
int main(int argc, char **argv) {
glutInit(&argc,argv); ///инициализируем glut
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowSize(WindW,WindH);
glutInitWindowPosition(100,100);
glutCreateWindow("start");
init();
glutDisplayFunc(display);
glutTimerFunc(SC_TIMER,timer,0);
glutReshapeFunc(Reshape);
glutKeyboardFunc(Keyboard);
glutKeyboardUpFunc(KeyboardUP);
glutSpecialFunc(KeyboardSpec);
glutSpecialUpFunc(KeyboardSpecUp);
glutPassiveMotionFunc(PassiveMotion);
glutIdleFunc(Idle);	// простой
// отрисовка курсора
if(curs){glutSetCursor(GLUT_CURSOR_NONE);}

//glutFullScreen();// полноэкранный режим
//cout << glutGet(GLUT_SCREEN_WIDTH) << "\n";
glutMainLoop();
return 0;
}
