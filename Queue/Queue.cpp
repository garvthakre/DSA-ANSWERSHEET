#include<iostream>
#include<queue>
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear;
    int size;
    
public:
Queue() {
    size = 100001;
    arr= new int[size];
    front = 0;
    rear = 0;
};
bool isEmpty(){
     if(front==rear){
        return -1;
    }else{
       return false;
    }
}
void enqueue(int data){
    if(rear == size)
    cout << "Queue is Full"<< endl;

else {
    arr[rear] = data;
    rear++;
}
}
int dequeue(){
    if(front == rear){
        return -1;

    }else {
        arr[front]=-1;
        front--;
        if(front==rear){
            front = 0;
            rear = 0;
        }
    }
}

int front(){
    if(front==rear){
        return -1;
    }else{
       return arr[front]
    }
}}
int main() {
    
    q.push(11);
}