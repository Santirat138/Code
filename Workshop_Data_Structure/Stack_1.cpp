#include<iostream>
using namespace std;
class node{
public:
    char chIn;
    node *next;
};
struct blanket{
    int openBk=0;
    int closeBk=0;
}bnk;

void push(node **topRef, char newCh);
void checkOpCl(node **topRef);
node *pop(node **topRef);
//--------------main--------------
int main(){
    node *top=NULL;
    node **topR=&top;
    string strIn;

    cin>>strIn;
    int strSize=strIn.length();
    int i;
    for(i=0;i<strSize;i++){
        push(topR, strIn[i]);
    }
    checkOpCl(topR);
}
//--------------main--------------
void push(node **topRef, char newCh){
    node *newNode=new node();
    newNode->chIn=newCh;
    if(*topRef==NULL){
        *topRef=newNode;
    }
    else{
        newNode->next=*topRef;
        *topRef=newNode;
    }
}
void checkOpCl(node **topRef){
    node *check=*topRef;
    while(check!=NULL){
        if(check->chIn=='('){
            bnk.openBk++;
        }
        else if(check->chIn==')'){
            bnk.closeBk++;
        }
        check=check->next;
    }
    if(bnk.openBk==bnk.closeBk){
        cout<<"Pass"<<endl;
    }
    else{
        cout<<"Error"<<endl;
    }
}
node *pop(node **topRef){
    node *temp=*topRef;
    *topRef=(*topRef)->next;
    return temp;
}