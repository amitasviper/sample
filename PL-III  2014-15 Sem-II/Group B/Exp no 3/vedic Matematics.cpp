#include <iostream>
#include <omp.h>
#include <stdio.h>
#define sz 100000
using namespace std;

char num[sz]; // input number

bool inputIsValid() {
  if(num[0] >= '0' && num[0] <= '9' && num[1] >= '0' && num[1] <= '9') return true;
  return false;
}

int getSquare(char ch) {
  int ret = (int)(ch-'0');
  ret *= ret;
  return ret;
}

int main() {
  int ans=0;

  cout<<"Enter two digit number: "<<endl;
  cin>>num;

  if(!inputIsValid()) {
    cout<<"Input is invalid"<<endl;
    return 0;
  }

  #pragma omp parallel for num_threads(3) shared(ans)
  for(int i=0;i<=2;i++) {

    // executed by thread 0
    if(i==0) {
      //cout<<" thread no : "<<omp_get_thread_num()<<endl;
      int temp = getSquare(num[i])*100;
      //cout<<"value "<<temp<<endl;
      ans += temp;
    } 

    // executed by thread 1
    else if(i==1) {
      //cout<<" thread no : "<<omp_get_thread_num()<<endl;
      int temp = getSquare(num[i]);
      //cout<<"value "<<temp<<endl;
      ans += temp;
    } 

    // executed by thread 2
    else {
      int temp = (int)(num[0]-'0') * (int)(num[1]-'0') * 2 * 10;
      //cout<<" thread no : "<<omp_get_thread_num()<<endl;
      //cout<<"value "<<temp<<endl;
      ans += temp;
    }
  }

  //printing result
  cout<<ans<<endl;
  return 0;
}
