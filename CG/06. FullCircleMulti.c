#include <GL/GLU.h>
#include <GL/gl.h>
#include <Windows.h>
#include <gl/glut.h>

#include <math.h>
#include <stdio.h>

void MatrixMultiply(float left[][3], float right[3][3], float result[][3], int leftRows)
{
   // Left has 3 Cols
   // Right has 3 Rows and 3 Cols
   for (int rL = 0; rL < leftRows; ++rL)
   {
      for (int cR = 0; cR < 3; ++cR)
      {
         result[rL][cR] = 0;
         for (int cLrR = 0; cLrR < 3; ++cLrR)
         {
            result[rL][cR] += left[rL][cLrR] * right[cLrR][cR];
         }
      }
   }
}

void Translate(float points[][3], int countPoints, float tx, float ty, float result[][3])
{
   float translationMatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};
   MatrixMultiply(points, translationMatrix, result, countPoints);
}
float DegreeToRadian(float angle)
{
   return (angle / 180.0) * 3.14159;
}
void Rotate(float points[][3], int countPoints, double angle, float result[][3])
{
   angle = DegreeToRadian(angle);
   float rotationMatrix[3][3] = {{cos(angle), sin(angle), 0}, {-sin(angle), cos(angle), 0}, {0, 0, 1}};
   MatrixMultiply(points, rotationMatrix, result, countPoints);
}

void FullCircle(int r, int xc, int yc, int angle)
{
   float matrix[1000][3];

   int count = 1;

   // Approx 5/4 = 1
   int decision = 1 - r;
   int x = 0;
   int y = r;

   // First Point
   matrix[0][0] = 0; // X
   matrix[0][1] = r; // Y
   matrix[0][2] = 1;

   while (x <= y)
   {
      if (decision < 0)
      {
         decision = decision + 2 * x + 3;
         x = x + 1;
         y = y;
      }
      else
      {
         decision = decision + 2 * x - 2 * y + 5;
         x = x + 1;
         y = y - 1;
      }
      matrix[count][0] = x;
      matrix[count][1] = y;
      matrix[count][2] = 1;
      ++count;
      matrix[count][0] = y;
      matrix[count][1] = x;
      matrix[count][2] = 1;
      ++count;
      matrix[count][0] = -x;
      matrix[count][1] = y;
      matrix[count][2] = 1;
      ++count;
      matrix[count][0] = -y;
      matrix[count][1] = x;
      matrix[count][2] = 1;
      ++count;

      matrix[count][0] = -x;
      matrix[count][1] = -y;
      matrix[count][2] = 1;
      ++count;
      matrix[count][0] = -y;
      matrix[count][1] = -x;
      matrix[count][2] = 1;
      ++count;
      matrix[count][0] = x;
      matrix[count][1] = -y;
      matrix[count][2] = 1;
      ++count;
      matrix[count][0] = y;
      matrix[count][1] = -x;
      matrix[count][2] = 1;
      ++count;
   }

   float result[300][3];
   Rotate(matrix, count, angle, result);
   for (int i = 0; i < count; ++i)
      for (int j = 0; j < 3; ++j)
         matrix[i][j] = result[i][j];
   Translate(matrix, count, xc, yc, result);

   // Use pixel plotting in glBegin and glEnd
   glBegin(GL_POINTS);
   for (int i = 0; i < count; ++i)
   {
      glVertex2f(result[i][0] /*X*/, result[i][1] /*Y*/);
   }
   // glVertex2f(x,y); //Sample for ploting pixel at (x,y)
   glEnd();
}
void DrawPattern(int x0, int y0, int radius)
{
   // Draw RightMost Circle
   FullCircle(radius, x0, y0, 0);
   // As we can see, they form an Equilateral Triangle
   // Hence Upper Circle is at 60 degrees up
   FullCircle(radius, x0 + (2 * radius * cosf(DegreeToRadian(60))), y0 + (2 * radius * sinf(DegreeToRadian(60))), 0);
   // Same Height
   // Just 2 Radius Away Centre
   FullCircle(radius, x0 + 2 * radius, y0, 0);
}
void disp()
{
   glClearColor(1, 1, 1, 1);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0, 0, 0);
   // call your function define at beginning
   // for example WriteFunctionName();
   DrawPattern(-60, 0, 40);
   glFlush();
} // disp
int main(int argv, char** argc)
{
   glutInit(&argv, argc);
   glutInitWindowSize(450, 450);
   glutCreateWindow("window");
   gluOrtho2D(-150, 300, -150, 300);
   glutDisplayFunc(disp);
   glutMainLoop();
   return 0;
}