void Keyboard(unsigned char key, int x, int y){
	#define ESCAPE '\033'
	if(key==ESCAPE){exit(0);}
	switch(key){
		case '`':
			flyMode=(flyMode)?false:true;
			break;
		case ' ':
			jumpMode=true;
			break;
		case 'w':
			move[0]=true;
			break;
		case 's':
			move[1]=true;
			break;
		case 'a':
			move[2]=true;
			break;
		case 'd':
			move[3]=true;
			break;
	}
	//cout << key << "\n";
}
void KeyboardUP(unsigned char key, int x, int y){
	switch(key){
//		case '`':
//			flyMode=false;
//			break;
		case 'w':
			move[0]=false;
			break;
		case 's':
			move[1]=false;
			break;
		case 'a':
			move[2]=false;
			break;
		case 'd':
			move[3]=false;
			break;
	}
	//cout << key << "\n";
}
void KeyboardSpec(int key, int x, int y){
	switch(key){
		case 112:
			runMode=true;
			break;
	}
	//cout << key << "\n";
}
void KeyboardSpecUp(int key, int x, int y){
	switch(key){
		case 112:
			runMode=false;
			break;
	}
	//cout << key << "\n";
}
