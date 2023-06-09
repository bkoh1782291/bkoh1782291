#include <stdio.h>
int main(void)
{
	float radius, area;

	printf("Enter the radius value:");
	scanf("%f", &radius);


	area = 3.1415926*(radius*radius);
	printf("The area of the circle is: %f\n", area);
	return 0;
}
