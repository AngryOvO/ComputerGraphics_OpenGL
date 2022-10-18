/***********************************************************************/
/*                           HW#3 : Mouse Callback 응용                                 */
/*  작성자 : 정하용                              날짜 : 2022년 10월 7일    */
/*                                                                                                 */
/* 문제 정의 :   Mouse callback 함수를 이용해 특정 키를 입력해 물체를 이동 또는 색상을 변환한다.*/
/*                - - - - - - -                                                                   */
/* 기능 :        마우스 왼쪽 버튼 : 물체가 오른쪽으로 0.1씩 연속적으로 이동
				 마우스 오른쪽 버튼 : 이동하고 있는 물체가 멈춤
				 조건 : 정점의 위치가 어디에있든지 상관없이 구동
						윈도우창을 벗어나면 안됨
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
#include <windows.h>

// 물체의 촤표를 결정할 변수 선언 및 초기화
GLfloat v1_x = -0.5;
GLfloat v1_y = -0.5;
GLfloat v2_x = 0.5;
GLfloat v2_y = -0.5;
GLfloat v3_x = 0.5;
GLfloat v3_y = 0.5;
GLfloat v4_x = -0.5;
GLfloat v4_y = 0.5;

void MyInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영 행렬로 변경
	glLoadIdentity(); // 항등행렬로 초기화
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); // polygon 형태로 도형 생성
	// 각 정점은 변수를 통해서 관리함.
	glVertex3f(v1_x, v1_y, 0.0);
	glVertex3f(v2_x, v2_y, 0.0);
	glVertex3f(v3_x, v3_y, 0.0);
	glVertex3f(v4_x, v4_y, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) //KeyboardCallback 함수
{
	switch (key) // q를 입력시 종료
	{
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}

void Mouseclick_idle() // IdleCallback 함수 호출시 실행되는 함수
{
	if (v2_x <= 1.0 && v3_x <= 1.0) // 윈도우창을 넘기지 않는 범위 하에
	{
		// x좌표 0.1씩 증가
		v1_x += 0.1;
		v2_x += 0.1;
		v3_x += 0.1;
		v4_x += 0.1;
		Sleep(350); // 350ms 초동안 딜레이.
	}
	glutPostRedisplay();
}

void MyMouse(GLint Button, GLint State , GLint X, GLint Y) //MouseCallback 함수 호출시 실행되는 함수
{
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) glutIdleFunc(Mouseclick_idle); 
	//왼쪽 버튼 클릭시 Idle Callback 함수 실행
	if ((Button == GLUT_RIGHT_BUTTON) && (State == GLUT_DOWN)) glutIdleFunc(NULL); 
	//오른쪽 버튼 클릭시 Idle Callback 함수 인자값 NULL을 받아서 실행
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	
	glutMouseFunc(MyMouse);
	glutMainLoop();
	return 0;
}
