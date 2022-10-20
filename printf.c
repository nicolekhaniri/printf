#include <unistd.h>

int _printf(char *c);

int _printf(char *c) {
	int i;

	for (i = 0; c[i] != '\0'; i++) {
		write(1, &c[i], 1);
	}
	return (0);
}

int main (void) {
	_printf("Apple");
	_printf("\n");
}
