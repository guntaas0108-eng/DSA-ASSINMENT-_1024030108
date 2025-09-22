  #include<iostream>
    using namespace std;
    int main(){
        string str;
        getline(cin,str);
        for (int i = 0; i < str.length()-1; i++)
        {
           for (int j = 0;j<str.length()-i-1; j++)
           {
            if(str[j]>str[j+1]){
                int temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
           }

        }
        cout<<str;

    }