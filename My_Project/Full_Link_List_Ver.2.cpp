#include<iostream>
using namespace std;
class node{
public:
    int num;
    node *prev;
    node *next;
};
struct dataNode{
    int amount=0;

}info;
void addHead(node **headRef, node **tailRef, int newNum);
void connectNode(node *node1, node *node2);
void showAll(node **headRef, node **tailRef);
int main(){
    node *head=NULL;
    node **headR=&head;
    node *tail=NULL;
    node **tailR=&tail;
    int i;
    for(i=0;i<6;i++){
        addHead(headR, tailR, i);
    }
    showAll(headR, tailR);
}
void addHead(node **headRef, node **tailRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*headRef==NULL){
        *headRef=newNode;
        *tailRef=newNode;
    }
    else{
        connectNode(newNode, *headRef);
        *headRef=newNode;
    }
    info.amount++;
}
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}
void showAll(node **headRef, node **tailRef){
    if((*headRef==NULL)||(*tailRef==NULL)){
        cout<<"Can't show."<<endl;
    }
    else{
        node *showNode=*headRef;
        cout<<"Head --> Tail."<<endl;
        while(showNode!=*tailRef) {
            cout << showNode->num <<" ";
            showNode = showNode->next;
        }
        cout<<showNode->num<<endl<<endl;
        cout<<"Tail --> Head."<<endl;
        while(showNode!=*headRef){
            cout<<showNode->num<<" ";
            showNode=showNode->prev;
        }
        cout<<showNode->num<<endl;
    }
}