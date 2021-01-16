#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>





void  ft_putchar(char c)
{
  write(1, &c, 1); 
}



int main(int argc, char **argv)
{	
	char *mas;	
	mas = "I n0t pid0r ";
	int i = 0;
	while (mas[i] != 0)
	{	
		ft_putchar (mas[i]) ;
		mas++;
	}
	 return (0);
}

