#include <stdio.h>

/* copies input to output, but replaces each tab with \t, eah backspace with \b
   and each \ with \\*/
main()
{
	int c;
	while ((c = getchar()) != EOF)
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else
			putchar(c);	
}

