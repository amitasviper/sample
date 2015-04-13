//Matrix Multiplication Program Using threading
#include <stdio.h>
#include <stdlib.h>
int Width=32;	//Width of matrix

int hTile_Width=300;
__device__ int dTile_Width=32; //Declare device copy for tile width

int CompareMatrix(int *M1,int *M2,int row,int col)
{		for(int i=0;i<(row*col);i++)
		{	if(M1[i]!=M2[i])
				return i;	
		}
		return -1;
		
}

/*Function to display Matrix elements
--------------------------------------------
Arguments
1-Matrix Pointer
2-Total elements size
--------------------------------------------
*/


void display_matrix(int *ptr,int m, int n)
{
	for(int i=0;i<m*n;i++)
	{	if(i%(n)==0){
			printf("\n");
		}
		printf("%d ",ptr[i]);
	}
}

/*Kernel function
---------------------------------------------
Arguments:
1-1st Matrix pointer
2-2nd Matrix pointer
3-Resultant matrix pointer
4-Width of square matrix
	This function calculates dot product of row and column for each thread
	__global__ qualifier indicates function can be called from host code and runs on device(GPU)
---------------------------------------------
*/
__global__ void MatrixMulKernel(int *Md,int *Nd,int *Pd,int w)
{
	int row=blockIdx.y*dTile_Width+ threadIdx.y;		//Get thread X position in a 2D block of threads
   int col=blockIdx.x*dTile_Width+ threadIdx.x;		//Get thread Y position in a 2D block of threads
   int Pvalue=0;
	 if(row<w && col<w){
    	for(int k=0;k<w;++k)	//
    	{
        Pvalue+=Md[row*w+k]*Nd[k*w+col];		//Calculate sum of dot product of elements
    	}
    	Pd[row*w+col]=Pvalue;
	}	
}

void NormalMultiplication(int *M,int *N,int *P,int w)
{

	for(int i=0;i<w;++i){
		for(int j=0;j<w;j++){
			int sum=0;
			for(int k=0;k<w;k++){
				int a=M[i*w+k];
				int b=N[k*w+j];
				sum+=a*b;
			}
			P[i*w+j]=sum;
		}
	}

}

/*
-----------------------------------------------
Arguments
1-1st Matrix pointer
2-2nd Matrix pointer
3-Resultant matrix pointer
4-Width of square matrix
	This function copy matrix data from host memory to device global memory and invoke kernel
-----------------------------------------------
 */
void MatrixMultiplication(int *M,int *N,int *P,int w)
{	int *Md,*Nd,*Pd;		//Matrix Pointer on device memoryi.e GPU
	int size=w*w*sizeof(int*);
	int x;

	cudaMalloc((void**)&Md,size);		//Allocate memory on device global memory
	cudaMemcpy(Md,M,size,cudaMemcpyHostToDevice);	//Copy matrix data from host to device memory
	cudaMalloc((void**)&Nd,size);
	cudaMemcpy(Nd,N,size,cudaMemcpyHostToDevice);
	cudaMalloc((void**)&Pd,size);
	

			if(w%hTile_Width!=0)			//
			{
				x=w/hTile_Width+1;
			}
			else
			{
				x=w/hTile_Width;
			}
		
		dim3 dimGrid(x,x);									//Variable for threads arrangement in a block.
		dim3 dimBlock(hTile_Width,hTile_Width);		//Variable for blocks arrangement in a grid.	

	MatrixMulKernel<<<dimGrid,dimBlock>>>(Md,Nd,Pd,w);	//Kernel invocation with grid and block specification in angle brackets

	cudaMemcpy(P,Pd,size,cudaMemcpyDeviceToHost);	//Copy resultant matrix from device to host
	//Free device memory
	cudaFree(Md);
	cudaFree(Nd);
	cudaFree(Pd);

}

int main()
{
    int mat_size=Width*Width*sizeof(int*);	//Calculate memory size required for float matrix
    int tot_elements=Width*Width;
    int *M,*N,*P,*ptr,*P_CPU;	// Host matrix pointers
	int a=0;
	int i=0;

	M=(int*)malloc(mat_size);		//Allocate memory on host for matrix
	N=(int*)malloc(mat_size);
	P=(int*)malloc(mat_size);
	P_CPU=(int*)malloc(mat_size);
	ptr=M;
	printf("\nGenarating random elements for matrix");
	for(i=0;i<tot_elements;i++)
	{	a=(rand()%10);		//Generates random no. in 0 to 10 range
		*ptr=a;
		ptr++;
	}
	ptr=N;
	for(i=0;i<tot_elements;i++)
	{
		a=(rand()%10);
		*ptr=a;
		ptr++;
	}
	printf("\nMatrix generated");
	MatrixMultiplication(M,N,P,Width);
	printf("\nDone with GPU");
	display_matrix(N,Width,Width);
	printf("\nMatrix Multiplication (GPU) is :");
	display_matrix(P,Width,Width);
	NormalMultiplication(M,N,P_CPU,Width);
	printf("\nDone with CPU");	
	printf("\n\nMatrix Multiplication is :");
	display_matrix(P_CPU,Width,Width);

	if(CompareMatrix(P,P_CPU,Width,Width)==-1)
		printf("\n\nBoth matrix are same\n");
	else
	{	printf("\n\nBoth matrix are not same\n\n");
		//printf("%d",CompareMatrix(P,P_CPU,Width,Width));
	}
}
