/***********************************************************************/
/*                           HW#2 : GL Modeling                                     */
/*  작성자 : 정하용                              날짜 : 2022년 9월 30일    */
/*                                                                                                 */
/* 문제 정의 :   GL modeling을 구현한다. 2D Primitives 구현한다.                                                                           */
/*                - - - - - - -                                                                   */
/* 기능 :  GL modeling를 구현하기 위해 각 정점들을 한 평면에 맞게 찍는다.
		   모양에 맞게 좌표를 설정한 뒤 크기에 맞게 좌표에 스칼라배를 하거나 적절한 위치를 찾아가기 위해
			평행이동까지 한 최종 좌표를 찍었다. 색상은 잘 보이게 빨간색을 사용했다.*/
		   /*                                 */
		   /***********************************************************************/

#include <GL/glut.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //컬러 버퍼 초기화
	glColor3f(1.0, 0.0, 0.0); //빨간색으로 설정
	
	//각 도형별 좌표
	glBegin(GL_POINTS); // 좌표에 점을 찍음
		glVertex3f(-8.0, 9.0, 0.0); glVertex3f(-9.0, 8.5, 0.0);
		glVertex3f(-9.0, 7.5, 0.0); glVertex3f(-8.0, 7.0, 0.0);
		glVertex3f(-7.0, 7.5, 0.0); glVertex3f(-7.0, 8.5, 0.0);
	glEnd();
	glBegin(GL_LINES); // 두 점사이를 잇는 선분 3개
		glVertex3f(-5.0, 9.0, 0.0); glVertex3f(-6.0, 8.5, 0.0);
		glVertex3f(-6.0, 7.5, 0.0); glVertex3f(-5.0, 7.0, 0.0);
		glVertex3f(-4.0, 7.5, 0.0); glVertex3f(-4.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP); //2개씩 묶은 선분을 하나의 선분으로 이음
		glVertex3f(-2.0, 9.0, 0.0); glVertex3f(-3.0, 8.5, 0.0);
		glVertex3f(-3.0, 7.5, 0.0); glVertex3f(-2.0, 7.0, 0.0);
		glVertex3f(-1.0, 7.5, 0.0); glVertex3f(-1.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP); // 좌표를 찍은 순서에 맞게 선분을 모두 이음
		glVertex3f(1.0, 9.0, 0.0); glVertex3f(0.0, 8.5, 0.0);
		glVertex3f(0.0, 7.5, 0.0); glVertex3f(1.0, 7.0, 0.0);
		glVertex3f(2.0, 7.5, 0.0); glVertex3f(2.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON); // 다각형, 속을 색으로 채움
		glVertex3f(4.0, 9.0, 0.0); glVertex3f(3.0, 8.5, 0.0);
		glVertex3f(3.0, 7.5, 0.0); glVertex3f(4.0, 7.0, 0.0);
		glVertex3f(5.0, 7.5, 0.0); glVertex3f(5.0, 8.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);	//3개의 정점으로 삼각형을 생성
		glVertex3f(-8.0, 6.0, 0.0); glVertex3f(-9.0, 5.5, 0.0);
		glVertex3f(-9.0, 4.5, 0.0); glVertex3f(-8.0, 4.0, 0.0);
		glVertex3f(-7.0, 4.5, 0.0); glVertex3f(-7.0, 5.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); //3개씩 묶어 삼각형을 만들어 연결
		glVertex3f(-4.0, 3.5, 0.0); glVertex3f(-4.5, 6.2, 0.0);
		glVertex3f(-5.0, 4.0, 0.0); glVertex3f(-5.5, 6.0, 0.0);
		glVertex3f(-6.0, 3.5, 0.0); glVertex3f(-6.5, 5.5, 0.0);
		glVertex3f(-7.0, 3.6, 0.0);
	glEnd();


	//여기서부터는 도형을 좌표평면을 활용해서 그리고 스칼라배를 통해 크기를 조정하고 평행이동으로 자리를 잡았다.
	glBegin(GL_TRIANGLE_FAN);  // 삼각형으로 부채꼴 모양을 표현
	glVertex3f(-3.0*2.0 + 3.0, 3.5*2.0 - 3.5, 0.0); glVertex3f(-1.5*2.0 + 3.0, 4.0*2.0 - 3.5, 0.0);
	glVertex3f(-1.7*2.0 + 3.0, 4.3*2.0 - 3.5, 0.0); glVertex3f(-2.0*2.0 + 3.0, 4.5*2.0 - 3.5, 0.0);
	glVertex3f(-2.2*2.0 + 3.0, 4.8*2.0 - 3.5, 0.0); glVertex3f(-2.5*2.0 + 3.0, 5.0*2.0 - 3.5, 0.0);
	glEnd();

	glBegin(GL_QUADS); // 4개의 꼭짓점으로 만든 다각형 : 사각형
	glVertex3f(5.2-4, 0.0+4, 0.0); glVertex3f(5.5-4, 1.0+4, 0.0);
	glVertex3f(6.0-4, 1.5+4, 0.0); glVertex3f(6.5-4, 1.0+4, 0.0);
	glVertex3f(6.7-4, 1.0+4, 0.0); glVertex3f(7.5-4, 1.5+4, 0.0);
	glVertex3f(8.0-4, 0.5+4, 0.0); glVertex3f(7.0-4, 0.0+4, 0.0);
	glEnd();

	glBegin(GL_QUAD_STRIP); // 4개씩 묶은 사각형으로 연결
	glVertex3f(0.0+8, 0.0+4, 0.0); glVertex3f(0.75*0.75+8, 2.0*0.75 + 4, 0.0);
	glVertex3f(-2.0*0.75+8, 0.0 + 4, 0.0); glVertex3f(-0.8*0.75+8, 2.8*0.75 + 4, 0.0);
	glVertex3f(-2.8*0.75+8, 1.6*0.75 + 4, 0.0); glVertex3f(-2.8*0.75+8, 4.0*0.75 + 4, 0.0);
	glVertex3f(-4.4*0.75+8, 2.8*0.75 + 4, 0.0); glVertex3f(-4.4*0.75+8, 3.6*0.75 + 4, 0.0);
	glEnd();
	

	glFlush();
	
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); //OS와 연결 및 초기화
	glutInitDisplayMode(GLUT_RGB); //디스플레이 모드를 RGB모드로
	glutInitWindowSize(500, 500); //윈도우 크기 설정
	glutInitWindowPosition(0, 0); //윈도우 시작 위치 설정
	glutCreateWindow("2D Primitive"); //윈도우 타이틀명 생성
	glClearColor(1.0, 1.0, 1.0, 1.0); //윈도우 바탕색 초기화 (흰색)
	glutDisplayFunc(MyDisplay); //객체들이 있는 MyDisplay 함수 호출
	glViewport(0, 0, 500, 500); // 뷰포트 설정 투영변환 함수
	glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영모드로
	glLoadIdentity(); // 항등행렬로 초기화
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // 직교투영으로 변환
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutMainLoop();
	
}