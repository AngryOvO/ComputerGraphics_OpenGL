/***********************************************************************/
/*                           HW#2 : GL Modeling                                     */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 9�� 30��    */
/*                                                                                                 */
/* ���� ���� :   GL modeling�� �����Ѵ�. 2D Primitives �����Ѵ�.                                                                           */
/*                - - - - - - -                                                                   */
/* ��� :  GL modeling�� �����ϱ� ���� �� �������� �� ��鿡 �°� ��´�.
		   ��翡 �°� ��ǥ�� ������ �� ũ�⿡ �°� ��ǥ�� ��Į��踦 �ϰų� ������ ��ġ�� ã�ư��� ����
			�����̵����� �� ���� ��ǥ�� �����. ������ �� ���̰� �������� ����ߴ�.*/
		   /*                                 */
		   /***********************************************************************/

#include <GL/glut.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //�÷� ���� �ʱ�ȭ
	glColor3f(1.0, 0.0, 0.0); //���������� ����
	
	//�� ������ ��ǥ
	glBegin(GL_POINTS); // ��ǥ�� ���� ����
		glVertex3f(-8.0, 9.0, 0.0); glVertex3f(-9.0, 8.5, 0.0);
		glVertex3f(-9.0, 7.5, 0.0); glVertex3f(-8.0, 7.0, 0.0);
		glVertex3f(-7.0, 7.5, 0.0); glVertex3f(-7.0, 8.5, 0.0);
	glEnd();
	glBegin(GL_LINES); // �� �����̸� �մ� ���� 3��
		glVertex3f(-5.0, 9.0, 0.0); glVertex3f(-6.0, 8.5, 0.0);
		glVertex3f(-6.0, 7.5, 0.0); glVertex3f(-5.0, 7.0, 0.0);
		glVertex3f(-4.0, 7.5, 0.0); glVertex3f(-4.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP); //2���� ���� ������ �ϳ��� �������� ����
		glVertex3f(-2.0, 9.0, 0.0); glVertex3f(-3.0, 8.5, 0.0);
		glVertex3f(-3.0, 7.5, 0.0); glVertex3f(-2.0, 7.0, 0.0);
		glVertex3f(-1.0, 7.5, 0.0); glVertex3f(-1.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP); // ��ǥ�� ���� ������ �°� ������ ��� ����
		glVertex3f(1.0, 9.0, 0.0); glVertex3f(0.0, 8.5, 0.0);
		glVertex3f(0.0, 7.5, 0.0); glVertex3f(1.0, 7.0, 0.0);
		glVertex3f(2.0, 7.5, 0.0); glVertex3f(2.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON); // �ٰ���, ���� ������ ä��
		glVertex3f(4.0, 9.0, 0.0); glVertex3f(3.0, 8.5, 0.0);
		glVertex3f(3.0, 7.5, 0.0); glVertex3f(4.0, 7.0, 0.0);
		glVertex3f(5.0, 7.5, 0.0); glVertex3f(5.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);	//3���� �������� �ﰢ���� ����
		glVertex3f(-8.0, 6.0, 0.0); glVertex3f(-9.0, 5.5, 0.0);
		glVertex3f(-9.0, 4.5, 0.0); glVertex3f(-8.0, 4.0, 0.0);
		glVertex3f(-7.0, 4.5, 0.0); glVertex3f(-7.0, 5.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); //3���� ���� �ﰢ���� ����� ����
		glVertex3f(-4.0, 3.5, 0.0); glVertex3f(-4.5, 6.2, 0.0);
		glVertex3f(-5.0, 4.0, 0.0); glVertex3f(-5.5, 6.0, 0.0);
		glVertex3f(-6.0, 3.5, 0.0); glVertex3f(-6.5, 5.5, 0.0);
		glVertex3f(-7.0, 3.6, 0.0);
	glEnd();


	//���⼭���ʹ� ������ ��ǥ����� Ȱ���ؼ� �׸��� ��Į��踦 ���� ũ�⸦ �����ϰ� �����̵����� �ڸ��� ��Ҵ�.
	glBegin(GL_TRIANGLE_FAN);  // �ﰢ������ ��ä�� ����� ǥ��
	glVertex3f(-3.0*2.0 + 3.0, 3.5*2.0 - 3.5, 0.0); glVertex3f(-1.5*2.0 + 3.0, 4.0*2.0 - 3.5, 0.0);
	glVertex3f(-1.7*2.0 + 3.0, 4.3*2.0 - 3.5, 0.0); glVertex3f(-2.0*2.0 + 3.0, 4.5*2.0 - 3.5, 0.0);
	glVertex3f(-2.2*2.0 + 3.0, 4.8*2.0 - 3.5, 0.0); glVertex3f(-2.5*2.0 + 3.0, 5.0*2.0 - 3.5, 0.0);
	glEnd();

	glBegin(GL_QUADS); // 4���� ���������� ���� �ٰ��� : �簢��
	glVertex3f(5.2-4, 0.0+4, 0.0); glVertex3f(5.5-4, 1.0+4, 0.0);
	glVertex3f(6.0-4, 1.5+4, 0.0); glVertex3f(6.5-4, 1.0+4, 0.0);
	glVertex3f(6.7-4, 1.0+4, 0.0); glVertex3f(7.5-4, 1.5+4, 0.0);
	glVertex3f(8.0-4, 0.5+4, 0.0); glVertex3f(7.0-4, 0.0+4, 0.0);
	glEnd();

	glBegin(GL_QUAD_STRIP); // 4���� ���� �簢������ ����
	glVertex3f(0.0+8, 0.0+4, 0.0); glVertex3f(0.75*0.75+8, 2.0*0.75 + 4, 0.0);
	glVertex3f(-2.0*0.75+8, 0.0 + 4, 0.0); glVertex3f(-0.8*0.75+8, 2.8*0.75 + 4, 0.0);
	glVertex3f(-2.8*0.75+8, 1.6*0.75 + 4, 0.0); glVertex3f(-2.8*0.75+8, 4.0*0.75 + 4, 0.0);
	glVertex3f(-4.4*0.75+8, 2.8*0.75 + 4, 0.0); glVertex3f(-4.4*0.75+8, 3.6*0.75 + 4, 0.0);
	glEnd();
	

	glFlush();
	
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); //OS�� ���� �� �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB); //���÷��� ��带 RGB����
	glutInitWindowSize(500, 500); //������ ũ�� ����
	glutInitWindowPosition(0, 0); //������ ���� ��ġ ����
	glutCreateWindow("2D Primitive"); //������ Ÿ��Ʋ�� ����
	glClearColor(1.0, 1.0, 1.0, 1.0); //������ ������ �ʱ�ȭ (���)
	glutDisplayFunc(MyDisplay); //��ü���� �ִ� MyDisplay �Լ� ȣ��
	glViewport(0, 0, 500, 500); // ����Ʈ ���� ������ȯ �Լ�
	glMatrixMode(GL_PROJECTION); // ��� ��带 ��������
	glLoadIdentity(); // �׵���ķ� �ʱ�ȭ
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // ������������ ��ȯ
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutMainLoop();
	
}