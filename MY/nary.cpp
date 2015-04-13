#include <iostream>
#include <stdio.h>
#include <omp.h>
using namespace std;

int arr[30],s,test;
int global_size,global_x,n=4;


void nary(int sz,int x)
{
	cout<<"size="<<sz<<endl;
	if(sz<=2)
	{
		test=0;
		#pragma omp parallel
		{
			int tid=omp_get_thread_num();
			cout<<"global_x="<<global_x<<endl;
			if(arr[global_x+tid]==s)
			{
				cout<<"found at "<<global_x+tid<<endl;
				
				test=1;
			}
		}

		if(test==0)
		{
			cout<<"not found"<<endl;
		}
	}

	else
	{
		test=0;
		#pragma omp parallel
		{
			int tid=omp_get_thread_num();
			printf("checking (%d----%d) with thread %d on cpu %d\n",arr[tid*sz/n+x],arr[tid*sz/n+sz/n-1+x],tid,sched_getcpu());
			if(s>=arr[tid*sz/n+x] && s<=arr[tid*sz/n+sz/n-1+x])
			{
				printf("may be here  %d ---- %d  size=(   %d   )\n",arr[tid*sz/n+x],arr[tid*sz/n+sz/n-1+x],+sz/n);
				global_size=sz/n;
				global_x=tid*global_size+x;
				test=1;
			}
		}

		if(test==1)
		{
			nary(global_size,global_x);
		}
		else
		{
			cout<<"not found"<<endl;
		}
	}

}

int main()
{
	int x=0;
	for(int i=0;i<30;i++)
		arr[i]=i*2;

	for(int i=0;i<30;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"Enter the number to be searched"<<endl;
	cin>>s;

	nary(30,x);

}	
