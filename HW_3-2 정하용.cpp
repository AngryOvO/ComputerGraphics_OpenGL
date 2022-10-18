/***********************************************************************/
/*                           HW#3 : Keyboard Callback 2                                   */
/*  작성자 : 정하용                              날짜 : 2022년 10월 7일    */
/*                                                                                                 */
/* 문제 정의 :   Keyboard callback 함수를 이용해 특정 키를 입력해 물체를 이동 또는 색상을 변환한다.*/
/*                - - - - - - -                                                                   */
/* 기능 :        q : 종료
				 왼쪽 방향키 : 왼쪽으로 0.1만큼 이동
				 오른쪽 방향키 : 오른쪽으로 0.1 만큼 이동
				 아래쪽 방향키 : 아래쪽으로 0.1 만큼 이동
				 위쪽 방향키 : 위쪽으로 0.1만큼 이동
				 page up : 도형의 각 정점을 0.1 씩 확대
				 page down : 도형의 각 정점을 0.1 씩 축소
				 주의사항 : 도형은 윈도우창 안에서만 이동할 수 있음
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>

// 각정점에 대한 변수 생성
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5); // 색상은 회색
	glBegin(GL_POLYGON); // polygon 형태로 생성
	// 이번엔 모든 정점을 각기 다른 변수를 통해서 관리
	glVertex3f(v1_x, v1_y, 0.0);
	glVertex3f(v2_x, v2_y, 0.0);
	glVertex3f(v3_x, v3_y, 0.0);
	glVertex3f(v4_x, v4_y, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) //keyboardCallbak 호출시 실행되는 함수
{
	switch (key)
	{
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) // 특수키들에 대한 KeyboardCallback 함수 호출시 실행되는 함수
{
	switch (key)
	{
	case GLUT_KEY_UP: // 방향키 위쪽
		if (v3_y <= 1.0 && v4_y <= 1.0) // y좌표가 1.0을 넘지 않는 경우에만 실행
		{
			// 모든 y 좌표를 0.1씩 증가
			v1_y += 0.1;
			v2_y += 0.1;
			v3_y += 0.1;
			v4_y += 0.1;
		}
		glutPostRedisplay(); // 변경된 내용으로 화면 재출력
		break;
	case GLUT_KEY_DOWN: // 방향키 아래쪽
		if (v1_y >= -1.0 && v2_y >= -1.0) // y좌표가 -1.0을 넘지 않는 경우에만 실행
		{
			// 모든 y 좌표를 -0.1씩 증가
			v1_y -= 0.1;
			v2_y -= 0.1;
			v3_y -= 0.1;
			v4_y -= 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT: // 방향키 왼쪽
		if (v1_x >= -1.0 && v4_x >= -1.0) // x좌표가 -1.0을 넘지 않는 경우에만 실행
		{
			// 모든 x 좌표를 -0.1씩 증가
			v1_x -= 0.1;
			v2_x -= 0.1;
			v3_x -= 0.1;
			v4_x -= 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT: // 방향키 오른쪽
		if (v2_x <= 1.0 && v3_x <= 1.0) // x좌표가 1.0을 넘지 않는 경우에만 실행
		{
			// 모든 x 좌표를 0.1씩 증가
			v1_x += 0.1;
			v2_x += 0.1;
			v3_x += 0.1;
			v4_x += 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP: // page up 키를 눌렀을 경우
		if (v1_x >= -1.0 && v1_y >= -1.0 && v2_x <= 1.0 && v2_y >= -1.0 && v3_x <= 1.0 && v3_y <= 1.0 && v4_x >= -1.0 && v4_y <= 1.0) // 각 좌표가 윈도우창을 넘지 않는 선에서
		{
			// 각 좌표값을 방향에 맞게 증가
			v1_x -= 0.1;
			v1_y -= 0.1;
			v2_x += 0.1;
			v2_y -= 0.1;
			v3_x += 0.1;
			v3_y += 0.1;
			v4_x -= 0.1;
			v4_y += 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN: // page down 키를 눌렀을 경우
		if ((v2_x - v1_x  ) >= 0.3) // 도형의 최소한의 크기를 유지하는 선에서
		{
			// 각 좌표값을 방향에 맞게 감소
			v1_x += 0.1;
			v1_y += 0.1;
			v2_x -= 0.1;
			v2_y += 0.1;
			v3_x -= 0.1;
			v3_y -= 0.1;
			v4_x += 0.1;
			v4_y -= 0.1;
		}
		
		glutPostRedisplay();
		break;
	default:
		break;
	}
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
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}
