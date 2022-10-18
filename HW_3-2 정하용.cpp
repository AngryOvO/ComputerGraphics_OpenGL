/***********************************************************************/
/*                           HW#3 : Keyboard Callback 2                                   */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 10�� 7��    */
/*                                                                                                 */
/* ���� ���� :   Keyboard callback �Լ��� �̿��� Ư�� Ű�� �Է��� ��ü�� �̵� �Ǵ� ������ ��ȯ�Ѵ�.*/
/*                - - - - - - -                                                                   */
/* ��� :        q : ����
				 ���� ����Ű : �������� 0.1��ŭ �̵�
				 ������ ����Ű : ���������� 0.1 ��ŭ �̵�
				 �Ʒ��� ����Ű : �Ʒ������� 0.1 ��ŭ �̵�
				 ���� ����Ű : �������� 0.1��ŭ �̵�
				 page up : ������ �� ������ 0.1 �� Ȯ��
				 page down : ������ �� ������ 0.1 �� ���
				 ���ǻ��� : ������ ������â �ȿ����� �̵��� �� ����
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>

// �������� ���� ���� ����
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
	glColor3f(0.5, 0.5, 0.5); // ������ ȸ��
	glBegin(GL_POLYGON); // polygon ���·� ����
	// �̹��� ��� ������ ���� �ٸ� ������ ���ؼ� ����
	glVertex3f(v1_x, v1_y, 0.0);
	glVertex3f(v2_x, v2_y, 0.0);
	glVertex3f(v3_x, v3_y, 0.0);
	glVertex3f(v4_x, v4_y, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) //keyboardCallbak ȣ��� ����Ǵ� �Լ�
{
	switch (key)
	{
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) // Ư��Ű�鿡 ���� KeyboardCallback �Լ� ȣ��� ����Ǵ� �Լ�
{
	switch (key)
	{
	case GLUT_KEY_UP: // ����Ű ����
		if (v3_y <= 1.0 && v4_y <= 1.0) // y��ǥ�� 1.0�� ���� �ʴ� ��쿡�� ����
		{
			// ��� y ��ǥ�� 0.1�� ����
			v1_y += 0.1;
			v2_y += 0.1;
			v3_y += 0.1;
			v4_y += 0.1;
		}
		glutPostRedisplay(); // ����� �������� ȭ�� �����
		break;
	case GLUT_KEY_DOWN: // ����Ű �Ʒ���
		if (v1_y >= -1.0 && v2_y >= -1.0) // y��ǥ�� -1.0�� ���� �ʴ� ��쿡�� ����
		{
			// ��� y ��ǥ�� -0.1�� ����
			v1_y -= 0.1;
			v2_y -= 0.1;
			v3_y -= 0.1;
			v4_y -= 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT: // ����Ű ����
		if (v1_x >= -1.0 && v4_x >= -1.0) // x��ǥ�� -1.0�� ���� �ʴ� ��쿡�� ����
		{
			// ��� x ��ǥ�� -0.1�� ����
			v1_x -= 0.1;
			v2_x -= 0.1;
			v3_x -= 0.1;
			v4_x -= 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT: // ����Ű ������
		if (v2_x <= 1.0 && v3_x <= 1.0) // x��ǥ�� 1.0�� ���� �ʴ� ��쿡�� ����
		{
			// ��� x ��ǥ�� 0.1�� ����
			v1_x += 0.1;
			v2_x += 0.1;
			v3_x += 0.1;
			v4_x += 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP: // page up Ű�� ������ ���
		if (v1_x >= -1.0 && v1_y >= -1.0 && v2_x <= 1.0 && v2_y >= -1.0 && v3_x <= 1.0 && v3_y <= 1.0 && v4_x >= -1.0 && v4_y <= 1.0) // �� ��ǥ�� ������â�� ���� �ʴ� ������
		{
			// �� ��ǥ���� ���⿡ �°� ����
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
	case GLUT_KEY_PAGE_DOWN: // page down Ű�� ������ ���
		if ((v2_x - v1_x  ) >= 0.3) // ������ �ּ����� ũ�⸦ �����ϴ� ������
		{
			// �� ��ǥ���� ���⿡ �°� ����
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
