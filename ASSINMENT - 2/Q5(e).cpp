#include<iostream>
using namespace std;
int main(){
        int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    int elements[total];


    for(int i = 0; i < total; i++) elements[i] = 0;


    cout << "Enter lower triangular elements: "<< endl;
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> elements[index++];
        }
    }


    cout << "Symmetric Matrix:"<< endl;
    index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) {
                cout << elements[i*(i+1)/2 + j] << " ";
            } else {
                cout << elements[j*(j+1)/2 + i] << " ";
            }
        }
        cout << endl;
    }
}