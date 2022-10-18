/***********************************************************************/
/*                           HW#3 :  TimerCallback �Լ� ����                            */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 10�� 7��    */
/*                                                                                                 */
/* ���� ���� :   TimerCallback�Լ��� ����� ������ �ð������� ������ �����س��� �Լ��� ��ȣ����  */
/*                - - - - - - -                                                                   */
/* ��� :        ��ü�� �������� 0.1�� �̵��ϴٰ� ������ â�� ������ ������ �����ϰ�
				 �ݴ� �������� �̵��ϴ� �ൿ�� �ݺ��Ѵ�.
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
// ��ü�� x���� ������ ����
GLfloat Delta = 0.0;
// ��ü�� ������ ������ ����
GLfloat color_R = 0.0;
GLfloat color_G = 0.5;
GLfloat color_B = 0.8;
// ���ǹ����� ����� ����
GLint a = 0;
void MyDisplay() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON); // polygon ���·� ��ü ���� 
	glColor3f(color_R, color_G, color_B); // ������ ���ؼ� ���� ����
	// ������ ���ؼ� ��ü�� �� ������ x���� ����
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}
void MyTimer(int value) // ������ �ð� �������� ȣ��� �Լ�
{
	if (a == 0) // a�� 0�� ���
	{
		Delta += 0.1; // ��ü�� ���������� 0.1��ŭ �̵�
		glutPostRedisplay();
	}
	if (a == 1) // a�� 1�� ���
	{
		Delta -= 0.1; // ��ü�� �������� 0.1��ŭ �̵�
		glutPostRedisplay();
	}
	if (0.0 + Delta > 1.0) // ��ü�� ������ ������ â�� ��� ���
	{
		a = 1; // a�� 1�� ���� (�������� �̵��ϰ�)
		// ������ ����������
		color_R = 1.0;
		color_G = 0.0;
		color_B = 0.0;
		glutPostRedisplay();
	}
	if (-1.0 + Delta < -0.9) // ��ü�� ���� ������ â�� ��°��
	{
		a = 0; // a�� 0���� ���� (���������� �̵��ϰ�)
		// ������ Ǫ��������
		color_R = 0.0;
		color_G = 0.0;
		color_B = 1.0;
		glutPostRedisplay();
	}
	
	
	glutTimerFunc(50, MyTimer, 1); // TimerCallback �Լ� ȣ�� �� �Լ��� 50msec �Ŀ� ȣ��
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
	glutTimerFunc(40, MyTimer, 1); //TimerCallback �Լ� ȣ�� �� MyTimer �Լ��� ȣ����.
	glutMainLoop();
	return 0;
}