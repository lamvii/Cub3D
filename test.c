#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float lint1(float a, float b, float f)
{
	return (a * (1.0f - f)) + (b * f);
}

float lint2(float a, float b, float f)
{
	return a + f * (b - a);
}

int main()
{
	const float a = 1.0e20;
	const float b = 1.0;
	int n;

	float p1 = lint1(0, 1, 1);
	float p2 = lint2(0, 1, 1);
	printf("x: %f, y: %f\n", p1, p2);
	return 0;
}
