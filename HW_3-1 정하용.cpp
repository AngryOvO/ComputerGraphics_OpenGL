/***********************************************************************/
/*                           HW#3 : Keyboard Callback1                                     */
/*  작성자 : 정하용                              날짜 : 2022년 10월 7일    */
/*                                                                                                 */
/* 문제 정의 :   Keyboard callback 함수를 이용해 특정 키를 입력해 물체를 이동 또는 색상을 변환한다.*/
/*                - - - - - - -                                                                   */
/* 기능 :        q : 종료 
				 a : 왼쪽으로 0.1만큼 이동 
				 f : 오른쪽으로 0.1 만큼 이동
				 r : 아래쪽으로 0.1 만큼 이동하고 색상을 붉은색으로
				 b : 색상을 파란색으로
				 v : 위쪽으로 0.1만큼 이동
				 */
/*                - - - - - - -                                                                   */
/***********************************************************************/

#include <gl/glut.h>

// 물체의 좌표를 결정할 변수 생성
GLfloat move_x = 0.0;
GLfloat move_y = 0.0;
// 물체의 색상을 결정할 변수 생성
GLfloat color_R = 0.5;
GLfloat color_G = 0.5;
GLfloat color_B = 0.5;


void MyInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영행렬 모드로
	glLoadIdentity(); // 항등행렬로 초기화
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(color_R, color_G, color_B); // 물체의 색상은 변수를 통해서 결정
	glBegin(GL_POLYGON); // polygon 형태로 물체 생성
		// 각 정점의 좌표는 변수를 통해서 결정
		glVertex3f(-0.5 + move_x, -0.5 + move_y, 0.0);
		glVertex3f(0.5 + move_x, -0.5 + move_y, 0.0);
		glVertex3f(0.5 + move_x, 0.5 + move_y, 0.0);
		glVertex3f(-0.5 + move_x, 0.5 + move_y, 0.0);
	glEnd();
	glFlush();

}

void MyKeyboard(unsigned char key, int x, int y) // KeyboardCallback 함수의 실행함수
{
	switch (key) // key값을 받아서
	{
	case 'Q': exit(0); break; //Q일경우 종료
	case 'q': exit(0); break;
	case 27: exit(0); break;
	case 'A': // key값이 A일경우
		move_x -= 0.1; // x축 좌표값을 -0.1만큼 더함
		glutPostRedisplay(); // 변경된 내용으로 화면 재출력
		break;
	case 'a':
		move_x -= 0.1;
		glutPostRedisplay();
		break;
	case 'f': // key값이 f일 경우
		move_x += 0.1;// x축 좌표값을 0.1만큼 더함
		glutPostRedisplay();
		break;
	case 'F':
		move_x += 0.1;
		glutPostRedisplay();
		break;
	case 'r': // key값이 r일 경우
		move_y -= 0.1; // y축 좌표값을 -0.1만큼 더함
		// rgb 값을 1 0 0 으로 즉 붉은색으로 변경
		color_R = 1.0;
		color_G = 0.0;
		color_B = 0.0;
		glutPostRedisplay();
		break;
	case 'R': 
		move_y -= 0.1;
		color_R = 1.0;
		color_G = 0.0;
		color_B = 0.0;
		glutPostRedisplay();
		break;
	case 'b': //key값이 b인 경우
		// rgb 값을 0 0 1 으로 즉 파란색으로 변경
		color_R = 0.0;
		color_G = 0.0;
		color_B = 1.0;
		glutPostRedisplay();
		break;
	case 'B':
		color_R = 0.0;
		color_G = 0.0;
		color_B = 1.0;
		glutPostRedisplay();
		break;
	case 'v': // key값이 v인 경우
		move_y += 0.1; // // y축 좌표값을 0.1만큼 더함
		glutPostRedisplay();
		break;
	case 'V':
		move_y += 0.1;
		glutPostRedisplay();
		break;
	}
	glutPostRedisplay();
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

	glutMainLoop();
	return 0;
}