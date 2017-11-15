#!/usr/bin/perl
sub KeyboardSpecUp{
	$key=shift @_;
#	print "KEY: [$key]\n";
	if($key==112){$run=0;}	#SHIFT
}
sub KeyboardSpec{
	$key=shift @_;
#	print "KEY: [$key]\n";
	if($key==112){$run=1;}	#SHIFT
}
sub KeyboardUp{
	$key=shift @_;
#	print "KEY: [$key]\n";
	if($key==119){$move[0]=0;}	#W
	if($key==115){$move[1]=0;}	#S
	if($key==100){$move[2]=0;}	#D
	if($key==97){$move[3]=0;}	#A
}
sub Keyboard{
	$key=shift @_;
#	print "KEY: [$key]\n";
	$rotLx=0;$rotLy=0;$rotLz=0.0;$angle=2;$r=0;
	if($key==27){$mousecam=($mousecam)?0:1;}	#ESCAPE
	if($key==96){$fly=($fly)?0:1;}	#TILDA
	if($key==32){$jump=($jump)?0:1;}	#SPACE
	if($key==49){print "KEY 1 none\n";}	#1
	if($key==9){exit 0;}	#TAB
	if($key==119){$move[0]=1;}	#W
	if($key==115){$move[1]=1;}	#S
	if($key==100){$move[2]=1;}	#D
	if($key==97){$move[3]=1;}	#A
	if($key==113){
		$r=$angle;
		$rotLx=0.2;
	}
	if($key==101){
		$r=0-$angle;
		$rotLx=0.2;
	}

	glRotatef($r,$rotLx,$rotLy,$rotLz);
}
return 1;
