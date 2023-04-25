#include <GL/gl.h>				// Подключаем библиотеки
#include <GL/glu.h>
#include <GL/glut.h>				// Добавляет объёмные фигуры

GLfloat angle, angle2;
int moving, startx, starty;

void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        moving = 1;
        startx = x;
        starty = y;
    }
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        moving = 0;
    }
}

void motion(int x, int y)
{
    if (moving)
    {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}


void display(void) {
GLfloat lp[4] = {0.2, 0.1, 0.0, 1};     	// x,y,z лампочки // Массив координат лампочки
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);	// Очистка буфера от старых значений в каждом кадре
glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);	// Переключение между односторонней и двухсторонней моделями освещения
glEnable(GL_DEPTH_TEST);			// Разрешить работу Z-буфера
glLightfv(GL_LIGHT0, GL_POSITION, lp);  	// Загрузить x,y,z // Загрузка массива лампочек
glEnable(GL_LIGHT0);				// Разрешение освещения от 0-й лампочки
glEnable(GL_LIGHTING);				// Разрешить работу лампочки
glEnable(GL_COLOR_MATERIAL);			// Разрешить цветное освещение
glEnable(GL_NORMALIZE);				// Приведение нормалей к единичной длине

GLUquadricObj* QuadrObj;
QuadrObj=gluNewQuadric();

 glLoadIdentity();				// Голова
 glRotatef(angle, 1, 0, 0);
 glPushMatrix();
 glTranslatef (0.0,0.5,0.0);			
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.1,0.1,0.4,30,30);
 glPopMatrix();
 
 glLoadIdentity();				// Глаз правый
 glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.04,0.4,-0.07);
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.0, 1.0, 0.0);			
 glutSolidSphere(0.03, 30, 30);
 glPopMatrix();			
 
  glLoadIdentity();				// Глаз левый
  glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
  glPushMatrix();
 glTranslatef (-0.04,0.4,-0.07);
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.0, 1.0, 0.0);			
 glutSolidSphere(0.03, 30, 30);
 glPopMatrix();			

 glLoadIdentity();				// Тело дровосека
 glRotatef(angle, 1, 0, 0);
 glPushMatrix();
 glTranslatef (0.0,0.3,0.0);		
 glRotatef(90.0,1.0,0.0,0.0);			// X Y Z
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.15,0.15,0.55,30,30);//Второй и третий параметры задают радиусы оснований, четвертый  высоту, последние два-число разбиений вокруг и вдоль оси z
 glPopMatrix();

 glLoadIdentity();				// Правая рука
 glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.15,0.25,0.0);
 glRotatef(90.0,0.0,1.0,0.0);
 glRotatef(30.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.07,0.05,0.25,30,30);
  glPopMatrix();
 
  glLoadIdentity();				// Левая рука
   glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.15,0.25,0.0);
 glRotatef(-90.0,0.0,1.0,0.0);
 glRotatef(45.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.07,0.05,0.25,30,30);
  glPopMatrix();
 
   glLoadIdentity();				// Рот
    glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.0,0.35,-0.1);
 glRotatef(0.0,0.0,1.0,0.0);
 glRotatef(0.0,1.0,0.0,0.0);
 glColor3f(0.8f, 0.1f, 0.1f);
 glutSolidTorus(0.005, 0.02, 20, 20);
 glPopMatrix();
 
  glLoadIdentity();				// Правое бедро
  glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.15,-0.2,0.0);
 glRotatef(90.0,0.0,1.0,0.0);
 glRotatef(60.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.07,0.05,0.25,30,30);
 glPopMatrix();
 
  glLoadIdentity();				// Левое бедро
    glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.15,-0.2,0.0);
 glRotatef(-90.0,0.0,1.0,0.0);
 glRotatef(60.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.07,0.05,0.25,30,30);
 glPopMatrix();
 
  glLoadIdentity();				// Левый тазобедренный
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.15,-0.2,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.1, 30, 30);	
 glPopMatrix();		
 
  glLoadIdentity();				// Правый тазобедренный 
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.15,-0.2,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.1, 30, 30);	
 glPopMatrix();
 
   glLoadIdentity();				// Левое плечо
       glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.15,0.25,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.08, 30, 30);	
 glPopMatrix();		
 
  glLoadIdentity();				// Правое плечо
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.15,0.25,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.08, 30, 30);	
 glPopMatrix();		
 
 glLoadIdentity();				// Левый локоть
     glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.34,0.065,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.05, 30, 30);	
 glPopMatrix();		
 
  glLoadIdentity();				// Правый локоть
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.37,0.125,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.05, 30, 30);	
 glPopMatrix();
 
 glLoadIdentity();				// Левое предплечье
     glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.345,0.06,0.0);
 glRotatef(-90.0,0.0,1.0,0.0);
 glRotatef(30.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.05,0.033,0.20,30,30);
 glPopMatrix();
 
 glLoadIdentity();				// Правое предплечье
     glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.377,0.12,0.0);
 glRotatef(90.0,0.0,1.0,0.0);
 glRotatef(15.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.05,0.033,0.20,30,30);
 glPopMatrix();
 
   glLoadIdentity();				// Левое колено
       glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.27,-0.4,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.055, 30, 30);
 glPopMatrix();			
 
  glLoadIdentity();				// Правое колено 
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.26,-0.4,0.0);
 glColor3f(0.2f, 0.25f, 0.3f);			
 glutSolidSphere(0.055, 30, 30);
 glPopMatrix();
 
   glLoadIdentity();				// Правое бедро
       glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.26,-0.4,0.0);
 glRotatef(90.0,0.0,1.0,0.0);
 glRotatef(75.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.05,0.033,0.25,30,30);
 glPopMatrix();
 
  glLoadIdentity();				// Левое бедро
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.27,-0.4,0.0);
 glRotatef(-90.0,0.0,1.0,0.0);
 glRotatef(75.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.05,0.033,0.25,30,30);
 glPopMatrix();
 
    glLoadIdentity();				// Правая ступня
        glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.3,-0.65,0.0);
 glRotatef(90.0,0.0,1.0,0.0);
 glRotatef(0.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.033,0.020,0.13,30,30);
 glPopMatrix();
 
  glLoadIdentity();				// Левая ступня
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (-0.3,-0.65,0.0);
 glRotatef(-90.0,0.0,1.0,0.0);
 glRotatef(0.0,1.0,0.0,0.0);
 glColor3f(0.2f, 0.35f, 0.4f);
 gluCylinder(QuadrObj,0.033,0.020,0.13,30,30);	
 glPopMatrix();
 
  glLoadIdentity();				// Топорище
      glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.52,0.0,-0.02);
 glRotatef(90.0,0.0,1.0,0.0);
 glRotatef(-80.0,1.0,0.0,0.0);
 glColor3f(0.3f, 0.2f, 0.0f);
 gluCylinder(QuadrObj,0.01,0.01,0.4,30,30);
 glPopMatrix();	
 
   glLoadIdentity();				// Голова топора
       glRotatef(angle, 1, 0, 0);
 glRotatef(angle2, 0, 1, 0);
 glPushMatrix();
 glTranslatef (0.57,0.32,0.0);
 glRotatef(90.0,0.0,1.0,0.0);
 glRotatef(10.0,1.0,0.0,0.0);
 glColor3f(0.8f, 0.8f, 0.8f);
 //gluCylinder(QuadrObj,0.1,0.08,0.2,30,30);
 glPopMatrix();
 
 	glBegin(GL_POLYGON);
 glVertex3f( 0.54f, 0.12f, -0.03f);
 glVertex3f( 0.57f, 0.35f, 0.0f);
 glVertex3f( 0.9f, 0.14f, 0.0f); 
 glVertex3f( 0.9f, 0.03f, 0.0f);
 glEnd();
    

glutSwapBuffers();	//По умолчанию все объекты строятся в Z-буфере, а не в буфере фрейма. Поэтому для вывода изображения на экран нужно поменять местами эти два буфера при помощи функции glutSwapBuffers().
glFlush();		//Так же вместо обмена можно просто принудительно скопировать текущее содержимое Z-буфера в буфер фрейма при помощи glFlush() или glFinish().
}

void reshape(int w, int h) // Изменение размера окна
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main (int argc, char** argv) {
glutInit (&argc, argv);						// Инициализация GLUT
glutReshapeFunc(reshape);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	// Режимы
glutInitWindowPosition (1000, 50);				// Позиция окна
glutInitWindowSize (800, 800);					// Размер окна
glutCreateWindow ("My iron woodcutter with an ax");		// Отображение окна
glClearColor (.2, 0.2, 0.1, 0.);				// Цвет фона  // Коричневый
glutDisplayFunc(display);					// Установка функции рисования изображения
glutMouseFunc(mouse);
glutMotionFunc(motion);
glutMainLoop ();						// Цикл выборки сообщений между glut и системой
}


