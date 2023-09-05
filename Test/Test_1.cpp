#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
};
class info{
    public:
        int amount=0;
        
        int calSum(node **headRef){
            node *currNode=*headRef;
            int sum=0;
            while(currNode!=NULL){
                sum=sum+currNode->num;
                currNode=currNode->next;
            }
            return sum;
        }
};
info data;
void addHead(node **headRef, int newNum);
void show(node **headRef);
//------------------ main ------------------
int main(){
    node *head=NULL;
    node **headR=&head;
    info infoNode;
    int i;
    for(i=0;i<=5;i++){
        addHead(headR, i);
    }
    show(headR);
    int totalNum=data.calSum(headR);
    cout<<totalNum;
}
//------------------ main ------------------
void addHead(node **headRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*headRef!=NULL){
        newNode->next=*headRef;
    }
    *headRef=newNode;
    data.amount++;
}
void show(node **headRef){
    node *showNode=*headRef;
    while(showNode!=NULL){
        cout<<showNode->num<<" ";
        showNode=showNode->next;
    }
    cout<<endl;
}