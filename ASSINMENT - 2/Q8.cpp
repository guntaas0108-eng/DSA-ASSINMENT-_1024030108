#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        bool flag=false;
       for (int j = 0; j < i; j++)
       {
        if (arr[i]==arr[j])
        {
           flag=true;
        break;
        }

       }
       if(flag!=true){
         cnt++;
       }

    }
    cout<<cnt;

}