bool mousecam=true;
//float angle=0.0;	//угол поворота
float camX=0.0;	//Текущее положение камеры
float camY=0.0;	//Текущее положение камеры
float camZ=5.0;	//Текущее положение камеры
float camYaw=0.0;	//поворот камеры вокруг Y
float camPitch=0.0;	//поворот камеры вокруг X
float pi=3.1415926535;
void lockCamera(){
	//набор campitch в диапазоне от -90 до 90, а набор camyaw между 0 и 360 градусов
	if(camPitch>90){camPitch=90;}
	if(camPitch<-90){camPitch=-90;}
	if(camYaw<0.0){camYaw+=360.0;}
	if(camYaw>360.0){camYaw-=360;}
}
void moveCamera(float dist,float dir){
	float rad=(camYaw+dir)*pi/180.0;	//преобразование из градусов в радианы
	camX-=sin(rad)*dist;	//Вычисление новых координат
	camZ-=cos(rad)*dist;
}
void moveCameraUp(float dist,float dir){
	//the the same, only this time we calculate the y coorinate
	float rad=(camPitch+dir)*pi/180.0;
	camY+=sin(rad)*dist;   
}
void UpdateCamera(){
	glTranslatef(-camX,-camY,-camZ);	//движение камеры
}
void Control(float movevel,float mousevel, bool mi){
	//move and mouse sensitivity, and is the mouse inside the window?
	if(mi){
		float MidX=WindW/2;	//Центр окна
		float MidY=WindH/2;
		//SDL_ShowCursor(SDL_DISABLE);    //we don't show the cursor
		camYaw+=mousevel*(MidX-mouseX);
		//получаем вращение, например, если мышь текущее положение 315, чем в 5*0,2, то это для Y
		camPitch+=mousevel*(MidY-mouseY);	//это для X
		lockCamera();
		glutWarpPointer(MidX,MidY);
	}
	glRotatef(-camPitch,1.0,0.0,0.0);
	//поворот камеры
	glRotatef(-camYaw,0.0,1.0,0.0);
}
