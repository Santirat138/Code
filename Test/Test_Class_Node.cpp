#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
        node(int newNum){
            num=newNum;
            next=NULL;
        }
};
class linkList{
    public:
        node *head;
        linkList(){
            head=NULL;
        }
        void addNode(node **headRef, int newNum){
            node *newNode=new node(newNum);
            newNode->next=*headRef;
            *headRef=newNode;
        }
        void show(){
            node *currNode=head;
            while(currNode!=NULL){
                cout<<currNode->num<<" ";
                currNode=currNode->next;
            }
        }
};
int main(){
    linkList list1;
    list1.addNode(&list1.head, 1);
    list1.addNode(&list1.head, 2);
    list1.addNode(&list1.head, 3);
    list1.show();
}