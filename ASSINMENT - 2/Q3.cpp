#include<iostream>
using namespace std;
int main(){
    int n;
cin>>n;
        int arr[n];
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    int k=arr[1]-arr[0];
   
  
    for(int i=1;i<5;i++){
      if(arr[i]-arr[i-1]!=k){
      	cout<<arr[i-1]+k;
      	break;
	  }
    }
}