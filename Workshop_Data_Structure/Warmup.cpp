// Stack
#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
};
void push(node **topRef, int newNum);
int pop(node **topRef);
int main(){
    node *top=NULL;
    node **topRef=NULL;

}
void push(node **topRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*topRef!=NULL){
        newNode->next=*topRef;
    }
    *topRef=newNode;
}
int pop(node **topRef){
    node *tempNode;
    
}