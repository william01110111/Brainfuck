#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	p[1] = 8;
	
	p += 1;
	
	while(*p)
	{
		p[-1] = (9 + p[-1]);
		p[0] = (-1 + p[0]);
	}
	
	putchar(p[-1]);
	p[-1] = p[-1];
	p[1] = (1 + p[1]);
	p[2] = (-1 + p[2]);
	
	p += 2;
	
	while(*p)
	{
		p[0] = (1 + p[0]);
	}
	
	p[0] = (2 + p[0]);
	p[1] = (2 + p[1]);
	p[2] = (3 + p[2]);
	
	p += 2;
	
	while(*p)
	{
		
		p += 1;
		
		while(*p)
		{
			p[-1] = (3 + p[-1]);
			p[0] = (-1 + p[0]);
			p[1] = (3 + p[1]);
		}
		
		
		p += -2;
	}
	
	putchar((-5 + p[1]));
	putchar((3 + p[3]));
	putchar((3 + p[3]));
	putchar((6 + p[3]));
	putchar((-1 + p[4]));
	p[1] = (-5 + p[1]);
	p[2] = p[2];
	p[3] = (6 + p[3]);
	p[4] = (-1 + p[4]);
	
	p += 2;
	
	while(*p)
	{
		
		p += 1;
		
		while(*p)
		{
			p[0] = (1 + p[0]);
			p[1] = (1 + p[1]);
			
			p += 1;
		}
		
		
		p += 2;
	}
	
	putchar((-14 + p[-1]));
	putchar(p[1]);
	putchar((3 + p[1]));
	putchar((-3 + p[1]));
	putchar((-11 + p[1]));
	putchar((1 + p[2]));
	putchar((1 + p[3]));
	p[-1] = (-14 + p[-1]);
	p[1] = (-11 + p[1]);
	p[2] = (1 + p[2]);
	p[3] = (1 + p[3]);
	
	p += 3;
}
