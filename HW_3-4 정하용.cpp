/***********************************************************************/
/*                           HW#3 : Menu Callback 응용                                 */
/*  작성자 : 정하용                              날짜 : 2022년 10월 7일    */
/*                                                                                                 */
/* 문제 정의 :   Menu callback 함수를 활용해 메뉴에 맞는 물체를 생성하고 크기및 색상을 정의한다 */
/*                - - - - - - -                                                                   */
/* 기능 :        생성할 물체의 이름을 메뉴로 만들고 각각의 메뉴의 서브메뉴로 크기를 설정할 수 있다.
				 메뉴의 색상을 선택하는 메뉴와 프로그램을 종료하는 메뉴까지 포함한다.
				 */
				 /*                - - - - - - -                                                                   */
				 /***********************************************************************/

#include <GL/glut.h>
// 어떤 물체를 생성할지 판단할 bool형 변수
GLboolean IsSphere = true; 
GLboolean IsSmall = true;
GLboolean IsTourus = true;

// 색상을 결정할 변수 생성 및 초기화
GLfloat color_R = 0.0;
GLfloat color_G = 0.5;
GLfloat color_B = 0.5;

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// 색상 변수로 물체의 색상 결정
	glColor3f(color_R, color_G, color_B);

	if ((!IsTourus) && (IsSphere) && (IsSmall)) // Sphere 이면서 small인 경우
		glutWireSphere(0.5, 30, 30);
	else if ((!IsTourus) && (IsSphere) && (!IsSmall)) // Sphere 이면서 Large인 경우
		glutWireSphere(0.7, 30, 30);
	else if ((!IsSphere) && (IsTourus) && (IsSmall)) // Tourus 이면서 small인 경우
		glutWireTorus(0.1, 0.3, 40, 20);
	else if ((!IsSphere) && (IsTourus) && (!IsSmall)) // Tourus 이면서 Large인 경우
		glutWireTorus(0.2, 0.5, 40, 20);
	else if ((!IsSphere) && (!IsTourus) && (IsSmall)) // Teapot 이면서 small인 경우
		glutWireTeapot(0.1);
	else //Teapo 이면서 Large인 경우
		glutWireTeapot(0.2);
	glFlush();
}
void MyMainMenu(int entryID) // MainMenu 함수 실행시 호출되는 함수
{
	if (entryID == 1) exit(0); // 인자값으로 1을 받으면 종료
	glutPostRedisplay();
}
void MySizeMenu_Sphere(int entryID) // Sphere을 선택했을 경우
{
	if (entryID == 1) // 인자값이 1일경우 small 크기로 생성
	{
		IsSphere = true;
		IsTourus = false;
		IsSmall = true;
	} 
	else if (entryID == 2) // 인자값이 2일경우 large 크기로 생성
	{
		IsSphere = true;
		IsTourus = false;
		IsSmall = false;
	}
	glutPostRedisplay();
}

void MySizeMenu_Torus(int entryID) // Tourus을 선택했을 경우
{
	if (entryID == 1) // 인자값을 1로 받을 경우 small크기로 생성
	{
		IsSphere = false;
		IsTourus = true;
		IsSmall = true;
	}
	else if (entryID == 2) // 인자값을 2로 받을 경우 large 크기로 생성
	{
		IsSphere = false;
		IsTourus = true;
		IsSmall = false;
	}
	glutPostRedisplay();
}

void MySizeMenu_Teapot(int entryID) // Teapot을 선택했을 경우
{
	if (entryID == 1) // 인자값이 1이면 small크기로
	{
		IsSphere = false;
		IsTourus = false;
		IsSmall = true;
	}
	else if (entryID == 2) // 인자값이 2이면 Large크기로
	{
		IsSphere = false;
		IsTourus = false;
		IsSmall = false;
	}
	glutPostRedisplay();
}

void MyChangeColor(int entryID) // Color을 선택했을 경우
{
	if (entryID == 1) // 인자값이 1인경우 색상을 붉은색
	{
		color_R = 1.0;
		color_G = 0.0;
		color_B = 0.0;
	}
	else if (entryID == 2) // 인자값이 2인경우 색상을 녹색
	{
		color_R = 0.0;
		color_G = 1.0;
		color_B = 0.0;
	}
	else if (entryID == 3) // 인자값이 3인경우 색상을 파란색
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
	// Sphere 메뉴 생성 및 sub 메뉴 연결
	GLint MySizeID_Sphere = glutCreateMenu(MySizeMenu_Sphere);
	glutAddMenuEntry("Small Sphere", 1);
	glutAddMenuEntry("Large Sphere", 2);
	// Torus 메뉴 생성 및 sub 메뉴 연결
	GLint MySizeID_Torus = glutCreateMenu(MySizeMenu_Torus);
	glutAddMenuEntry("Small Torus", 1);
	glutAddMenuEntry("Large Torus", 2);
	// Teapot 메뉴 생성 및 sub 메뉴 연결
	GLint MySizeID_Teapot = glutCreateMenu(MySizeMenu_Teapot);
	glutAddMenuEntry("Small Teapot", 1);
	glutAddMenuEntry("Large Teapot", 2);
	// Color 메뉴 생성 및 sub 메뉴 연결
	GLint MyColorID = glutCreateMenu(MyChangeColor);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	// Main메뉴 생성 및 각각의 sub메뉴를 모두 연결
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