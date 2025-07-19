#include<iostream>
 
using namespace std;

class CircularQueue{
    int* arr;
    int front;
    int rear;
    int size;
    
public:
CircularQueue(int n){
    size = 100001;
    arr = new int[size];
    front = rear = -1;
}
bool enqueue(int value){
    if((front == 0 && rear == size-1)||(rear == (front-1)%(size-1) )){
        cout<< "queue is Full";
        return false;
    }else if(front==-1){
        front = rear = 0;
        arr[rear]= value;
    }else if(rear == size-1 && front !=0){
        rear = 0;
        arr[rear]= value;
    }else {
        rear++;
    }
    arr[rear]=value;
    return true;
}
int dequeue(){
    if(front==-1){
        cout<<" Queue is Empty"<< endl;
        return -1;
    }
    int ans = arr[front];
    arr[front]=-1;
    if(front==rear){
        front = rear= -1;
    }else if(front==size ==-1){
        front = 0;
    }else{
        front++;
    }
    return ans;
}
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Should hit full condition depending on logic

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(70);

    return 0;
}
