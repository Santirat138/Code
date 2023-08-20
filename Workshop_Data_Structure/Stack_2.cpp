#include<iostream>
using namespace std;
class node{
    public:
        char ch;
        node *next;
};
void push(node **topRef, char newCh);
char pop(node **topRef);
int countAmount(string strIn);
int main(){
    node *top=NULL;
    node **top_ref=&top;
    string strIn;
    int amountCh;
    int i;
    cin>>strIn;
    amountCh=countAmount(strIn);
    char newCh[amountCh];
    char chOut;
    for(i=0;i<amountCh;i++){
        newCh[i]=strIn[i];
        push(top_ref, newCh[i]);
    }
    while(*top_ref!=NULL){
        chOut=pop(top_ref);
        cout<<chOut;
    }
}
void push(node **topRef, char newCh){
    node *newNode=new node();
    newNode->ch=newCh;
    if(*topRef==NULL){
        *topRef=newNode;
    }
    else{
        newNode->next=*topRef;
        *topRef=newNode;
    }
}
char pop(node **topRef){
    node *tempNode=*topRef;
    *topRef=tempNode->next;
    return tempNode->ch;
}
int countAmount(string strIn){
    int amount=0;
    int i;
    for(i=0;strIn[i]!='\0';++i){
        amount++;
    }
    return amount;
}