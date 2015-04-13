#include<stdio.h>
#include<omp.h>
omp_lock_t writelock;
omp_lock_t readlock;
omp_lock_t mutex;
int readcount=0;
int tid=-1;

//reader function executed by reader
void reader(int rc)
{
	printf("\nthread id = %d rc = %d\n",omp_get_thread_num(),rc);
	
	omp_set_lock(&readlock);
		readcount++;
			if(readcount==1)
				omp_set_lock(&writelock);
	omp_unset_lock(&readlock);

	printf("\nR[%d]reader is entering critical section",rc);
		//readunit();
	printf("\nR[%d]reader is leaving critical section",rc);
	
	omp_set_lock(&readlock);
		readcount--;
			if(readcount==0)
				omp_unset_lock(&writelock);

	omp_unset_lock(&readlock);


}
//writer function executed by writer
void writer(int wc)
{
	printf("\nthread id = %d wc = %d\n",omp_get_thread_num(),wc);
	// obtain the lock
  	omp_set_lock(&writelock);
	// one thread at a time stuff
	//printf("Writer %d in critical section ",wno);    	

	printf("\nW[%d]writer is entering critical section",wc);
	//critical section
	//writeunit();
	
	// release the lock	
	omp_unset_lock(&writelock);
	printf("\nW[%d]writer is leaving critical section",wc);
    	// some stuff
}




int main()
{


//init the locks
omp_init_lock(&writelock);
omp_init_lock(&readlock);
omp_init_lock(&mutex);
#pragma omp parallel shared(writelock,readlock,mutex)private(tid)
{
	        omp_set_num_threads(6);
		#pragma omp single
	        { reader(1);}
		#pragma omp single
		{reader(2);}
		#pragma omp single
		{reader(3);}
		#pragma omp single
		{writer(1);}
		#pragma omp single		
		{ reader(4);}
		#pragma omp single
		{writer(2);}		
		
	/*#pragma omp sections
	{
		reader(1);
		writer(1);		
		reader(2);
		
	}*/
}
//distroy the locks
omp_destroy_lock(&writelock);
omp_destroy_lock(&readlock);
omp_destroy_lock(&mutex);
}
[komal@localhost ~]$ gcc -o omp_helloc -fopenmp rw.c
[komal@localhost ~]$ ./omp_helloc

thread id = 0 rc = 1

R[1]reader is entering critical section
R[1]reader is leaving critical section
thread id = 0 rc = 2

R[2]reader is entering critical section
R[2]reader is leaving critical section
thread id = 0 rc = 3

R[3]reader is entering critical section
R[3]reader is leaving critical section
thread id = 0 wc = 1

W[1]writer is entering critical section
W[1]writer is leaving critical section
thread id = 0 rc = 4

R[4]reader is entering critical section
R[4]reader is leaving critical section
thread id = 0 wc = 2

W[2]writer is entering critical section
W[2]writer is leaving critical section[komal@localhost ~]$ /*OUTPUT

*/

