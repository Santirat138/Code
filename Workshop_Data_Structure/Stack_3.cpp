#include<iostream>
using namespace std;
#define MAX 20
class node{
    public:
        int num;
        node *next;
};
int amount=0;
void push(node **topRef, int newNum);
int pop(node **topRef);
void showNext(node **topRef);
void newSort(node **topRef);
void showAll(node **topRef);
int main(){
    node *top=NULL;
    node **top_ref=&top;
    char chIn;
    int num;
    int numOut;
    bool status=true;
    do{
        chIn=getchar();
        if(chIn=='U'){
            cin>>num;
            push(top_ref, num);
        }
        /*else if(chIn=='S'){
            showAll(top_ref);
        }*/
        else if(chIn=='O'){
            numOut=pop(top_ref);
            cout<<numOut<<endl;
        }
        else if(chIn=='T'){
            showNext(top_ref);
        }
        else if(chIn=='P'){
            newSort(top_ref);
        }
        else if(chIn=='N'){
            cout<<amount<<endl;
        }
        else if(chIn=='X'){
            status=false;
            break;
        }
        status=true;
    }
    while(status);
}
void push(node **topRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*topRef==NULL){
        *topRef=newNode;
    }
    else{
        newNode->next=*topRef;
        *topRef=newNode;
    }
    amount++;
}
int pop(node **topRef){
    node *tempNode=*topRef;
    *topRef=tempNode->next;
    amount--;
    return tempNode->num;
}
void showNext(node **topRef){
    node *nextNode=*topRef;
    cout<<nextNode->num<<endl;
}
void newSort(node **topRef){
    int remainNode=amount;
    int walk=0;
    node *sentNode=*topRef;
    node *prepareNode=NULL;
    int i=0;
    int array[MAX];
    while(remainNode>=0){
        if(walk==remainNode-1){
            array[i]=sentNode->num;
            sentNode=*topRef;
            remainNode--;
            walk=0;
            i++;
        }
        else if(walk<remainNode-1){
            walk++;
            prepareNode=sentNode;
            sentNode=sentNode->next;
        }
        else{
            break;
        }
    }
    for(i=0;i<amount;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void showAll(node **topRef){
    node *showNode=*topRef;
    while(showNode!=NULL){
        cout<<showNode->num<<" ";
        showNode=showNode->next;
    }
}