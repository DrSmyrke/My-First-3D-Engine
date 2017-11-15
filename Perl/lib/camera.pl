#!/usr/bin/perl
$angle=0.0;
$camX=0.0;$camY=30.0;$camZ=0.0;	#current position of the camera
$camYaw=0.0;	#camera rotation in Y axis
$camPitch=0.0;	#camera rotation in X axis
sub lockCamera{
	#набор campitch в диапазоне от -90 до 90, а набор camyaw между 0 и 360 градусов
	if($camPitch>90){$camPitch=90;}
	if($camPitch<-90){$camPitch=-90;}
	if($camYaw<0.0){$camYaw+=360.0;}
	if($camYaw>360.0){$camYaw-=360;}
}
sub moveCamera{
	($dist,$dir)=@_;
	$rad=($camYaw+$dir)*$pi/180.0;	#преобразование из градусов в радианы
	$camX-=sin($rad)*$dist;	#calculate the new coorinate, if you don't understand, draw a right triangle with the datas, you have
	$camZ-=cos($rad)*$dist;	#and try to calculate the new coorinate with trigonometric functions, that should help
}
sub moveCameraUp{
	($dist,$dir)=@_;
	#the the same, only this time we calculate the y coorinate
	$rad=($camPitch+$dir)*$pi/180.0;
	$camY+=sin($rad)*$dist;   
}
sub UpdateCamera{
	glTranslatef(-$camX,-$camY,-$camZ);	#move the camera
}
sub Control{
	($movevel,$mousevel,$mi)=@_;	#move and mouse sensitivity, and is the mouse inside the window?
	if($mi){	#if the mouse is in the screen
		$MidX=$WinW/2;	#middle of the screen
		$MidY=$WinH/2;
#		SDL_ShowCursor(SDL_DISABLE);    //we don't show the cursor
		$tmpx=$mx;$tmpy=$my;
#		SDL_GetMouseState(&tmpx,&tmpy); //get the current position of the cursor
		$camYaw+=$mousevel*($MidX-$tmpx);
		#get the rotation, for example, if the mouse current position is 315, than 5*0.2, this is for Y
		$camPitch+=$mousevel*($MidY-$tmpy);	#this is for X
		lockCamera();
		glutWarpPointer($MidX,$MidY);
	}
	glRotatef(-$camPitch,1.0,0.0,0.0);
	#rotate the camera (more precisly move everything in the opposit direction)
	glRotatef(-$camYaw,0.0,1.0,0.0);
}
return 1;
