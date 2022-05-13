#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(){
            next = NULL;
        }
        Node(char data){
            this->data = data;
        }
};
class Queue{
    private:
        Node* nodes,*front,*rear;
        int limit,current;
    public:
        Queue(int l){
            nodes = NULL;
            front = NULL;
            rear = NULL;
            limit = l;
            current = 0;
        }
        bool queueCapacity(){
            if(current == limit){
                return true;
            }else{
                return false;
            }
        }
        void addMember(int data){
            if(queueCapacity()){
                cout<<"Queue is already full."<<endl;
            }else{
                nodes = new Node(data);
                current++;
                cout<<"Node added."<<endl;
                if(front == NULL && rear == NULL){
                    front = nodes;
                    rear = nodes;
                }else{
                    rear->next = nodes;
                    rear = nodes;
                    sort();
                }  
            }
        }
        void sort(){
            Node* ptr = front;
            while(ptr!=rear){
                Node* ptr1 = front;
                while(ptr1 != rear){
                    if(ptr1->data > ptr1->next->data){
                        int temp = ptr1->data;
                        ptr1->data = ptr1->next->data;
                        ptr1->next->data = temp;
                    }
                    ptr1 = ptr1->next;
                }
                ptr = ptr->next;
            }
        }
        void removeMember(){
            if(front == NULL && rear == NULL){
                cout<<"Queue is empty. "<<endl;
            }else{
                cout<<"Node deleted."<<endl;
                current--;
                if(front == rear){
                    delete front;
                    front = NULL;
                    rear = NULL;
                }else{
                    Node* temp = front;
                    while(temp->next != rear && temp){
                        temp = temp->next;
                    }
                    rear = temp;
                    temp = temp->next;
                    delete temp;
                    temp = NULL;

                }
            }
        }
        void traverse(){
            Node* temp = front;
            while(temp!=rear->next){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
int main(){
    Queue q(15);
    q.addMember('P');
    q.addMember('Q');
    q.addMember('E');
    q.traverse();
    q.removeMember();
    q.traverse();
    q.addMember('X');
    q.addMember('A');
    q.addMember('M');
    q.traverse();
    q.removeMember();
    q.traverse();
    q.addMember('P');
    q.addMember('L');
    q.addMember('E');
    q.traverse();
    q.removeMember();
    q.traverse();
}