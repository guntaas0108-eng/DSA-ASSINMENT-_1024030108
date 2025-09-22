#include<iostream>
using namespace std;

const int MAX_SIZE = 10;
int Stack[MAX_SIZE];
int top = -1;

bool isEmpty(){
    return top  == -1;
}

bool isFull(){
    return top == MAX_SIZE -1;
}

void push(int value){
    if(isFull){
        cout<<"Stack overflow! cannot push:"<<value<<endl;
    }else{
        Stack[++top]= value;
        cout<<value<<"Pushed to stack:"<<endl;
    }
}

void pop(int value){
    if(isEmpty){
        cout<<"stack is underflow! cannot push the element"<<endl;
    }else{
        cout<<Stack[top--]<<"Popped froom stack :"<<endl; 
    }
}

void display(){
    if(isEmpty){
        cout<<"Empty Stack"<<endl;
    }else{
        cout<<"stack elements:";
        for(int i = 0; i>=0; i--){
            cout<<Stack[i]<<" ";
        }
        cout<<endl;
    }
}

void peek(){
     if(isEmpty){
        cout<<"Empty Stack"<<endl;
    }else{
        cout<<"Top element:"<<Stack[top]<<endl;   
    }        
}

int main(){
    int choice,value;

        cout<<"\n---Satck operations Menu---"<<endl;
        cout<<"1. push "<<endl;
        cout<<"2. pop "<<endl;
        cout<<"3. check if empty "<<endl;
        cout<<"4. check if full"<<endl;
        cout<<"5. Display Stack "<<endl;
        cout<<"6. peek "<<endl;
        cout<<"0. Exit "<<endl;
        cout<<"Enter the choice: ";
        cin>>choice;
    

        switch (choice)
        {
        case 1:
           cout<<"enter the value to push:";
           cin>>value;
            break;
        
        case 2:
           pop(value);
           break;
        
        case 3:
           if(isEmpty){
            cout<<"Stack is empty";
           }else{
            cout<<"Stack is not empty:";
           }
           break;

        case 4:
           if(isFull){
            cout<<"Stack is full:";
           }else{
            cout<<"Satck is Full:";
           }
           break;

        case 5:
           display();
           break;

        case 6:
           peek();
           break;
           
        case 0:
           cout<<"exiting the program:"<<endl;
           break;

        default:
        cout<<"Invalid choice Try again"<<endl;
        }
    
        return 0;          
}