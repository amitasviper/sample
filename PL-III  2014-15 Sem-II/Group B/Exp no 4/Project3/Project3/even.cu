#include<stdio.h>
#include<iostream>
#include<conio.h>


__global__ void odd(int *arr,int n){
	int i=threadIdx.x;
	int temp;
	if(i%2==1&&i<n-1){
	if(arr[i]>arr[i+1])
	{
	temp=arr[i];
	arr[i]=arr[i+1];
	arr[i+1]=temp;
	}
	}
}

__global__ void even(int *arr,int n){
	int i=threadIdx.x;
	int temp;
	if(i%2==0&&i<n-1){
	if(arr[i]>arr[i+1])
	{
	temp=arr[i];
	arr[i]=arr[i+1];
	arr[i+1]=temp;
	}
	}
}

int main(){
	int SIZE,k,*A,p,j;
	int *d_A;
	
	
	printf("Enter the size of the array\n");
	scanf("%d",&SIZE);
	A=(int *)malloc(SIZE*sizeof(int));
	cudaMalloc(&d_A,SIZE*sizeof(int));
	for(k=0;k<SIZE;k++)
		scanf("%d",&A[k]);
		
		
	
	cudaMemcpy(d_A,A,SIZE*sizeof(int),cudaMemcpyHostToDevice);
	if(SIZE%2==0)
		p=SIZE/2;
	else
		p=SIZE/2+1;
	for(j=0;j<p;j++){
		even<<<2,SIZE>>>(d_A,SIZE);
		if(j!=p-1)
			odd<<<2,SIZE>>>(d_A,SIZE);
		if(j==p-1&&SIZE%2==0)
			odd<<<1,SIZE>>>(d_A,SIZE);
	}
	cudaMemcpy(A,d_A,SIZE*sizeof(int),cudaMemcpyDeviceToHost);
	for(k=0;k<SIZE;k++)
		printf("%d ",A[k]);
	
	free(A);
	cudaFree(d_A);
	
	getch();
	
}