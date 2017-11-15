// Инициализация OpenGL
void init(void){
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glShadeModel(GL_FLAT);
	//glEnable(GL_LINE_SMOOTH);
	//glHint(GL_LINE_SMOOTH_HINT,GL_NICEST); // Установка сглаживания линний
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//glClearColor(0.5,0.5,0.5,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,WindW/WindH,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}
