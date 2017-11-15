#!/usr/bin/perl
sub nextPos{
	($dist,$dir,$px,$py,$pz)=@_;
	$rad=($camYaw+$dir)*$pi/180.0;
	$px-=sin($rad)*$dist;
	$pz-=cos($rad)*$dist;
	$rad=($camPitch+$dir)*$pi/180.0;
	$py+=sin($rad)*$dist;   
	$rad=$dist=$dir=undef;
	return (int $px,int $py,int $pz);
}
sub getPos{
	($px,$py,$pz)=@_;
	@tmp=(int $px,int $py,int $pz);
	if($px>0){$tmp[0]++;}
	if($px<0){$tmp[0]--;}
	if($py>0){$tmp[1]++;}
	if($py<0){$tmp[1]--;}
	if($pz>0){$tmp[2]++;}
	if($pz<0){$tmp[2]--;}
	return @tmp;
}
sub drawGround{
	$fex=20;
	$step=1;
	$dy=0;
	glLineWidth(1);
	glColor3f(0.108,0.108,0.108);
	glBegin(GL_LINES);
	for($iLine=-$fex;$iLine<=$fex;$iLine+=$step){
		glVertex3f($iLine,$dy,$fex);
		glVertex3f($iLine,$dy,-$fex);
		glVertex3f($fex,$dy,$iLine);
		glVertex3f(-$fex,$dy,$iLine);
	}
	glEnd();
}
sub drawCube{
	($x,$y,$z,$size,$r,$g,$b,$id)=@_;
	@build{"$x:$y:$z"}=1;
	if($id){
		eval "\$texture=\$tex$id;";
		eval "\$p1=\$ifmt$id;";
		eval "\$p2=\$fmt$id;";
		eval "\$p3=\$type$id;";
		eval "\$p4=\$texw$id;";
		eval "\$p5=\$texh$id;";
		glTexImage2D_c(GL_TEXTURE_2D,0,$p1,$p4,$p5,0,$p2,$p3,$texture->Ptr());
		$texture=$p1=$p2=$p3=$p4=$p5=undef;
	}
	glLineWidth(5);
	glColor3ub($r,$g,$b);
	glBegin(GL_QUADS);
		glTexCoord2f(1,1);glVertex3f($x,$y+$size,$z);
		glTexCoord2f(0,1);glVertex3f($x+$size,$y+$size,$z);
		glTexCoord2f(0,0);glVertex3f($x+$size,$y,$z);
		glTexCoord2f(1,0);glVertex3f($x,$y,$z);
		glTexCoord2f(1,1);glVertex3f($x,$y,$z+$size);
		glTexCoord2f(1,0);glVertex3f($x+$size,$y,$z+$size);
		glTexCoord2f(0,0);glVertex3f($x+$size,$y,$z);
		glTexCoord2f(0,1);glVertex3f($x,$y,$z);
		glTexCoord2f(1,0);glVertex3f($x,$y,$z+$size);
		glTexCoord2f(1,1);glVertex3f($x,$y+$size,$z+$size);
		glTexCoord2f(0,1);glVertex3f($x,$y+$size,$z);
		glTexCoord2f(0,0);glVertex3f($x,$y,$z);
		glTexCoord2f(0,0);glVertex3f($x+$size,$y,$z+$size);
		glTexCoord2f(0,1);glVertex3f($x+$size,$y+$size,$z+$size);
		glTexCoord2f(1,1);glVertex3f($x+$size,$y+$size,$z);
		glTexCoord2f(1,0);glVertex3f($x+$size,$y,$z);
		glTexCoord2f(1,0);glVertex3f($x,$y+$size,$z+$size);
		glTexCoord2f(1,1);glVertex3f($x+$size,$y+$size,$z+$size);
		glTexCoord2f(0,1);glVertex3f($x+$size,$y+$size,$z);
		glTexCoord2f(0,0);glVertex3f($x,$y+$size,$z);
		glTexCoord2f(0,1);glVertex3f($x,$y+$size,$z+$size);
		glTexCoord2f(1,1);glVertex3f($x+$size,$y+$size,$z+$size);
		glTexCoord2f(1,0);glVertex3f($x+$size,$y,$z+$size);
		glTexCoord2f(0,0);glVertex3f($x,$y,$z+$size);
	glEnd();
#	glFlush();
}
return 1;
