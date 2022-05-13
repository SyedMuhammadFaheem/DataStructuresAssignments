#include<iostream>
using namespace std;
int ctr1=0,ctr2=0;
class node{
	public:
		int data;
		node *next;
		node(){
			next=NULL;
		}
		node(int data){
			this->data=data;
			next=NULL;
		}
};
class list{
	public:
		node *head;
		list(){
			head=NULL;
		}
		void insertAtend(int data){
			node *n=new node(data);
			if(head==NULL){
                head=n;
				return;
			}
			node *temp;
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=n;
			n->next=NULL;
		}
		void display(){
			node *temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}cout<<endl;
		}
        node* CreateNode(int data)
        {
            node* newNode=new node(data);
            return newNode;
        }
		
};

list* merge(list A,list B,list* AB){
			node* temp1=A.head;
			node* temp2=B.head;
            int i=0,data=0;
			while(temp1 && temp2)
            {
                if(i%2==0)
                {
                    data=temp1->data;
                    temp1=temp1->next;
                }
                else
                {
                    data=temp2->data;
                    temp2=temp2->next;
                }
                if(AB->head==NULL)
                {
                    AB->insertAtend(data);
                }
                else
                {
                    AB->insertAtend(data);
                }
                ++i;
			}
            while(temp1)
            {
                AB->insertAtend(temp1->data);
                temp1=temp1->next;
            }
            while(temp2)
            {
                AB->insertAtend(temp2->data);
                temp2=temp2->next;
            }
			return AB;
	}
		
int main()
{
	list A;
	A.insertAtend(1);
	A.insertAtend(2);
	A.insertAtend(5);
	A.insertAtend(7);
	A.insertAtend(8);
	A.insertAtend(11);
	A.display();
	list B;
	B.insertAtend(22);
	B.insertAtend(56);
	B.insertAtend(88);
	B.insertAtend(99);
	B.insertAtend(54);
	B.insertAtend(70);
	B.insertAtend(98);
	B.insertAtend(64);
	B.insertAtend(72);
    B.display();
	list* AB=new list();
    AB=merge(A,B,AB);
	AB->display();
}