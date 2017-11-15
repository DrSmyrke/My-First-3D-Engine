#!/usr/bin/perl
sub init{
	glClearColor(0.5,0.5,0.5,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,$WinW/$WinH,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	#load textures
	glEnable(GL_TEXTURE_2D);
	open fs,"<$dir/textures/index.list";
	@textures=<fs>;
	close fs;
	chomp @textures;
	$i=0;
	foreach $str(@textures){
		($id,$fname)=split("	",$str);
		eval "\$tex$id=new OpenGL::Image(source=>'$dir/textures/$fname');";
		# Get GL info
		eval "(\$ifmt$id,\$fmt$id,\$type$id)=\$tex$id->Get('gl_internalformat','gl_format','gl_type');";
		eval "(\$texw$id,\$texh$id)=\$tex$id->Get('width','height');";
		$i++;
	}
	$texid=glGenTextures_p($i);
	glBindTexture(GL_TEXTURE_2D,$texid);
	#glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	loadRegion();
#	glEnable(GL_LIGHTING);
#	glEnable(GL_LIGHT0);
#	@col=(1.0,1.0,1.0,1.0);
#	glLightfv(GL_LIGHT0,GL_DIFFUSE,@col);
	###
	glEnable(GL_DEPTH_TEST);
#	glDepthMask(GL_TRUE);
#	glDepthFunc(GL_LEQUAL);
#	glShadeModel(GL_FLAT);
#	glEnable(GL_LIGHTING);
#	glEnable(GL_LIGHT0);
#	glEnable(GL_LINE_SMOOTH);
#	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
#	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
#	glutSetCursor(GLUT_CURSOR_NONE);
	#_textureId = loadTexture(image);
#	delete $image;
}
sub loadRegion{
	$name="test.world";
	open fs,"<$dir/test_world/$name";@region=<fs>;close fs;chomp @region;
}
return 1;
