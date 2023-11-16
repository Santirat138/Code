#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
node nullNode(-1);
void connectNode(node *node1, node *node2);
class linkList{
    public:
        node *head;
        node *tail;
        node **headRef;
        node **tailRef;
        linkList();
        void addFirst(int newNum);
        void show();
};
linkList::linkList(){
    headRef=&head;
    tailRef=&tail;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((*headRef==NULL)&&(*tailRef==NULL)){
        *headRef=newNode;
        *tailRef=newNode;
    }
    else{
        connectNode(newNode, *headRef);
        *headRef=newNode;
    }
}
void linkList::show(){
    node *currNode=*headRef;
    cout<<endl<<"Head --> Tail."<<endl;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->next;
    }
    cout<<endl<<endl<<"Tail --> Head."<<endl;
    currNode=*tailRef;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->prev;
    }
}
int main(){
    
}
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}