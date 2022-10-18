/***********************************************************************/
/*                           HW#2 : GLU Modeling                                     */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 9�� 30��    */
/*                                                                                                 */
/* ���� ���� :   GLU modeling�� �����Ѵ�. 3D Primitives �����Ѵ�. : Sphere, Cylinder, Disk, PatialDisk                                                                           */
/*                - - - - - - -                                                                   */
/* ��� :  ���÷��� ����Ʈ�� Ȱ���� 3D �������� ��ü�� �����Ѵ�.
		   ����, ���� ���õ� �Լ����� Ȱ���� ��ü�� ������ ��ġ�� ���� ��� �ٸ��� ���̴��� Ȯ���ߴ�.*/
/*                - - - - - - -                                                                   */
/***********************************************************************/


#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

GLuint listA, listB, listC, listD; // ���÷��� ����Ʈ ����
GLUquadricObj* qobj = gluNewQuadric(); // ���ο� Quadric ��ü ����

void MyCreateList()
{
	listA = glGenLists(4); //glGenLists �Լ��� �̿��ؼ� ������� ���� ID�� ��ȯ
	// �ѹ��� �װ��� ����Ʈ ID �Ҵ�
	listB = listA + 1; 
	listC = listB + 1;
	listD = listC + 1;

	glNewList(listA, GL_COMPILE); // ����ƮA ���� , �ٷ� �������� �ʰ� �����ϰ����� ����
	gluQuadricDrawStyle(qobj, GLU_FILL); // DrawStyle�� Solid ���·� ����
	gluSphere(qobj, 1.0, 50, 50); // ������ 1.0, subdivision�� ��� 50���� ������ ��
	glTranslatef(-2, -2, 2); // �����̵�
	glEndList();

	glNewList(listB, GL_COMPILE); // ����ƮB ����
	gluQuadricDrawStyle(qobj, GLU_LINE); // DrawStyle�� Wire-frame ���� ����
	gluCylinder(qobj, 1.0, 0.5, 2.0, 8, 8); // �ٴڸ��� ������ 1.0, ���� ���� ������ 0.5�� �����
	glTranslatef(4, 4, 0); // �����̵�
	glEndList();

	glNewList(listC, GL_COMPILE); // ����ƮC ����
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE); // �ܺ� �𼭸��� �𵨸��ϴ� DrawStyle ���
	gluDisk(qobj, 0.5, 1, 20, 1); // ���� ������ 0.5 �ٱ� ������ 0.1�� ��ũ
	glTranslatef(-2, 2, 0); // �����̵�
	glEndList();

	glNewList(listD, GL_COMPILE); // ����ƮD ����
	gluQuadricDrawStyle(qobj, GLU_POINT); // ������ �𵨸�
	gluPartialDisk(qobj, 0.3, 1.0, 26, 13, 0, 90); //  ���� ������ 0.3 �ٱ��� ������ 1.0 ���� 90���� �߸� disk���
	glTranslatef(2, -2, 0); // �����̵�
	glEndList();
}

void MyInit(void)
{
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; // �ֺ��� ����
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // �ݻ籤 ����
	GLfloat mat_shininess[] = { 50.0 }; //����
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // ������ ��ġ
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0); //���� ����������


	//���� �𵨿� ���� ���� ����
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//���� ���� ����
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

	// ���� �ѱ�
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0); 
	glEnable(GL_DEPTH_TEST);
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�÷� ����& ���� ���۸� �ʱ�ȭ

	glMatrixMode(GL_MODELVIEW); // ��� ��带 �𵨺��
	glLoadIdentity(); //�׵���ķ� �ʱ�ȭ 

	glViewport(0, 0, 500, 500); // ���� ���� : ������ȯ �Լ� ȣ��
	gluLookAt(0.0, 0.0, 0.0, 0.0, 1.0, -1.0, 0.0, 1.0, 0.0);  // ī�޶� ��ġ ����

	glEnable(GL_LIGHTING); // ���� �ѱ�
	glShadeModel(GL_SMOOTH); // �� ������ ������ �ε巴�� �����Ͽ� ä��
	
	gluQuadricNormals(qobj, GLU_SMOOTH); //��ü�� �𼭸��� �ε巴��
	gluQuadricOrientation(qobj, GLU_OUTSIDE); 
	gluQuadricTexture(qobj, GL_FALSE);

	//���÷��� ����Ʈ ȣ��
	glCallList(listA);
	glCallList(listB);
	glCallList(listC);
	glCallList(listD);

	glutSwapBuffers(); // ������ ���� ��ȯ
}

void Reshape(int width, int height) //reshape �Լ� 
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); 

	glMatrixMode(GL_PROJECTION); //��� ��带 ������ķ�
	glLoadIdentity(); //�׵���ķ� �ʱ�ȭ

	glOrtho(-5.0, 5.0, -5.0*((GLfloat)height/(GLfloat)width), 5.0*((GLfloat)height/(GLfloat)height), -5.0, 5.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //���÷��� ��� ����
	glutInitWindowSize(500, 500); //������ ũ�� 500,500
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3D Primitives");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); //�������� ��ȯ 

	MyInit();
	glutDisplayFunc(MyDisplay); //Display Callback
	glutReshapeFunc(Reshape); // Reshape Callback
	MyCreateList(); 

	glutMainLoop(); 
	gluDeleteQuadric(qobj); //�����Ҵ� ���� Quadric �Ҵ� ����
}