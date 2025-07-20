#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Queue {
    int r;
    int f;
    int size;
    int* arr;
    public:
    Queue(int size) {
        
        r=f=-1;
        arr = new int[size];
    }
    int isFull(){
        if(r==size-1){
             return 1;
        }
        return 0;
    }
    int isEmpty(){
        if(r==f){
            return 1;

        }
        return 0;
    }
    void enqueue(int z){
        if(isFull())
        {
            cout <<"QUEUE IS FULL \n";

        }
        else{
            
             r++;
              arr[r]= z;
        }
    };
     void dequeue(int z){
        if(isEmpty())
        {
            cout <<"QUEUE IS Empty \n";

        }
        else{
            
             f--;
              arr[f]= -1;
        }
    };
    void print(){
        for(int i =f+1;i<=r;i++){
            cout<< arr[i]<< endl;

        }
       
    }

};

int main(){
    Queue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(43);
    q.print();

}