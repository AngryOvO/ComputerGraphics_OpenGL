/***********************************************************************/
/*                           HW#1 : 3D Sierpinski Gasket                                     */
/*  �ۼ��� : ���Ͽ�                              ��¥ : 2022�� 9�� 20��    */
/*                                                                                                 */
/* ���� ���� :  2D�� ������ Sierpinski Gasket�� 3D���·� �����ϴ� �����̴�.
				Reshape callback �Լ��� ����� ������ â�� ũ�⸦ ������ѵ�
				��ü�� ������ ������ �����ϵ��� �Ѵ�.*/
/*                - - - - - - -                                                                   */
/* ��� :      ���� 2D������ �ﰢ�� ����̿����Ƿ� ������ ���� ������� 3D���� ���ü�̹Ƿ� ������ �װ� ��´�.
			   3���� �����̹Ƿ� ��ǥ���� ���� ����ϹǷ� [4][3]ũ���� 2�����迭�� ����Ѵ�.
			   ��ǥ���� ���� ����ϸ鼭 ���� ������ ���� ��ǥ ���� 3�������� �����ϰ�,
			   ���� ���� ������ �������� ������ ����� �ݺ��Ѵ�.
			   */
			   
/*                - - - - - - -                                                                   */
/***********************************************************************/

#include <GL/glut.h>

void MyDisplay() {
	float vertices[4][3] = { { 0.0,0.0,0.0 },{ 250.0,500.0,100.0 },{ 500.0,250.0,250.0 },{250.0,100.0,250.0} };
	// ���ü�� �� ������ ���� : ������ â�� ũ�⿡ �°� �����ߴ�.
	float p[3] = { 250.0, 100.0, 250.0 }; //������ ���� �ϳ� ����
	int i, j;//������ ���� ����
	glClear(GL_COLOR_BUFFER_BIT); // ���� ����
	for (j = 0; j < 50000; j++) {
		i = rand() % 4;
		// vertex�� 4���̹Ƿ� 0~2 ������ ���� �������� ����
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;
		p[2] = (p[2] + vertices[i][2]) / 2.0;
		// vertex�� ������ �� ������ ������ ���� ���
		glBegin(GL_POINTS);
		glVertex3fv(p);
		// ���� ���� ���
		glEnd();
	}
	glFlush();
}void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	// �� ��Ʈ ����
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500;
	// ���� ������ ũ�� ������ �°� ����
	glMatrixMode(GL_PROJECTION);
	// ��� ��带 ���� ��ȯ ���� ����
	glLoadIdentity();
	// �׵���� ����
	glOrtho(0.0*Widthfactor, 500.0*Widthfactor, 0.0*
		Heightfactor, 500.0*Heightfactor, 0.0, -250.0);
	// �������� ��ȯ �Լ� : ������ â�� ũ�Ⱑ ���ϴ� ������ �°� ������ȯ�� ����
}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0); // ���� ����������
	glMatrixMode(GL_PROJECTION); // ��� ��带 ���� ��ȯ ����
	glLoadIdentity(); // �׵���� ����
	glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, -250.0);
	// ������ â�� ũ�⿡ �°� ������ȯ
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); // openGL�� �����츦 ����
	glutInitDisplayMode(GLUT_RGB); // �������̸�� ���� : RGB ���� ���� ���
	glutInitWindowSize(500, 500); // ������ â ũ�� 500 x 500
	glutInitWindowPosition(0, 0); // ������â ���� ��ġ
	glutCreateWindow("3D Sierpinski Gasket"); // ������â ���� + Ÿ��Ʋ�� ����
	glutDisplayFunc(MyDisplay); // MyDisplay�Լ��� ������ ������ ���÷��̿� ���
	glutReshapeFunc(MyReshape); // Reshape �Լ� callback
	MyInit(); // MyInit�Լ� ���� : ������ȯ �Լ�
	glutMainLoop();
}