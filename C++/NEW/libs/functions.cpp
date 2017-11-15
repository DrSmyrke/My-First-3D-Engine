// отрисовка земли
void drawGround(){float fex=20,step=1,y=-0.4;int iLine;glLineWidth(1);glColor3f(0.108,0.108,0.108);glBegin(GL_LINES);for(iLine=-fex;iLine<=fex;iLine+=step){glVertex3f(iLine,y,fex);glVertex3f(iLine,y,-fex);glVertex3f(fex,y,iLine);glVertex3f(-fex,y,iLine);}glEnd();}
void drawrels(){
float fex=20,step=1,y=-0.4;int iLine;
glLineWidth(3);glColor3f(0.68,0.68,0.68);glBegin(GL_LINES);for(iLine=-fex;iLine<=fex;iLine+=step){glVertex3f(iLine,y,fex);glVertex3f(iLine,y,-fex);glVertex3f(fex,y,iLine);glVertex3f(-fex,y,iLine);}glEnd();
}
