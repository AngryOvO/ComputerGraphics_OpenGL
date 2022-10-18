/***********************************************************************/
/*                           HW#3 : IDLE Callback ����                                 */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 10�� 7��    */
/*                                                                                                 */
/* ���� ���� :   IDLE callback �Լ��� Ȱ���� �׷��� �⺻ ��Ҹ�  ��� �����Ѵ�  */
/*                - - - - - - -                                                                   */
/* ��� :        �ǽ����� 3-2 �� ����ϰ� Ű������ ����Ű�� ������ �� ����Ű�� �°� 
				 ��ü�� �̵��Ѵ�. ������ 3-2�����ʹ� �ٸ��� ����Ű�� �ѹ� ������
			     ������â ���� ��� ������ ���������� �̵��Ѵ�.
				 �̴� IdleCallback�Լ��� ������۸��� Ȱ���� �ִϸ��̼��� �����Ѵ�.
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
#include <Windows.h>

// �� ������ ��ǥ�� ��Ÿ�� ���� ���� �� �ʱ�ȭ
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
	glBegin(GL_POLYGON);// polygon ���·� ��ü ����
	glColor3f(0.0, 0.5, 0.8);// ��ü ���� ����
	// ������ �� ������ ������ ���ؼ� ����
	glVertex3f(v1_x, v1_y, 0.0);
	glVertex3f(v2_x, v2_y, 0.0);
	glVertex3f(v3_x, v3_y, 0.0);
	glVertex3f(v4_x, v4_y, 0.0);
	glEnd();
	glutSwapBuffers(); // ���� ���۸��� ����ϱ� ���� glflush�� ������� �ʰ� swapbuffers ���
}
void MyIdle_up()  // ���� ����Ű�� ������ ���
{
	if (v3_y <= 1.0 && v4_y <= 1.0) // ������ â�� ��� ���̸�
	{
		// y�� �������� 0.1 ��ŭ ����
		v1_y += 0.1;
		v2_y += 0.1;
		v3_y += 0.1;
		v4_y += 0.1;
		Sleep(50); // ������ �����̸� ��
	}
	glutPostRedisplay(); // ����� ��ü�� ȭ�鿡 �����
}

void MyIdle_down() //�Ʒ��� ����Ű�� ������ ��
{
	if (v1_y >= -1.0 && v2_y >= -1.0) // ������ â�� ��� ������
	{
		// y�� �������� -0.1 ��ŭ ����
		v1_y -= 0.1;
		v2_y -= 0.1;
		v3_y -= 0.1;
		v4_y -= 0.1;
		Sleep(50); // ������
	}
	glutPostRedisplay();
}

void MyIdle_left() // ���� ����Ű�� ������ ���
{
	if (v1_x >= -1.0 && v4_x >= -1.0) // ������ â�� ��� ������
	{
		// x�� �������� -0.1��ŭ ����
		v1_x -= 0.1;
		v2_x -= 0.1;
		v3_x -= 0.1;
		v4_x -= 0.1;
		Sleep(50); // ������
	}
	glutPostRedisplay();
}

void MyIdle_right() // ������ ����Ű�� ������ ���
{
	if (v2_x <= 1.0 && v3_x <= 1.0) // ������ â�� ��� ������
	{
		// x�� �������� 0.1��ŭ ����
		v1_x += 0.1;
		v2_x += 0.1;
		v3_x += 0.1;
		v4_x += 0.1;
		Sleep(50); //������
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) // Ư����Ű�� ���� KeyboardCallback�Լ� ȣ��� ����Ǵ� �Լ�
{
	switch (key)
	{
	case GLUT_KEY_UP:
		glutIdleFunc(MyIdle_up); // IdleCallback �Լ��� ����� ȣ��
		break;
	case GLUT_KEY_DOWN:
		glutIdleFunc(MyIdle_down);// IdleCallback �Լ��� ����� ȣ��
		break;
	case GLUT_KEY_LEFT:
		glutIdleFunc(MyIdle_left);// IdleCallback �Լ��� ����� ȣ��
		break;
	case GLUT_KEY_RIGHT:
		glutIdleFunc(MyIdle_right);// IdleCallback �Լ��� ����� ȣ��
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
	glutSpecialFunc(MySpecial); // KeyboardCallback �Լ� ȣ��
	glutMainLoop();
	return 0;
}