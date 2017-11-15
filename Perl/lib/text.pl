#!/usr/bin/perl
#FONTS
	#GLUT_BITMAP_8_BY_13
	#GLUT_BITMAP_9_BY_15
	#GLUT_BITMAP_TIMES_ROMAN_10
	#GLUT_BITMAP_TIMES_ROMAN_24
	#GLUT_BITMAP_HELVETICA_10
	#GLUT_BITMAP_HELVETICA_12
	#GLUT_BITMAP_HELVETICA_18
sub setText{
	($str,$x,$y,$z,$tr,$tg,$tb)=@_;
	glColor3ub($tr,$tg,$tb);
	glRasterPos3i($x,$y,$z);
	@tmp=split '',$str;
	for(@tmp){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ord $_);
	}
}
sub ScreenText{
	($text,$x,$y,$tr,$tg,$tb,$fon,$fonr,$fong,$fonb,$fonw,$fonh)=@_;
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0,$WinW,$WinH,0,0,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_DEPTH_TEST);
	if($fon){
		glColor3ub($fonr,$fong,$fonb);
		glBegin(GL_QUADS);
			glVertex3f($x,$y-11,0.0);
			glVertex3f($x,$y+$fonh-11,0.0);
			glVertex3f($x+$fonw,$y+$fonh-11,0.0);
			glVertex3f($x+$fonw,$y-11,0.0);
		glEnd();
	}
	###
	glColor3ub($tr,$tg,$tb);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
#	glTranslatef($x,$y,-1);
	glRasterPos2i($x,$y);
#	glTexCoord3f(0.0,text.0,1);
	@tmp=split '',$text;
	for(@tmp){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,ord $_);
	}
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();
	###
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
return 1;
