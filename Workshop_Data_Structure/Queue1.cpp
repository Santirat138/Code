#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
};
int amount=0;
void enQ(node **firstRef, node **lastRef, int newNum);
int dQ(node **firstRef, node **lastRef);
void showAll(node **firstRef, node **lastRef);
void showFirstLast(node **firstRef, node **lastRef);
int main(){
    node *firstNode=NULL;
    node *lastNode=NULL;
    node **first_ref=&firstNode;
    node **last_ref=&lastNode;
    char chIn;
    int num;
    int numOut;
    do{
        chIn=getchar();
        if(chIn=='e'){
            cin>>num;
            // Enqueue
            enQ(first_ref, last_ref, num);
        }
        else if(chIn=='d'){
            // Dequeue
            numOut=dQ(first_ref, last_ref);
            cout<<numOut<<endl;
        }
        else if(chIn=='p'){
            // Show
            showAll(first_ref, last_ref);
        }
        else if(chIn=='n'){
            // Show amount of node
            cout<<amount<<endl;
        }
        else if(chIn=='s'){
            // Show first and last number if don't have number don't show
            showFirstLast(first_ref, last_ref);
        }
        else if(chIn=='x'){
            break;
        }
    }
    while(true);
}
void enQ(node **firstRef, node **lastRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*firstRef==NULL){
        *firstRef=newNode;
        *lastRef=newNode;
    }
    else{
        (*lastRef)->next=newNode;
        *lastRef=newNode;
    }
    amount++;
}
int dQ(node **firstRef, node **lastRef){
    node *temp=*firstRef;
    *firstRef=temp->next;
    temp->next=NULL;
    amount--;
    return temp->num;
}
void showAll(node **firstRef, node **lastRef){
    node *showNode;;
    node *temp=*firstRef;
    while(temp!=NULL){
        cout<<temp->num<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void showFirstLast(node **firstRef, node **lastRef){
    if(*firstRef==NULL){

    }
    else{
        cout<<(*firstRef)->num<<" "<<(*lastRef)->num<<endl;
    }
}