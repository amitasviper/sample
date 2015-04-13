#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int rcount,data;//data is shared memory.
omp_lock_t readlock;
omp_lock_t writelock;

void *reader()
{
	
	omp_set_lock(&readlock);
	rcount=rcount+1;
	if(rcount==1)
		omp_set_lock(&writelock);
	omp_unset_lock(&readlock);
	printf("\nData read by the reader is %d\n",data);
	printf("Reader going to sleep for 1 ms.\n");
	sleep(1);
	omp_set_lock(&readlock);
	rcount=rcount-1;
	if(rcount==0)
		omp_unset_lock(&writelock);
	omp_unset_lock(&readlock);
}

void *writer()
{
	
	omp_set_lock(&writelock);
	data++;
	printf("\nData written by the writer is %d\n", data);
	printf("Writer going to sleep for 1 ms.\n");
	sleep(1);
	omp_unset_lock(&writelock);
}

int main()
{
	omp_init_lock(&readlock);
	omp_init_lock(&writelock);
	int num,cnt;
	printf("Enter the number of parallel threads :\n");
	scanf("%d",&num);

	printf("Enter the number of readers and writers:\n");
	scanf("%d",&cnt);




	#pragma omp parallel num_threads(num)
	{
		
			for(int i=0;i<cnt;i++)
			{
				writer();
				reader();
			}
	}
return 0;
}
