/***********************************************************************/
/*                           HW#1 : 3D Sierpinski Gasket                                     */
/*  작성자 : 정하용                              날짜 : 2022년 9월 20일    */
/*                                                                                                 */
/* 문제 정의 :  2D로 구현한 Sierpinski Gasket을 3D형태로 구현하는 과제이다.
				Reshape callback 함수를 사용해 윈도우 창의 크기를 변경시켜도
				객체가 기존의 비율을 유지하도록 한다.*/
/*                - - - - - - -                                                                   */
/* 기능 :      기존 2D에서는 삼각형 모양이였으므로 정점을 세개 찍었으나 3D에선 사면체이므로 정점을 네개 찍는다.
			   3차원 공간이므로 좌표축을 세개 사용하므로 [4][3]크기의 2차원배열을 사용한다.
			   좌표축을 세개 사용하면서 기존 임의의 점의 좌표 또한 3차원으로 설정하고,
			   찍힌 점과 임의의 정점과의 중점을 계산해 반복한다.
			   */
			   
/*                - - - - - - -                                                                   */
/***********************************************************************/

#include <GL/glut.h>

void MyDisplay() {
	float vertices[4][3] = { { 0.0,0.0,0.0 },{ 250.0,500.0,100.0 },{ 500.0,250.0,250.0 },{250.0,100.0,250.0} };
	// 사면체의 각 정점을 설정 : 윈도우 창의 크기에 맞게 설정했다.
	float p[3] = { 250.0, 100.0, 250.0 }; //임의의 점을 하나 설정
	int i, j;//루프를 위한 변수
	glClear(GL_COLOR_BUFFER_BIT); // 버퍼 제거
	for (j = 0; j < 50000; j++) {
		i = rand() % 4;
		// vertex가 4개이므로 0~2 사이의 숫자 랜덤으로 선택
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;
		p[2] = (p[2] + vertices[i][2]) / 2.0;
		// vertex와 임의의 점 사이의 중점을 새로 계산
		glBegin(GL_POINTS);
		glVertex3fv(p);
		// 계산된 점을 출력
		glEnd();
	}
	glFlush();
}void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	// 뷰 포트 설정
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500;
	// 시작 윈도우 크기 비율에 맞게 설정
	glMatrixMode(GL_PROJECTION);
	// 행렬 모드를 투영 변환 모드로 설정
	glLoadIdentity();
	// 항등행렬 생성
	glOrtho(0.0*Widthfactor, 500.0*Widthfactor, 0.0*
		Heightfactor, 500.0*Heightfactor, 0.0, -250.0);
	// 직교투영 변환 함수 : 윈도우 창의 크기가 변하는 비율에 맞게 투영변환도 맞춤
}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0); // 색상 붉은색으로
	glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영 변환 모드로
	glLoadIdentity(); // 항등행렬 생성
	glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, -250.0);
	// 윈도우 창의 크기에 맞게 투영변환
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); // openGL과 윈도우를 연결
	glutInitDisplayMode(GLUT_RGB); // 디스프레이모드 설정 : RGB 색상 모델을 사용
	glutInitWindowSize(500, 500); // 윈도우 창 크기 500 x 500
	glutInitWindowPosition(0, 0); // 윈도우창 시작 위치
	glutCreateWindow("3D Sierpinski Gasket"); // 윈도우창 생성 + 타이틀명 설정
	glutDisplayFunc(MyDisplay); // MyDisplay함수를 가져와 윈도우 디스플레이에 띄움
	glutReshapeFunc(MyReshape); // Reshape 함수 callback
	MyInit(); // MyInit함수 실행 : 투영변환 함수
	glutMainLoop();
}