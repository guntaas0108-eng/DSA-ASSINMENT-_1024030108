    #include<iostream>
    using namespace std;
    int main(){
        int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left=0;
    int right=n-1;
    int target;
    cin>>target;
    bool found=false;
    while(left<=right){
        int mid=(left+right)/2;
        if(target>arr[mid]){
            left=mid+1;
        }
        else if(target<arr[mid]){
            right=mid-1;
        }
        else if(target==arr[mid]){
            cout<<mid;
            found=true;
            break;
        }
    }
    
    if(found!=true){
        return -1;
    }
