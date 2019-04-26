#include<Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float matrix[1000][3];
void drawPoly(float a[][3], int n)
{
	glBegin(GL_POINTS);
	for (int i = 0;i < n;i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();
	glFlush();
}

void mul(int n, float trans[3][3])
{
	int i, j, k;
	float result[1000][3];
	// Multiply original coordinate matrix a [][] with transformation matrix trans[][] to get the resultant new coordinates
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < 3;j++)
		{
			result[i][j] = 0;
			for (k = 0;k < 3;k++)
			{
				result[i][j] = result[i][j] + (matrix[i][k] * trans[k][j]);
			}
		}
	}

	printf("\n Final coordinates are");
	for (i = 0;i < n;i++)
	{
		printf("\n");

		for (j = 0;j < 3;j++)
		{
			printf("%f  ", result[i][j]);
		}
	}
	drawPoly(result, n);

}

void scaling(int n, float sx, float sy)
{
	int i, j, xf = 0, yf = 0;
	float f[3][3] = { {0.0,0.0,0.0} ,{0.0,0.0,0.0}, {0.0,0.0,1.0} };
	// Initialize scaling matrix
	f[0][0] = sx;
	f[1][1] = sy;
	printf("\n Scaling Matrix is:");
	for (i = 0;i < 3;i++)
	{
		printf("\n");
		for (j = 0;j < 3;j++)
			printf("%f ", f[i][j]);
	}
	// call mul function
	mul(n, f);
	printf("\n");
}


void drawellipse(int rx, int ry, int xc, int yc)
{

	int count = 1;
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	matrix[0][0] = 0;   // X
	matrix[0][1] = ry;   // Y
	matrix[0][2] = 1;

	// Initial decision parameter of region 1 
	d1 = (ry * ry)
		- (rx * rx * ry)
		+ (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	// For region 1 
	while (dx < dy) {

		// Print points based on 4-way symmetry 
		printf("(%f, %f)\n", x + xc, y + yc);
		printf("(%f, %f)\n", -x + xc, y + yc);
		printf("(%f, %f)\n", x + xc, -y + yc);
		printf("(%f, %f)\n", -x + xc, -y + yc);

		matrix[count][0] = x + xc;
		matrix[count][1] = y + yc;
		matrix[count][2] = 1;
		++count;

		matrix[count][0] = -x + xc;
		matrix[count][1] = y + yc;
		matrix[count][2] = 1;
		++count;

		matrix[count][0] = x + xc;
		matrix[count][1] = -y + yc;
		matrix[count][2] = 1;
		++count;

		matrix[count][0] = -x + xc;
		matrix[count][1] = -y + yc;
		matrix[count][2] = 1;
		++count;



		// Checking and updating value of 
		// decision parameter based on algorithm 
		if (d1 < 0) {
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}

	// Decision parameter of region 2 
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
		+ ((rx * rx) * ((y - 1) * (y - 1)))
		- (rx * rx * ry * ry);

	// Plotting points of region 2 
	while (y >= 0) {

		// printing points based on 4-way symmetry 
		printf("(%f, %f)\n", x + xc, y + yc);
		printf("(%f, %f)\n", -x + xc, y + yc);
		printf("(%f, %f)\n", x + xc, -y + yc);
		printf("(%f, %f)\n", -x + xc, -y + yc);

		matrix[count][0] = x + xc;
		matrix[count][1] = y + yc;
		matrix[count][2] = 1;
		++count;

		matrix[count][0] = -x + xc;
		matrix[count][1] = y + yc;
		matrix[count][2] = 1;
		++count;

		matrix[count][0] = x + xc;
		matrix[count][1] = -y + yc;
		matrix[count][2] = 1;
		++count;

		matrix[count][0] = -x + xc;
		matrix[count][1] = -y + yc;
		matrix[count][2] = 1;
		++count;

		// Checking and updating parameter 
		// value based on algorithm 
		if (d2 > 0) {
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else {
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}

	drawPoly(matrix, count);
	scaling(count, 2, 2);
}

void disp()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	// call input function
	drawellipse(60, 30, 0, 0);
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Rotation...");
	gluOrtho2D(-300, 300, -300, 300);
	glutDisplayFunc(disp);
	glutMainLoop();

}