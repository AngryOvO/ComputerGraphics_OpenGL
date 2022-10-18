/***********************************************************************/
/*                           HW#3 : IDLE Callback 응용                                 */
/*  작성자 : 정하용                              날짜 : 2022년 10월 7일    */
/*                                                                                                 */
/* 문제 정의 :   IDLE callback 함수를 활용해 그래픽 기본 요소를  계속 생성한다  */
/*                - - - - - - -                                                                   */
/* 기능 :        실습과제 3-2 와 비슷하게 키보드의 방향키를 눌렀을 때 방향키에 맞게 
				 물체가 이동한다. 하지만 3-2에서와는 다르게 방향키를 한번 누르면
			     윈도우창 끝에 닿기 전까지 연속적으로 이동한다.
				 이는 IdleCallback함수와 더블버퍼링을 활용해 애니메이션을 생성한다.
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
#include <Windows.h>

// 각 정점의 좌표를 나타낼 변수 선언 및 초기화
GLfloat v1_x = -0.5;
GLfloat v1_y = -0.5;
GLfloat v2_x = 0.5;
GLfloat v2_y = -0.5;
GLfloat v3_x = 0.5;
GLfloat v3_y = 0.5;
GLfloat v4_x = -0.5;
GLfloat v4_y = 0.5;

void MyDisplay() 
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON);// polygon 형태로 물체 생성
	glColor3f(0.0, 0.5, 0.8);// 물체 색상 설정
	// 도형의 각 정점은 변수를 통해서 관리
	glVertex3f(v1_x, v1_y, 0.0);
	glVertex3f(v2_x, v2_y, 0.0);
	glVertex3f(v3_x, v3_y, 0.0);
	glVertex3f(v4_x, v4_y, 0.0);
	glEnd();
	glutSwapBuffers(); // 더블 버퍼링을 사용하기 위해 glflush를 사용하지 않고 swapbuffers 사용
}
void MyIdle_up()  // 위쪽 방향키를 눌렀을 경우
{
	if (v3_y <= 1.0 && v4_y <= 1.0) // 윈도우 창에 닿기 전이면
	{
		// y축 방향으로 0.1 만큼 증가
		v1_y += 0.1;
		v2_y += 0.1;
		v3_y += 0.1;
		v4_y += 0.1;
		Sleep(50); // 일정한 딜레이를 줌
	}
	glutPostRedisplay(); // 변경된 물체를 화면에 재출력
}

void MyIdle_down() //아래쪽 방향키를 눌렀을 때
{
	if (v1_y >= -1.0 && v2_y >= -1.0) // 윈도우 창에 닿기 전까지
	{
		// y축 방향으로 -0.1 만큼 증가
		v1_y -= 0.1;
		v2_y -= 0.1;
		v3_y -= 0.1;
		v4_y -= 0.1;
		Sleep(50); // 딜레이
	}
	glutPostRedisplay();
}

void MyIdle_left() // 왼쪽 방향키를 눌렀을 경우
{
	if (v1_x >= -1.0 && v4_x >= -1.0) // 윈도우 창에 닿기 전까지
	{
		// x축 방향으로 -0.1만큼 증가
		v1_x -= 0.1;
		v2_x -= 0.1;
		v3_x -= 0.1;
		v4_x -= 0.1;
		Sleep(50); // 딜레이
	}
	glutPostRedisplay();
}

void MyIdle_right() // 오른쪽 방향키를 눌렀을 경우
{
	if (v2_x <= 1.0 && v3_x <= 1.0) // 윈도우 창에 닿기 전까지
	{
		// x축 방향으로 0.1만큼 증가
		v1_x += 0.1;
		v2_x += 0.1;
		v3_x += 0.1;
		v4_x += 0.1;
		Sleep(50); //딜레이
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) // 특수한키에 대한 KeyboardCallback함수 호출시 실행되는 함수
{
	switch (key)
	{
	case GLUT_KEY_UP:
		glutIdleFunc(MyIdle_up); // IdleCallback 함수를 사용해 호출
		break;
	case GLUT_KEY_DOWN:
		glutIdleFunc(MyIdle_down);// IdleCallback 함수를 사용해 호출
		break;
	case GLUT_KEY_LEFT:
		glutIdleFunc(MyIdle_left);// IdleCallback 함수를 사용해 호출
		break;
	case GLUT_KEY_RIGHT:
		glutIdleFunc(MyIdle_right);// IdleCallback 함수를 사용해 호출
		break;
	default:
		break;
	}
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
	glutCreateWindow("Idle Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutSpecialFunc(MySpecial); // KeyboardCallback 함수 호출
	glutMainLoop();
	return 0;
}