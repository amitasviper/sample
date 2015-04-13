#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

using namespace std;
int wcount=0,data=0;//data is shared memory
omp_lock_t readlock;
omp_lock_t writelock;


void *writer()
{
	omp_set_lock(&writelock);
	data++;
	wcount++;
	cout<<"data written by writer is "<<data<<endl;
	omp_unset_lock(&writelock);

}

void *reader()
{
	if(wcount==0)
		writer();
	cout<<"data read by reader is "<<data<<endl;
}





int main(int argc, char const *argv[])
{
	/* code */
	omp_init_lock(&readlock);
	omp_init_lock(&writelock);

	#pragma omp parallel num_threads(10)
	{
		#pragma omp parallel for
		for(int i=0;i<3;i++)
		{	
			reader();
			writer();
		}
	}

	return 0;
}