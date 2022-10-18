/***********************************************************************/
/*                           HW#3 : Menu Callback ����                                 */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 10�� 7��    */
/*                                                                                                 */
/* ���� ���� :   Menu callback �Լ��� Ȱ���� �޴��� �´� ��ü�� �����ϰ� ũ��� ������ �����Ѵ� */
/*                - - - - - - -                                                                   */
/* ��� :        ������ ��ü�� �̸��� �޴��� ����� ������ �޴��� ����޴��� ũ�⸦ ������ �� �ִ�.
				 �޴��� ������ �����ϴ� �޴��� ���α׷��� �����ϴ� �޴����� �����Ѵ�.
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
// � ��ü�� �������� �Ǵ��� bool�� ����
GLboolean IsSphere = true; 
GLboolean IsSmall = true;
GLboolean IsTourus = true;

// ������ ������ ���� ���� �� �ʱ�ȭ
GLfloat color_R = 0.0;
GLfloat color_G = 0.5;
GLfloat color_B = 0.5;

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// ���� ������ ��ü�� ���� ����
	glColor3f(color_R, color_G, color_B);

	if ((!IsTourus) && (IsSphere) && (IsSmall)) // Sphere �̸鼭 small�� ���
		glutWireSphere(0.5, 30, 30);
	else if ((!IsTourus) && (IsSphere) && (!IsSmall)) // Sphere �̸鼭 Large�� ���
		glutWireSphere(0.7, 30, 30);
	else if ((!IsSphere) && (IsTourus) && (IsSmall)) // Tourus �̸鼭 small�� ���
		glutWireTorus(0.1, 0.3, 40, 20);
	else if ((!IsSphere) && (IsTourus) && (!IsSmall)) // Tourus �̸鼭 Large�� ���
		glutWireTorus(0.2, 0.5, 40, 20);
	else if ((!IsSphere) && (!IsTourus) && (IsSmall)) // Teapot �̸鼭 small�� ���
		glutWireTeapot(0.1);
	else //Teapo �̸鼭 Large�� ���
		glutWireTeapot(0.2);
	glFlush();
}
void MyMainMenu(int entryID) // MainMenu �Լ� ����� ȣ��Ǵ� �Լ�
{
	if (entryID == 1) exit(0); // ���ڰ����� 1�� ������ ����
	glutPostRedisplay();
}
void MySizeMenu_Sphere(int entryID) // Sphere�� �������� ���
{
	if (entryID == 1) // ���ڰ��� 1�ϰ�� small ũ��� ����
	{
		IsSphere = true;
		IsTourus = false;
		IsSmall = true;
	} 
	else if (entryID == 2) // ���ڰ��� 2�ϰ�� large ũ��� ����
	{
		IsSphere = true;
		IsTourus = false;
		IsSmall = false;
	}
	glutPostRedisplay();
}

void MySizeMenu_Torus(int entryID) // Tourus�� �������� ���
{
	if (entryID == 1) // ���ڰ��� 1�� ���� ��� smallũ��� ����
	{
		IsSphere = false;
		IsTourus = true;
		IsSmall = true;
	}
	else if (entryID == 2) // ���ڰ��� 2�� ���� ��� large ũ��� ����
	{
		IsSphere = false;
		IsTourus = true;
		IsSmall = false;
	}
	glutPostRedisplay();
}

void MySizeMenu_Teapot(int entryID) // Teapot�� �������� ���
{
	if (entryID == 1) // ���ڰ��� 1�̸� smallũ���
	{
		IsSphere = false;
		IsTourus = false;
		IsSmall = true;
	}
	else if (entryID == 2) // ���ڰ��� 2�̸� Largeũ���
	{
		IsSphere = false;
		IsTourus = false;
		IsSmall = false;
	}
	glutPostRedisplay();
}

void MyChangeColor(int entryID) // Color�� �������� ���
{
	if (entryID == 1) // ���ڰ��� 1�ΰ�� ������ ������
	{
		color_R = 1.0;
		color_G = 0.0;
		color_B = 0.0;
	}
	else if (entryID == 2) // ���ڰ��� 2�ΰ�� ������ ���
	{
		color_R = 0.0;
		color_G = 1.0;
		color_B = 0.0;
	}
	else if (entryID == 3) // ���ڰ��� 3�ΰ�� ������ �Ķ���
	{
		color_R = 0.0;
		color_G = 0.0;
		color_B = 1.0;
	}
	glutPostRedisplay();
}

void MyInit() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	// Sphere �޴� ���� �� sub �޴� ����
	GLint MySizeID_Sphere = glutCreateMenu(MySizeMenu_Sphere);
	glutAddMenuEntry("Small Sphere", 1);
	glutAddMenuEntry("Large Sphere", 2);
	// Torus �޴� ���� �� sub �޴� ����
	GLint MySizeID_Torus = glutCreateMenu(MySizeMenu_Torus);
	glutAddMenuEntry("Small Torus", 1);
	glutAddMenuEntry("Large Torus", 2);
	// Teapot �޴� ���� �� sub �޴� ����
	GLint MySizeID_Teapot = glutCreateMenu(MySizeMenu_Teapot);
	glutAddMenuEntry("Small Teapot", 1);
	glutAddMenuEntry("Large Teapot", 2);
	// Color �޴� ���� �� sub �޴� ����
	GLint MyColorID = glutCreateMenu(MyChangeColor);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	// Main�޴� ���� �� ������ sub�޴��� ��� ����
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySizeID_Sphere);
	glutAddSubMenu("Draw Torus", MySizeID_Torus);
	glutAddSubMenu("Draw Teapot", MySizeID_Teapot);
	glutAddSubMenu("Change Color", MyColorID);
	glutAddMenuEntry("Exit",1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char** argv) 
{
	glutInit(&argc, argv); glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500); glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}