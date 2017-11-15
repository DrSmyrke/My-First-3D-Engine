#!/usr/bin/perl
sub Reshape{
	($WinW,$WinH)=@_;
	glViewport(0,0,$WinW,$WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	#gluPerspective(75,$WinW/$WinH,0.10,100.0);
	gluPerspective(45.0,$WinW/$WinH,0.1,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}
return 1;
