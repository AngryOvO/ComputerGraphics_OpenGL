/***********************************************************************/
/*                           HW#3 : Mouse Callback ����                                 */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 10�� 7��    */
/*                                                                                                 */
/* ���� ���� :   Mouse callback �Լ��� �̿��� Ư�� Ű�� �Է��� ��ü�� �̵� �Ǵ� ������ ��ȯ�Ѵ�.*/
/*                - - - - - - -                                                                   */
/* ��� :        ���콺 ���� ��ư : ��ü�� ���������� 0.1�� ���������� �̵�
				 ���콺 ������ ��ư : �̵��ϰ� �ִ� ��ü�� ����
				 ���� : ������ ��ġ�� ����ֵ��� ������� ����
						������â�� ����� �ȵ�
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
#include <windows.h>

// ��ü�� ��ǥ�� ������ ���� ���� �� �ʱ�ȭ
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
	glMatrixMode(GL_PROJECTION); // ��� ��带 ���� ��ķ� ����
	glLoadIdentity(); // �׵���ķ� �ʱ�ȭ
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON); // polygon ���·� ���� ����
	// �� ������ ������ ���ؼ� ������.
	glVertex3f(v1_x, v1_y, 0.0);
	glVertex3f(v2_x, v2_y, 0.0);
	glVertex3f(v3_x, v3_y, 0.0);
	glVertex3f(v4_x, v4_y, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) //KeyboardCallback �Լ�
{
	switch (key) // q�� �Է½� ����
	{
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}

void Mouseclick_idle() // IdleCallback �Լ� ȣ��� ����Ǵ� �Լ�
{
	if (v2_x <= 1.0 && v3_x <= 1.0) // ������â�� �ѱ��� �ʴ� ���� �Ͽ�
	{
		// x��ǥ 0.1�� ����
		v1_x += 0.1;
		v2_x += 0.1;
		v3_x += 0.1;
		v4_x += 0.1;
		Sleep(350); // 350ms �ʵ��� ������.
	}
	glutPostRedisplay();
}

void MyMouse(GLint Button, GLint State , GLint X, GLint Y) //MouseCallback �Լ� ȣ��� ����Ǵ� �Լ�
{
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) glutIdleFunc(Mouseclick_idle); 
	//���� ��ư Ŭ���� Idle Callback �Լ� ����
	if ((Button == GLUT_RIGHT_BUTTON) && (State == GLUT_DOWN)) glutIdleFunc(NULL); 
	//������ ��ư Ŭ���� Idle Callback �Լ� ���ڰ� NULL�� �޾Ƽ� ����
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
