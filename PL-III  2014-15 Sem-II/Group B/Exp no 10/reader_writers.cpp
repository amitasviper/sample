#include<iostream>
#include<omp.h>
#define size 20

using namespace std;

void readers(int a[]){
    for(int i = 0;i<size; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void writers(int a[],int num){
	a[num%20] = num;
    
}

int main(){
    
    int i = 0,a[size]= {0};
    #pragma omp parallel for num_threads(100)
    for(i = 0;i<100;i++){
        #pragma omp critical
        writers(a,omp_get_thread_num());
        //#pragma omp critical
        readers(a);
    }
	

    return 0;
}

