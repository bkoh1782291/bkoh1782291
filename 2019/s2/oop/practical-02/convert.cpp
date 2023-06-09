#include <iostream>
extern int array(int number);

int main()
{
	int number=74;
	int number1=23;
	int number2=134;

	int value;
	value = array(number);
	value = array(number1);
	value = array(number2);

	return 0;

}