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
// Node
void addHead(node **headRef, node **tailRef, int newNum);
void connectNode(node *node1, node *node2);
void disConnectNode(node *node1, node *node2);
void showAll(node **headRef, node **tailRef);
void deleteHead(node **headRef);

// stack
void push(node **topRef, int newNum);
node *pop(node **topRef);

// Queue
void enqueue(node **firstRef, node **lastRef, int newNum);
node *dequeue(node **firstRef);

// Stack, Queue
void check(node **firstNode, node **lastNode);
//-----------------Start main-----------------
int main(){
    node *head=NULL;
    node **headR=&head;
    node *tail=NULL;
    node **tailR=&tail;
    int i;
    for(i=0;i<6;i++){
        cout<<"Add head "<<i<<"    ";
        addHead(headR, tailR, i);
    }
    showAll(headR, tailR);
    cout<<endl;
        // Stack
    node *top=NULL;
    node **topR=&top;
    node *testPop;
    for(i=6;i<11;i++){
        push(topR, i);
    }
    while(*topR!=NULL){
        testPop=pop(topR);
        cout<<testPop->num<<" ";
    }
    cout<<endl;
        // Queue
    node *firstNode=NULL;
    node **firstR=&firstNode;
    node *lastNode=NULL;
    node **lastR=&lastNode;
    for(i=11;i<16;i++){
        enqueue(firstR, lastR, i);
    }
    node *testDeq;
    while(*firstR!=NULL){
        testDeq=dequeue(firstR);
        cout<<testDeq->num<<" ";
    }
}
//-----------------End main-----------------
// Node
void addHead(node **headRef, node **tailRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*headRef!=NULL){
        connectNode(newNode, *headRef);
    }
    else{
        *tailRef=newNode;
    }
    *headRef=newNode;
    info.amount++;
}
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}
void disConnectNode(node *node1, node *node2){
    node1->next=NULL;
    node2->prev=NULL;
}
void showAll(node **headRef, node **tailRef){
    if((*headRef==NULL)||(*tailRef==NULL)||(info.amount==0)){
        cout<<"Can't show."<<endl;
    }
    else{
        node *showNode=*headRef;
        cout<<endl<<"Head --> Tail."<<endl;
        while(showNode!=NULL) {
            cout<<showNode->num<<" ";
            showNode=showNode->next;
        }
        showNode=*tailRef;
        cout<<endl<<endl<<"Tail --> Head."<<endl;
        while(showNode!=NULL){
            cout<<showNode->num<<" ";
            showNode=showNode->prev;
        }
        cout<<endl;
    }
}
void deleteHead(node **headRef){
    node *delNode=*headRef;
    *headRef=(*headRef)->next;
    disConnectNode(delNode, *headRef);
    info.amount--;
}
// Stack
void push(node **topRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*topRef!=NULL){
        newNode->next=*topRef;
    }
    *topRef=newNode;
}
node *pop(node **topRef){
    if(*topRef!=NULL){
        node *temp=*topRef;
        *topRef=(*topRef)->next;
        temp->next=NULL;
        return temp;
    }
    else{
        return NULL;
    }
}

// Queue
void enqueue(node **firstRef, node **lastRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if((*firstRef==NULL)||(*lastRef==NULL)){
        *lastRef=newNode;
    }
    else{
        newNode->next=*firstRef;
    }
    *firstRef=newNode;
}
node *dequeue(node **firstRef){
    if(*firstRef!=NULL){
        node *temp=*firstRef;
        *firstRef=(*firstRef)->next;
        temp->next=NULL;
        return temp;
    }
    else{
        return NULL;
    }
}
/*void check(node **firstNode, node **lastNode){

}*/