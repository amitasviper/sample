#include <stdio.h>
#include <unistd.h>
void delay(int num);
int main()
{
FILE *l1,*l2,*l3,*l4;

l1 = fopen("/sys/class/gpio/gpio31/value", "r+");
l2 = fopen("/sys/class/gpio/gpio50/value", "r+");
l3 = fopen("/sys/class/gpio/gpio30/value", "r+");
l4 = fopen("/sys/class/gpio/gpio60/value", "r+");

while(1)
{
		 fwrite("1", sizeof(char), 1, l1);
		 fwrite("0", sizeof(char), 1, l2);
		 fwrite("0", sizeof(char), 1, l3);
		 fwrite("0", sizeof(char), 1, l4);
		 fflush(l1);
		 fflush(l2);
		 fflush(l3);
		 fflush(l4);
		 delay(100000);

		 fwrite("0", sizeof(char), 1, l1);
		 fwrite("1", sizeof(char), 1, l2);
		 fwrite("0", sizeof(char), 1, l3);
		 fwrite("0", sizeof(char), 1, l4);
		 fflush(l1);
		 fflush(l2);
		 fflush(l3);
		 fflush(l4);
		 delay(100000);

		 fwrite("0", sizeof(char), 1, l1);
		 fwrite("0", sizeof(char), 1, l2);
		 fwrite("1", sizeof(char), 1, l3);
		 fwrite("0", sizeof(char), 1, l4);
		 fflush(l1);
		 fflush(l2);
		 fflush(l3);
		 fflush(l4);
		 delay(100000);

		 fwrite("0", sizeof(char), 1, l1);
		 fwrite("0", sizeof(char), 1, l2);
		 fwrite("0", sizeof(char), 1, l3);
		 fwrite("1", sizeof(char), 1, l4);
		 fflush(l1);
		 fflush(l2);
		 fflush(l3);
		 fflush(l4);
	 	 delay(100000);

 }
fclose(l1);
fclose(l2);
fclose(l3);
fclose(l4);
}

void delay(int num)
{
	int i,j;
	for(i=0;i<num;i++)
		for(j=0;j<1275;j++);
}
