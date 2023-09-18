#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
};
void addFirst(node **headRef, int newNum);
void show(node **headRef);
node *findNode(node **headRef, int target);
void deleteNode(node **headRef, int target);
/*-----------------------------------------*/ 
int main(){
    node *head=NULL;
    node **headR=&head;
    for(int i=0;i<=5;i++){
        addFirst(headR, i);
    }

}
/*-----------------------------------------*/ 
void addFirst(node **headRef, int newNum){
    node *newNode=new node();
    if(*headRef==NULL){
        *headRef=newNode;
    }
    else if(*headRef!=NULL){
        newNode->next=*headRef;
        *headRef=newNode;
    }
}
void show(node **headRef){
    node *showNode=*headRef;
    while(showNode!=NULL){
        cout<<showNode->num<<" ";
        showNode=showNode->next;
    }
    cout<<endl<<endl;
}
node *findNode(node **headRef, int target){
    node *currNode=*headRef;
    while(currNode!=NULL){
        if(currNode->num==target){
            break;
        }
        else{
            currNode=currNode->next;
        }
    }
    return currNode;
}
void deleteNode(node **headRef, int target){

}