#include <iostream>
using namespace std;

class stack {
    int *arr;
    int top;
    int Msize;

    public:
    stack (int size){
        arr = new int[size];
        Msize = size;
        top = -1;
    }
    void push(int x){
        if (top>Msize-1){
            cout<< "stack overflow\n";
            
        }
        arr[++top] = x;
         
    };
    int pop(){
        if(top<0){
            cout<<"stack Underflow\n";
        }
        return arr[top--];
    }
    int peek(){
        if(top<0){
             cout << "Stack is Empty\n";
            
        }
        return arr[top];
    }
    void print() {
        for(int i =0;i<=top;i++){
            cout << arr[i]<< endl;
        }
        cout << endl;
        
    };
};
int main() {
    stack s(5);
  s.push(10);
  s.push(20);
  s.push(30);
  s.print();
  s.pop();
  s.print();
};
