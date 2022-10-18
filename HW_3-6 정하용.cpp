/***********************************************************************/
/*                           HW#3 :  TimerCallback 함수 응용                            */
/*  작성자 : 정하용                              날짜 : 2022년 10월 7일    */
/*                                                                                                 */
/* 문제 정의 :   TimerCallback함수를 사용해 일정한 시간간격이 지나면 지정해놓은 함수를 재호출함  */
/*                - - - - - - -                                                                   */
/* 기능 :        물체가 왼쪽으로 0.1씩 이동하다가 윈도우 창을 만나면 색상을 변경하고
				 반대 방향으로 이동하는 행동을 반복한다.
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
// 물체의 x축을 관리할 변수
GLfloat Delta = 0.0;
// 물체의 색상을 관리할 변수
GLfloat color_R = 0.0;
GLfloat color_G = 0.5;
GLfloat color_B = 0.8;
// 조건문에서 사용할 변수
GLint a = 0;
void MyDisplay() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON); // polygon 형태로 물체 생성 
	glColor3f(color_R, color_G, color_B); // 변수를 통해서 색상 변경
	// 변수를 통해서 물체의 각 정점의 x축을 관리
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}
void MyTimer(int value) // 일정한 시간 간격으로 호출될 함수
{
	if (a == 0) // a가 0일 경우
	{
		Delta += 0.1; // 물체를 오른쪽으로 0.1만큼 이동
		glutPostRedisplay();
	}
	if (a == 1) // a가 1일 경우
	{
		Delta -= 0.1; // 물체를 왼쪽으로 0.1만큼 이동
		glutPostRedisplay();
	}
	if (0.0 + Delta > 1.0) // 물체가 오른쪽 윈도우 창에 닿는 경우
	{
		a = 1; // a를 1로 변경 (왼쪽으로 이동하게)
		// 색상을 붉은색으로
		color_R = 1.0;
		color_G = 0.0;
		color_B = 0.0;
		glutPostRedisplay();
	}
	if (-1.0 + Delta < -0.9) // 물체가 왼쪽 윈도우 창에 닿는경우
	{
		a = 0; // a를 0으로 변경 (오른쪽으로 이동하게)
		// 색상을 푸른색으로
		color_R = 0.0;
		color_G = 0.0;
		color_B = 1.0;
		glutPostRedisplay();
	}
	
	
	glutTimerFunc(50, MyTimer, 1); // TimerCallback 함수 호출 이 함수를 50msec 후에 호출
}

void MyInit() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Timer Callback");
		MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, MyTimer, 1); //TimerCallback 함수 호출 위 MyTimer 함수를 호출함.
	glutMainLoop();
	return 0;
}