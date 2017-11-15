void Reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(75,w/h,0.10,100.0);
	//gluPerspective(45,w/h,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,10.0,15.0,0.0,0.0,0.0,0.0,1.0,0.0);
	WindW=w;
	WindH=h;
}
