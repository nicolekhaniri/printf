#include <unistd.h>
#include <stdio.h>

int _printf(char *c);

int _printf(char *c) {
	int i;
	char n = '\n';
	int position = 0;

	for (i = 0; c[i] != '\0'; i++) {
		write(1, &c[i], 1);
		position = position + 1;
	}
	write(1, &n, 1);
	return (position);
}

int main (void) 
{
	_printf("Hello");
	return (0);
}
