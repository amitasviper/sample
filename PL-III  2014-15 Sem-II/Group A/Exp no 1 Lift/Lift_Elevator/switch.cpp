#include <iostream>
#include <stdio.h>
#include <unistd.h>
 using namespace std;

FILE *Achar = NULL;
FILE *Bchar = NULL;
FILE *Cchar = NULL;
FILE *Dchar = NULL;
FILE *Echar = NULL;
FILE *Fchar = NULL;
FILE *Gchar = NULL;
FILE *DPchar = NULL;
FILE *LR4 = fopen("/sys/class/gpio/gpio30/value","r+");
FILE *LG4 = fopen("/sys/class/gpio/gpio60/value","r+");
FILE *LR3 = fopen("/sys/class/gpio/gpio31/value","r+");
FILE *LG3 = fopen("/sys/class/gpio/gpio50/value","r+");
FILE *LR2 = fopen("/sys/class/gpio/gpio48/value","r+");
FILE *LG2 = fopen("/sys/class/gpio/gpio51/value","r+");
FILE *LR1 = fopen("/sys/class/gpio/gpio49/value","r+");
FILE *LG1 = fopen("/sys/class/gpio/gpio15/value","r+");


const char *seg1="/sys/class/gpio/gpio45/value";	//A
const char *seg2="/sys/class/gpio/gpio44/value";	//B
const char *seg3="/sys/class/gpio/gpio23/value";	//C
const char *seg4="/sys/class/gpio/gpio26/value";	//D
const char *seg5="/sys/class/gpio/gpio47/value";	//E
const char *seg6="/sys/class/gpio/gpio46/value";	//F
const char *seg7="/sys/class/gpio/gpio27/value";	//G
const char *seg8="/sys/class/gpio/gpio65/value";	//DP

unsigned char disp(int val);
void led(int m,int ch);

int main(void)
{
 FILE *SW1,*SW2,*SW3,*SW4;
 int value,value1,value2,value3,chan=0;
 int var9,var4,var7,var8,var3,var5,p=1,var6=0,var2=0,var1=0;
	while(1)
	{
    SW1 = fopen("/sys/class/gpio/gpio68/value","r");
		SW2 = fopen("/sys/class/gpio/gpio67/value","r");
		SW3 = fopen("/sys/class/gpio/gpio69/value","r");
		SW4 = fopen("/sys/class/gpio/gpio66/value","r");
	  fscanf(SW1,"%d",&value);
		printf("value=%d",value);
		fscanf(SW2,"%d",&value1);
		printf("value1=%d",value1);
		fscanf(SW3,"%d",&value2);
		printf("value2=%d",value2);
		fscanf(SW4,"%d",&value3);
		printf("value3=%d\n",value3);
		fflush(SW1);
		fflush(SW2);
		fflush(SW3);
		fflush(SW4);
    if(value==0 & var1==0)
    {	
			chan=0;
			disp(chan);
			if(var6==1)
				led(4,0);
			else
				led(0,0);
			var2=0;
			var1=var4=var5=var3=1;
			var7=var8=var9=1;
			var6=0;		//0-1 
			p=1;
    }
		else
		if(value1==0 & var6==0)
		{
			chan=1;
			disp(chan);
			if(var3==1 & p==0)
				led(4,1);
			else
				led(0,1);
			var1=0;		//1-0
			var3=0;		//1-2
			var6=var5=1;
			var7=0;		//1-3
			p=0;
		}
		else
		if(value2==0 & var3==0)
		{
			chan=2;
			disp(chan);
			if(var5==1 & p==1)
				led(4,2);
			else
				led(0,2);
			var1=1;
			var3=1;
			var6=0;		//2-1
			var5=0;		//2-3
			var4=0;		//2-0
			p=0;
		}
		else
		if(value3==0 & var5==0)
		{
			chan=3;
			disp(chan);
			led(0,3);
			var1=1;
			var3=0;		//3-2
			var6=var5=var4=1;

			var9=0;		//3-0
			var8=0;		//3-1
			p=1;
			
		}
		else
		if(value2==0 & var2==0)
		{
			chan=1;
			disp(chan);
			led(0,1);
			chan=2;
			disp(chan);
			led(0,2);
			var4=0;		//2-0
			var2=1;
			var1=1;
			var5=0;
			var6=0;
			var3=1;//
			p=0;
		}
		else 
		if(value==0 & var4==0)
		{
			led(4,2);
			chan=1;
			disp(chan);
			led(4,1);
			chan=0;
			disp(chan);
			led(4,0);
			var2=0;		//0-2,0-3
			var1=var3=var5=var3=1;
			var7=var8=var9=1;
			var6=0;
			p=1;
		}
		else 
		if(value3==0 & var2==0)
		{
			chan=1;
			disp(chan);
			led(0,1);
			chan=2;
			disp(chan);
			led(0,2);
			chan=3;
			disp(3);
			led(0,3);
				
			var1=var6=var2=var5=var4=1;
			var8=0;		//3-1
			var9=0;
			var3=0;
		}
		else
		if(value==0 & var9==0)
		{
			led(4,3);
			chan=2;
			disp(chan);
			led(4,2);
			chan=1;
			disp(chan);
			led(4,1);
			chan=0;
			disp(chan);
			led(4,0);
			
			var1=var9=var3=var5=1;
			var2=0;		//0-2,0-3
			var6=0;
			p=1;
		}
		else
		if(value3==0 & var7==0)
		{
			led(0,1);
			chan=2;
			disp(chan);
			led(0,2);
			chan=3;
			disp(chan);
			led(0,3);
			var3=0;		
			var8=0;
			var9=0;
			var5=1;//
			var1=var7=1;
		}
		else 
		if(value1==0 & var8==0)
		{
			led(4,3);
			chan=2;
			disp(chan);
			led(4,2);
			chan=1;
			disp(chan);
			led(4,1);
			var1=0;
			var3=0;
			var7=0;
			var8=1;
			var5=1;//
		}
		fclose(SW1);
		fclose(SW2);
		fclose(SW3);
		fclose(SW4);
		}
}

unsigned char disp(int val)
{
	
	switch(val)
	{
		case 0:usleep(1000000);
			 if(
            ((Achar=fopen(seg1,"r+"))!=NULL) &
            ((Bchar=fopen(seg2,"r+"))!=NULL) &
            ((Cchar=fopen(seg3,"r+"))!=NULL) &
            ((Dchar=fopen(seg4,"r+"))!=NULL) &
            ((Echar=fopen(seg5,"r+"))!=NULL) &
            ((Fchar=fopen(seg6,"r+"))!=NULL) &
            ((Gchar=fopen(seg7,"r+"))!=NULL) &
            ((DPchar=fopen(seg8,"r+"))!=NULL)
         )
         {
            fwrite("1", sizeof(char), 1, Achar);
            fwrite("1", sizeof(char), 1, Bchar);
            fwrite("1", sizeof(char), 1, Cchar);
            fwrite("1", sizeof(char), 1, Dchar);
            fwrite("1", sizeof(char), 1, Echar);
            fwrite("1", sizeof(char), 1, Fchar);
            fwrite("1", sizeof(char), 1, Gchar);
            fwrite("1", sizeof(char), 1, DPchar);
            fclose(Achar);
            fclose(Bchar);
						fclose(Cchar);
            fclose(Dchar);
            fclose(Echar);
            fclose(Fchar);
            fclose(Gchar);
            fclose(DPchar);
					}

			 if(
            ((Achar=fopen(seg1,"r+"))!=NULL) &
            ((Bchar=fopen(seg2,"r+"))!=NULL) &
            ((Fchar=fopen(seg6,"r+"))!=NULL) &
            ((Echar=fopen(seg5,"r+"))!=NULL) &
            ((Dchar=fopen(seg4,"r+"))!=NULL) &
						((Cchar=fopen(seg3,"r+"))!=NULL) &
            ((DPchar=fopen(seg8,"r+"))!=NULL)
				 )
         {
            fwrite("0", sizeof(char), 1, Achar);
            fwrite("0", sizeof(char), 1, Bchar);
            fwrite("0", sizeof(char), 1, Cchar);
            fwrite("0", sizeof(char), 1, Echar);
						fwrite("0", sizeof(char), 1, Dchar);
						fwrite("0", sizeof(char), 1, Fchar);
            fwrite("0", sizeof(char), 1, DPchar);
            fclose(Achar);
            fclose(Bchar);
            fclose(Cchar);
            fclose(Echar);
            fclose(Dchar);
						fclose(Fchar);
            fclose(DPchar);
       	}	
			break;
		case 1: 
			usleep(1000000);
			if(
                        ((Achar=fopen(seg1,"r+"))!=NULL) &
                        ((Bchar=fopen(seg2,"r+"))!=NULL) &
                        ((Cchar=fopen(seg3,"r+"))!=NULL) &
                        ((Dchar=fopen(seg4,"r+"))!=NULL) &
                        ((Echar=fopen(seg5,"r+"))!=NULL) &
                        ((Fchar=fopen(seg6,"r+"))!=NULL) &
                        ((Gchar=fopen(seg7,"r+"))!=NULL) &
                        ((DPchar=fopen(seg8,"r+"))!=NULL)
                        )
                        {
                        fwrite("1", sizeof(char), 1, Achar);
                        fwrite("1", sizeof(char), 1, Bchar);
                        fwrite("1", sizeof(char), 1, Cchar);
                        fwrite("1", sizeof(char), 1, Dchar);
                        fwrite("1", sizeof(char), 1, Echar);
                        fwrite("1", sizeof(char), 1, Fchar);
                        fwrite("1", sizeof(char), 1, Gchar);
                        fwrite("1", sizeof(char), 1, DPchar);
                        fclose(Achar);
                        fclose(Bchar);
												fclose(Cchar);
                        fclose(Dchar);
                        fclose(Echar);
                        fclose(Fchar);
                        fclose(Gchar);
                        fclose(DPchar);
			}
			if(
                	((Bchar=fopen(seg2,"r+"))!=NULL) &
                	((Cchar=fopen(seg3,"r+"))!=NULL) &
               	        ((DPchar=fopen(seg8,"r+"))!=NULL)
          		)
                	{
                        fwrite("0", sizeof(char), 1, Bchar);
                        fwrite("0", sizeof(char), 1, Cchar);
                        fwrite("0", sizeof(char), 1, DPchar);
                        fclose(Bchar);
                        fclose(Cchar);
                        fclose(DPchar);
                	}
			break;
		case 2:usleep(1000000);
			if(
                        ((Achar=fopen(seg1,"r+"))!=NULL) &
                        ((Bchar=fopen(seg2,"r+"))!=NULL) &
                        ((Cchar=fopen(seg3,"r+"))!=NULL) &
                        ((Dchar=fopen(seg4,"r+"))!=NULL) &
			((Echar=fopen(seg5,"r+"))!=NULL) &
			((Fchar=fopen(seg6,"r+"))!=NULL) &
                        ((Gchar=fopen(seg7,"r+"))!=NULL) &
                        ((DPchar=fopen(seg8,"r+"))!=NULL)
                        )
                        {
                        fwrite("1", sizeof(char), 1, Achar);
                        fwrite("1", sizeof(char), 1, Bchar);
                        fwrite("1", sizeof(char), 1, Cchar);
                        fwrite("1", sizeof(char), 1, Dchar);
			fwrite("1", sizeof(char), 1, Echar);
			fwrite("1", sizeof(char), 1, Fchar);
                        fwrite("1", sizeof(char), 1, Gchar);
                        fwrite("1", sizeof(char), 1, DPchar);
                        fclose(Achar);
                        fclose(Bchar);
                        fclose(Cchar);
                        fclose(Dchar);
			fclose(Echar);
			fclose(Fchar);
                        fclose(Gchar);
                        fclose(DPchar);
                        }

			if(
			((Achar=fopen(seg1,"r+"))!=NULL) &
                        ((Bchar=fopen(seg2,"r+"))!=NULL) &
                        ((Echar=fopen(seg5,"r+"))!=NULL) &
			((Dchar=fopen(seg4,"r+"))!=NULL) &
			((Gchar=fopen(seg7,"r+"))!=NULL) &
                        ((DPchar=fopen(seg8,"r+"))!=NULL)
                        )
                        {
			fwrite("0", sizeof(char), 1, Achar);
                        fwrite("0", sizeof(char), 1, Bchar);
                        fwrite("0", sizeof(char), 1, Echar);
			fwrite("0", sizeof(char), 1, Dchar);
			fwrite("0", sizeof(char), 1, Gchar);
                        fwrite("0", sizeof(char), 1, DPchar);
			fclose(Achar);
                        fclose(Bchar);
                        fclose(Echar);
			fclose(Dchar);
			fclose(Gchar);
                        fclose(DPchar);
                        }
                        break;

		case 3:usleep(1000000);
			if(
                        ((Achar=fopen(seg1,"r+"))!=NULL) &
                        ((Bchar=fopen(seg2,"r+"))!=NULL) &
                        ((Cchar=fopen(seg3,"r+"))!=NULL) &
                        ((Dchar=fopen(seg4,"r+"))!=NULL) &
                        ((Echar=fopen(seg5,"r+"))!=NULL) &
                        ((Fchar=fopen(seg6,"r+"))!=NULL) &
                        ((Gchar=fopen(seg7,"r+"))!=NULL) &
                        ((DPchar=fopen(seg8,"r+"))!=NULL)
                        )
                        {
                        fwrite("1", sizeof(char), 1, Achar);
                        fwrite("1", sizeof(char), 1, Bchar);
                        fwrite("1", sizeof(char), 1, Cchar);
                        fwrite("1", sizeof(char), 1, Dchar);
                        fwrite("1", sizeof(char), 1, Echar);
                        fwrite("1", sizeof(char), 1, Fchar);
                        fwrite("1", sizeof(char), 1, Gchar);
                        fwrite("1", sizeof(char), 1, DPchar);
                        fclose(Achar);
                        fclose(Bchar);
                        fclose(Cchar);
			fclose(Dchar);
                        fclose(Echar);
                        fclose(Fchar);
                        fclose(Gchar);
                        fclose(DPchar);
                        }
			if(
                        ((Achar=fopen(seg1,"r+"))!=NULL) &
                        ((Bchar=fopen(seg2,"r+"))!=NULL) &
                        ((Cchar=fopen(seg3,"r+"))!=NULL) &
                        ((Dchar=fopen(seg4,"r+"))!=NULL) &
                        ((Gchar=fopen(seg7,"r+"))!=NULL) &
                        ((DPchar=fopen(seg8,"r+"))!=NULL)
                        )
			{
			fwrite("0", sizeof(char), 1, Achar);
                        fwrite("0", sizeof(char), 1, Bchar);
                        fwrite("0", sizeof(char), 1, Cchar);
                        fwrite("0", sizeof(char), 1, Dchar);
                        fwrite("0", sizeof(char), 1, Gchar);
                        fwrite("0", sizeof(char), 1, DPchar);
                        fclose(Achar);
                        fclose(Bchar);
                        fclose(Cchar);
                        fclose(Dchar);
                        fclose(Gchar);
			fclose(DPchar);
			}
			break;

		default: break;
	}	
}



void led(int m,int ch)
{
FILE *LR4 = fopen("/sys/class/gpio/gpio30/value","r+");
FILE *LG4 = fopen("/sys/class/gpio/gpio60/value","r+");
FILE *LR3 = fopen("/sys/class/gpio/gpio31/value","r+");
FILE *LG3 = fopen("/sys/class/gpio/gpio50/value","r+");
FILE *LR2 = fopen("/sys/class/gpio/gpio48/value","r+");
FILE *LG2 = fopen("/sys/class/gpio/gpio51/value","r+");
FILE *LR1 = fopen("/sys/class/gpio/gpio49/value","r+");
FILE *LG1 = fopen("/sys/class/gpio/gpio15/value","r+"); 

	if((m >= 0) & (m <=3))
	{
		switch(ch)
		{
			case 0:
				 fwrite("1", sizeof(char), 1, LR1);
				 fwrite("1", sizeof(char), 1, LG1);
				 fflush(LR1);
				 fflush(LG1);
				 break;
			case 1:
				fwrite("0", sizeof(char), 1, LR1);
				fwrite("0", sizeof(char), 1, LG1);
				fwrite("0", sizeof(char), 1, LG2);
				fwrite("1", sizeof(char), 1, LR2);
				fflush(LR2);
				fflush(LG1);
				fflush(LG2);
				fflush(LR1);
				break;
			case 2:
				fwrite("0", sizeof(char), 1, LR2);
				fwrite("0", sizeof(char), 1, LG2);
				fwrite("0", sizeof(char), 1, LG3);
				fwrite("1", sizeof(char), 1, LR3);
				fflush(LR2);
				fflush(LG2);
				fflush(LG3);
				fflush(LR3);
				break;
			case 3:
				fwrite("0", sizeof(char), 1, LR3);
				fwrite("0", sizeof(char), 1, LG3);
				fwrite("0", sizeof(char), 1, LG4);
				fwrite("1", sizeof(char), 1, LR4);
				fflush(LR3);
				fflush(LG3);
				fflush(LG4);
				fflush(LR4);
				break;
		  
			default:
				break;
		}
	}
	else
	if(m>3)
		{
			switch(ch)
			{
				case 3:
					fwrite("0", sizeof(char), 1, LR4);
					fwrite("1", sizeof(char), 1, LG4);
					fflush(LR4);
					fflush(LG4);
					break;
				case 2:
					fwrite("0", sizeof(char), 1,LG4);
					fwrite("0", sizeof(char), 1,LR4);
					fwrite("0", sizeof(char), 1,LR3);
					fwrite("1", sizeof(char), 1,LG3);
					fflush(LG4);
					fflush(LR4);
					fflush(LR3);
					fflush(LG3);
					break;
				case 1:
					fwrite("0", sizeof(char), 1, LR3);
					fwrite("0", sizeof(char), 1, LG3);
					fwrite("0", sizeof(char), 1, LR2);
					fwrite("1", sizeof(char), 1, LG2);
					fflush(LR3);
					fflush(LG3);
					fflush(LR2);
					fflush(LG2);
					break;
				case 0:
					fwrite("0", sizeof(char), 1, LG2);
					fwrite("0", sizeof(char), 1, LR2);
					fwrite("1", sizeof(char), 1, LR1);
					fwrite("1", sizeof(char), 1, LG1);
					fflush(LG2);
					fflush(LR2);
					fflush(LG1);
					fflush(LR1);
					break;
				default:
					break;
			}
		}
	fclose(LR1);
	fclose(LR2);
	fclose(LR3);
	fclose(LR4);
	fclose(LG1);
	fclose(LG2);
	fclose(LG3);
	fclose(LG4);
}

