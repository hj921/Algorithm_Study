#include <stdio.h>

char Data[5] = { 'A', 'B', 'D', 'E' };
char c;

void main() {
	int i, temp, temp2;
	c = 'C';

	for (i = 0; i < 5; i++) {
		printf("%2c", Data[i]);
	}
	printf("\n");

	for (i = 0; i < 5; i++) {
		if (Data[i] > c)
			break;
	}

	temp = Data[i];
	printf("i = %d, %2c\n", i, Data[i]); // D
	Data[i] = c;
	printf("i = %d, %2c\n", i, Data[i]); // C
	i++;
	printf("i = %d, %2c\n", i, Data[i]);

	for (; i < 5; i++) { // 3, 4
		printf("i = %d, %2c\n", i, Data[i]);
		temp2 = Data[i];
		Data[i] = temp;
		temp = temp2;
	}

	for (i = 0; i < 5; i++) {
		printf("%2c", Data[i]);
	}
}