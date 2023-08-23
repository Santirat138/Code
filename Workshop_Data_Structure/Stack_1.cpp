#include<iostream>
using namespace std;
class node{
public:
    char ch;
    node *next;
};

void check(node **topRef, string strIn);
void push(node **topRef, char chIn);
node *pop(node **topRef);
void deleteTop(node **topRef);
int main(){
    node *top=NULL;
    node **topR=&top;
    string prob;
    cin>>prob;
    check(topR, prob);

}
void check(node **topRef, string strIn){
    int size=strIn.length();
    int i;
    int j=0;
    string strOut;
    char sentOut;
    char tempAry[size];
    bool err;
    for(i=0;i<size;i++, j++){
        if(strIn[i]=='('){
            push(topRef, strIn[i]);
        }
        else if(strIn[i]==')'){
            if(*topRef==NULL){
                //cout<<"Error";
                err=true;
                break;
            }
            else{
                deleteTop(topRef);
            }
        }
    }
    if((*topRef!=NULL)||(err)){
        cout<<"Error";
    }
    else if((*topRef==NULL)&&(!err)){
        cout<<"Pass";
    }
}
void push(node **topRef, char chIn){
    node *newNode=new node();
    newNode->ch=chIn;
    if(*topRef==NULL){
        *topRef=newNode;
    }
    else{
        newNode->next=*topRef;
        *topRef=newNode;
    }
}
node *pop(node **topRef){
    node *sentNode;
    if(*topRef==NULL){
        sentNode->ch='e';
    }
    else{
        sentNode=*topRef;
        *topRef=(*topRef)->next;
    }
    return sentNode;
}
void deleteTop(node **topRef){
    node *temp=*topRef;
    *topRef=(*topRef)->next;
    temp->next=NULL;
}