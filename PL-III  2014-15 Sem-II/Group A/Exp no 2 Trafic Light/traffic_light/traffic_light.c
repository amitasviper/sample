#include <stdio.h>
#include <unistd.h>

FILE *RD1,*RD2,*RD3,*RD4;
FILE *YL1,*YL2,*YL3,*YL4;
FILE *GN1,*GN2,*GN3,*GN4;
FILE *LT1,*LT2,*LT3,*LT4;

 int main()
{
 int i=0;
  const char *R1="/sys/class/gpio/gpio65/value";
  const char *R2="/sys/class/gpio/gpio45/value";
  const char *R3="/sys/class/gpio/gpio30/value";
  const char *R4="/sys/class/gpio/gpio49/value";
  const char *Y1="/sys/class/gpio/gpio46/value";
  const char *Y2="/sys/class/gpio/gpio23/value";
  const char *Y3="/sys/class/gpio/gpio31/value";
  const char *Y4="/sys/class/gpio/gpio51/value";
  const char *G1="/sys/class/gpio/gpio26/value";
  const char *G2="/sys/class/gpio/gpio47/value";
  const char *G3="/sys/class/gpio/gpio48/value";
  const char *G4="/sys/class/gpio/gpio50/value";
  const char *L1="/sys/class/gpio/gpio44/value";
  const char *L2="/sys/class/gpio/gpio27/value";
  const char *L3="/sys/class/gpio/gpio15/value";
  const char *L4="/sys/class/gpio/gpio60/value";

while(1)
  {
        if(
	   				((GN2 = fopen(G2, "r+")) != NULL) &
	   				((LT2 = fopen(L2, "r+")) != NULL) &
	   				((RD1 = fopen(R1, "r+")) != NULL) &
	   				((RD3 = fopen(R3, "r+")) != NULL) &
	   				((GN4 = fopen(G4, "r+")) != NULL) &	
	   				((LT4 = fopen(L4, "r+")) != NULL) 
	 				)
        	{
	                fwrite("1", sizeof(char), 1, GN2);
			fwrite("1", sizeof(char), 1, LT2);
			fwrite("1", sizeof(char), 1, RD1);
			fwrite("1", sizeof(char), 1, RD3);
			fwrite("1", sizeof(char), 1, GN4);
			fwrite("1", sizeof(char), 1, LT4);
	                fclose(GN2);
			fclose(LT2);
			fclose(RD1);
			fclose(RD3);
			fclose(GN4);
			fclose(LT4);
        	}
	        usleep(50000000);
				if(
 				 	((GN2 = fopen(G2, "r+")) != NULL) &
	  				((GN4 = fopen(G4, "r+")) != NULL) &
					((LT2 = fopen(L2, "r+")) != NULL) & 
					((LT4 = fopen(L4, "r+")) != NULL) 
				)
  				{
			  	 	fwrite("0", sizeof(char), 1, GN2);
			   		fwrite("0", sizeof(char), 1, GN4);
					fwrite("0", sizeof(char), 1, LT2);
					fwrite("0", sizeof(char), 1, LT4);
			   		fclose(GN2);
			   	 	fclose(GN4);
					fclose(LT2);
					fclose(LT4);
				}

				for(i=0;i<5;i++)
				{
					if(
		            			((YL2 = fopen(Y2, "r+")) != NULL) &
		            			((YL4 = fopen(Y4, "r+")) != NULL) 
  	 	  			 )
  	  				{
			                   fwrite("1", sizeof(char), 1, YL2);
			                   fwrite("1", sizeof(char), 1, YL4);
			                   fclose(YL2);
			                   fclose(YL4);
		            		} 
					usleep(1000000);	
      	 			if(
            			((YL2 = fopen(Y2, "r+")) != NULL) &
            			((YL4 = fopen(Y4, "r+")) != NULL) 
            	  ) 
          	 		{        
                   fwrite("0", sizeof(char), 1, YL2);
                   fwrite("0", sizeof(char), 1, YL4);
                   fclose(YL2);
                   fclose(YL4);
          	 		}    
								usleep(1000000);
      		}
					if(
           		((LT2 = fopen(L2, "r+")) != NULL) &
           		((RD1 = fopen(R1, "r+")) != NULL) &
          	 	((RD3 = fopen(R3, "r+")) != NULL) &
           		((LT4 = fopen(L4, "r+")) != NULL) 
         		)	      
        		{       
                fwrite("0", sizeof(char), 1, LT2);
                fwrite("0", sizeof(char), 1, RD1);
                fwrite("0", sizeof(char), 1, RD3);
                fwrite("0", sizeof(char), 1, LT4);		
                fclose(LT2);
                fclose(RD1);
                fclose(RD3);
                fclose(LT4);
        		}

					if (
          		 	((GN1 = fopen(G1, "r+")) != NULL) &
          	  	((LT1 = fopen(L1, "r+")) != NULL) &
            		((RD2 = fopen(R2, "r+")) != NULL) &
            		((RD4 = fopen(R4, "r+")) != NULL) &
            		((GN3 = fopen(G3, "r+")) != NULL) &
            		((LT3 = fopen(L3, "r+")) != NULL) 
           	) 
       	  	{
                fwrite("1", sizeof(char), 1, GN1);
                fwrite("1", sizeof(char), 1, LT1);
                fwrite("1", sizeof(char), 1, RD2);
                fwrite("1", sizeof(char), 1, RD4);
                fwrite("1", sizeof(char), 1, GN3);
                fwrite("1", sizeof(char), 1, LT3);
                fclose(GN1);
                fclose(LT1);
                fclose(RD2);
                fclose(RD4);
                fclose(GN3);
                fclose(LT3);
       	  	}       
						usleep(50000000);
					if(   
		  					((GN1 = fopen(G1, "r+")) != NULL) &
								((GN3 = fopen(G3, "r+")) != NULL) &
								((LT1 = fopen(L1, "r+")) != NULL) &
								((LT3 = fopen(L3, "r+")) != NULL) 
						)
						{    
		    				fwrite("0", sizeof(char), 1, GN1);
			  				fwrite("0", sizeof(char), 1, GN3);
								fwrite("0", sizeof(char), 1, LT1);
								fwrite("0", sizeof(char), 1, LT3);
			  				fclose(GN1);
			  				fclose(GN3);
								fclose(LT1);
								fclose(LT3);
						}

					for(i=0;i<5;i++)
        	{
        		if(
            			((YL1 = fopen(Y1, "r+")) != NULL) &
            			((YL3 = fopen(Y3, "r+")) != NULL)
          	  )
          	  {
                   fwrite("1", sizeof(char), 1, YL1);
                   fwrite("1", sizeof(char), 1, YL3);
                   fclose(YL1);
                   fclose(YL3);
          	  }
	 	  			usleep(1000000);
						if(
            		((YL1 = fopen(Y1, "r+")) != NULL) &
            		((YL3 = fopen(Y3, "r+")) != NULL)
            	)
          	  {
                   fwrite("0", sizeof(char), 1, YL1);
                   fwrite("0", sizeof(char), 1, YL3);
                   fclose(YL1);
		   						 fclose(YL3);
	  	  			}
						usleep(1000000);
						}

						if (
            			((LT1 = fopen(L1, "r+")) != NULL) &
            			((RD2 = fopen(R2, "r+")) != NULL) &
            			((RD4 = fopen(R4, "r+")) != NULL) &
           			 	((LT3 = fopen(L3, "r+")) != NULL)
           		)    
          		{     
              	  fwrite("0", sizeof(char), 1, LT1);
               	 	fwrite("0", sizeof(char), 1, RD2);
                	fwrite("0", sizeof(char), 1, RD4);
                	fwrite("0", sizeof(char), 1, LT3);
                	fclose(LT1);
                	fclose(RD2);
                	fclose(RD4);
                	fclose(LT3);
          		}       

 	}
 return 0;
}


