

#include<stdio.h>
#include<omp.h>
#include<sched.h>
//#include<timer.h>
int a[30],s,test;
int global_size,global_x,n=4;

void nary_search(int,int);
void seq_search(int);
int main()
{
	int i,size=30,x=0;

	for(i=0;i<size;i++)
	a[i]=i*2;

	for(i=0;i<size;i++)
	printf("%d ",a[i]);
	printf("\n");
	
	printf("Enter number to be searched\n");
	scanf("%d",&s);
	/*intf("enter the number of threads used\n");
	/*scanf("%d",&n)*/

	nary_search(size,x);
	return 0;
}

void nary_search(int size,int x)
{
	printf("size = %d\n",size);
	if(size<=2)
	{

		test=0;
		#pragma omp parallel
		{
			int tid=omp_get_thread_num();
			printf("%d",global_x);
			if(a[global_x+tid]==s)
			{

				printf("found at %d\n",global_x+tid);
				test=1;
			}
		}

		if(test==0)
		{

			printf("not found\n");
		}
	}
	else
	{
		test=0;
		#pragma omp parallel
		{
			int tid=omp_get_thread_num();
			printf("checking (%d --  %d)with thread %d on cpu %d \n",a[tid*size/n+x],a[tid*size/n+size/n-1+x],tid,sched_getcpu());
			if(s>=a[tid*size/n+x] && s<=a[tid*size/n+size/n-1+x])
			{
				printf("may be here  %d ---- %d  size=(   %d   )\n",a[tid*size/n+x],a[tid*size/n+size/n-1+x],+size/n);
				global_size=size/n;
				global_x=tid*global_size+x;
				test=1;
			}
		}
		if(test==1)
			nary_search(global_size,global_x);
		else
			printf("not found in\n");
	}
}

