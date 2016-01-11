#include <stdio.h>

/* copies input to output, but replaces each run of one or more tabs/spaces
   with a single space */
main()
{
	int c;
	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t') {
			for(c = getchar();
					c == ' ' || c == '\t';
					c = getchar())
				;
			putchar(' ');
			if (c != EOF)
				putchar(c);
		} else
			putchar(c);	
}

