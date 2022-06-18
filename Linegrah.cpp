// roll no 04071713030
// umar basharat
 
 #include <gl/Gl.h>
 #include <gl/glut.h>
 #include<math.h>
 
 const int screenWidth = 640; // width of the screen window in pixels
 const int screenHeight =480; // height of the screen window in pixels
 GLdouble A, B, C, D; // scaling and shifting coefficients

void myInit(void) {
glClearColor(1.0, 1.0, 1.0, 0.0); // background color is set to white
glColor3f(1.0, 0.0, 0.0); // drawing color is set to black
glPointSize(2.0); // a dot is 2 by 2 pixels
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenWidth);
A = screenWidth / 4.0;
B = 0.0;
C = D = screenHeight / 2.0;
}


void myDisplay(void) {
glClear(GL_COLOR_BUFFER_BIT); // clear the screen
glBegin(GL_LINE_STRIP); // draw the points
for (GLdouble x=0; x<4.0; x += 0.005) {
// GLdouble func = tan(2*3.1416*x/100) + 30*tan(4*3.1416*x/100) + 6*tan(6*3.1416*x/100);
GLdouble func = exp(-x)*cos(2*3.14159265*x);
glVertex2d( A*x + B, C*func + D ); }
glEnd(); 
glFlush();
}

int main(int argc, char **argv) {
glutInit(&argc, argv); // initialize the toolkit
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
glutInitWindowSize(screenWidth, screenHeight); // set window size
glutInitWindowPosition(100, 150); // set window position on screen
glutCreateWindow("Dot Plot of a Function");
glutDisplayFunc(myDisplay); // register display function
myInit();
glutMainLoop();
}
