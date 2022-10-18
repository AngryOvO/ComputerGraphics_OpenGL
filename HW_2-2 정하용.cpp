/***********************************************************************/
/*                           HW#2 : GLU Modeling                                     */
/*  작성자 : 정하용                              날짜 : 2022년 9월 30일    */
/*                                                                                                 */
/* 문제 정의 :   GLU modeling을 구현한다. 3D Primitives 구현한다. : Sphere, Cylinder, Disk, PatialDisk                                                                           */
/*                - - - - - - -                                                                   */
/* 기능 :  디스플레이 리스트를 활용해 3D 공간에서 객체를 생성한다.
		   광원, 조명에 관련된 함수들을 활용해 객체가 조명의 위치에 따라 어떻게 다르게 보이는지 확인했다.*/
/*                - - - - - - -                                                                   */
/***********************************************************************/


#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

GLuint listA, listB, listC, listD; // 디스플레이 리스트 생성
GLUquadricObj* qobj = gluNewQuadric(); // 새로운 Quadric 객체 생성

void MyCreateList()
{
	listA = glGenLists(4); //glGenLists 함수를 이용해서 사용하지 않은 ID값 반환
	// 한번에 네개의 리스트 ID 할당
	listB = listA + 1; 
	listC = listB + 1;
	listD = listC + 1;

	glNewList(listA, GL_COMPILE); // 리스트A 생성 , 바로 실행하지 않고 컴파일과정만 진행
	gluQuadricDrawStyle(qobj, GLU_FILL); // DrawStyle을 Solid 형태로 설정
	gluSphere(qobj, 1.0, 50, 50); // 반지름 1.0, subdivision을 모두 50으로 설정한 구
	glTranslatef(-2, -2, 2); // 평행이동
	glEndList();

	glNewList(listB, GL_COMPILE); // 리스트B 생성
	gluQuadricDrawStyle(qobj, GLU_LINE); // DrawStyle을 Wire-frame 으로 설정
	gluCylinder(qobj, 1.0, 0.5, 2.0, 8, 8); // 바닥면의 반지름 1.0, 위쪽 면의 반지름 0.5인 원기둥
	glTranslatef(4, 4, 0); // 평행이동
	glEndList();

	glNewList(listC, GL_COMPILE); // 리스트C 생성
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE); // 외부 모서리만 모델링하는 DrawStyle 사용
	gluDisk(qobj, 0.5, 1, 20, 1); // 안쪽 반지름 0.5 바깥 반지름 0.1인 디스크
	glTranslatef(-2, 2, 0); // 평행이동
	glEndList();

	glNewList(listD, GL_COMPILE); // 리스트D 생성
	gluQuadricDrawStyle(qobj, GLU_POINT); // 점으로 모델링
	gluPartialDisk(qobj, 0.3, 1.0, 26, 13, 0, 90); //  안쪽 반지름 0.3 바깥쪽 반지름 1.0 각도 90도의 잘린 disk모양
	glTranslatef(2, -2, 0); // 평행이동
	glEndList();
}

void MyInit(void)
{
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; // 주변광 설정
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 반사광 설정
	GLfloat mat_shininess[] = { 50.0 }; //선명도
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // 조명의 위치
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0); //배경색 검은색으로


	//조명 모델에 따른 재질 설정
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//조명 성질 설정
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

	// 조명 켜기
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0); 
	glEnable(GL_DEPTH_TEST);
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //컬러 버퍼& 깊이 버퍼를 초기화

	glMatrixMode(GL_MODELVIEW); // 행렬 모드를 모델뷰로
	glLoadIdentity(); //항등행렬로 초기화 

	glViewport(0, 0, 500, 500); // 뷰폿 설정 : 투영변환 함수 호출
	gluLookAt(0.0, 0.0, 0.0, 0.0, 1.0, -1.0, 0.0, 1.0, 0.0);  // 카메라 위치 설정

	glEnable(GL_LIGHTING); // 조명 켜기
	glShadeModel(GL_SMOOTH); // 각 정점의 색상을 부드럽게 연결하여 채색
	
	gluQuadricNormals(qobj, GLU_SMOOTH); //객체의 모서리를 부드럽게
	gluQuadricOrientation(qobj, GLU_OUTSIDE); 
	gluQuadricTexture(qobj, GL_FALSE);

	//디스플레이 리스트 호출
	glCallList(listA);
	glCallList(listB);
	glCallList(listC);
	glCallList(listD);

	glutSwapBuffers(); // 프레임 버퍼 교환
}

void Reshape(int width, int height) //reshape 함수 
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); 

	glMatrixMode(GL_PROJECTION); //행렬 모드를 투영행렬로
	glLoadIdentity(); //항등행렬로 초기화

	glOrtho(-5.0, 5.0, -5.0*((GLfloat)height/(GLfloat)width), 5.0*((GLfloat)height/(GLfloat)height), -5.0, 5.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //디스플레이 모드 설정
	glutInitWindowSize(500, 500); //윈도우 크기 500,500
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3D Primitives");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); //직교투영 변환 

	MyInit();
	glutDisplayFunc(MyDisplay); //Display Callback
	glutReshapeFunc(Reshape); // Reshape Callback
	MyCreateList(); 

	glutMainLoop(); 
	gluDeleteQuadric(qobj); //동적할당 받음 Quadric 할당 해제
}