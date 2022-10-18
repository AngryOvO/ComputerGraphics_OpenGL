/***********************************************************************/
/*                           HW#3 : Keyboard Callback1                                     */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 10�� 7��    */
/*                                                                                                 */
/* ���� ���� :   Keyboard callback �Լ��� �̿��� Ư�� Ű�� �Է��� ��ü�� �̵� �Ǵ� ������ ��ȯ�Ѵ�.*/
/*                - - - - - - -                                                                   */
/* ��� :        q : ���� 
				 a : �������� 0.1��ŭ �̵� 
				 f : ���������� 0.1 ��ŭ �̵�
				 r : �Ʒ������� 0.1 ��ŭ �̵��ϰ� ������ ����������
				 b : ������ �Ķ�������
				 v : �������� 0.1��ŭ �̵�
				 */
/*                - - - - - - -                                                                   */
/***********************************************************************/

#include <gl/glut.h>

// ��ü�� ��ǥ�� ������ ���� ����
GLfloat move_x = 0.0;
GLfloat move_y = 0.0;
// ��ü�� ������ ������ ���� ����
GLfloat color_R = 0.5;
GLfloat color_G = 0.5;
GLfloat color_B = 0.5;


void MyInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); // ��� ��带 ������� ����
	glLoadIdentity(); // �׵���ķ� �ʱ�ȭ
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(color_R, color_G, color_B); // ��ü�� ������ ������ ���ؼ� ����
	glBegin(GL_POLYGON); // polygon ���·� ��ü ����
		// �� ������ ��ǥ�� ������ ���ؼ� ����
		glVertex3f(-0.5 + move_x, -0.5 + move_y, 0.0);
		glVertex3f(0.5 + move_x, -0.5 + move_y, 0.0);
		glVertex3f(0.5 + move_x, 0.5 + move_y, 0.0);
		glVertex3f(-0.5 + move_x, 0.5 + move_y, 0.0);
	glEnd();
	glFlush();

}

void MyKeyboard(unsigned char key, int x, int y) // KeyboardCallback �Լ��� �����Լ�
{
	switch (key) // key���� �޾Ƽ�
	{
	case 'Q': exit(0); break; //Q�ϰ�� ����
	case 'q': exit(0); break;
	case 27: exit(0); break;
	case 'A': // key���� A�ϰ��
		move_x -= 0.1; // x�� ��ǥ���� -0.1��ŭ ����
		glutPostRedisplay(); // ����� �������� ȭ�� �����
		break;
	case 'a':
		move_x -= 0.1;
		glutPostRedisplay();
		break;
	case 'f': // key���� f�� ���
		move_x += 0.1;// x�� ��ǥ���� 0.1��ŭ ����
		glutPostRedisplay();
		break;
	case 'F':
		move_x += 0.1;
		glutPostRedisplay();
		break;
	case 'r': // key���� r�� ���
		move_y -= 0.1; // y�� ��ǥ���� -0.1��ŭ ����
		// rgb ���� 1 0 0 ���� �� ���������� ����
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
	case 'b': //key���� b�� ���
		// rgb ���� 0 0 1 ���� �� �Ķ������� ����
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
	case 'v': // key���� v�� ���
		move_y += 0.1; // // y�� ��ǥ���� 0.1��ŭ ����
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