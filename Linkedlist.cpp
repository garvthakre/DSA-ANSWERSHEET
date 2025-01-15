#include<iostream>
using namespace std ;

class Node {
    public:
    int data;
    Node* next;
    Node(int data=0){
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp ->next=head;
    head = temp;


}
void insertAtTail(Node* &head,int val){

    Node* n = new Node(val);
    if (head==NULL){
        head=n;
        return ;

    }
    Node* temp= head;
    while(temp->next=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(Node* head){
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;

    }
    cout<<endl;

}
int main (){
    Node* head =NULL;
    insertAtTail(head,1);
    InsertAtHead(head,22);
    display(head);
    return 0;

}