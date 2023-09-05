// Data structure OOP
// Single link list
#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
};
class infoNode{
    public:
        int amount;
        node *currNode=new node();
        void show(node **headRef){
            node *showNode=*headRef;
            while(showNode!=NULL){
                cout<<showNode->num<<" ";
                showNode=showNode->next;
                cout<<endl;
            }
        }
        int calSum(){
            int sum=0;
            while(currNode!=NULL){
                sum=sum+currNode->num;
                currNode=currNode->next;
            }
            return sum;
        }
};
infoNode data;
void addFirst(node **headRef, int newNum);
int main(){
    node *head=NULL;
    node **headR=&head;
    for(int i=0;i<=5;i++){
        addFirst(headR, i);
    }
    int sumNode;
    sumNode=data.calSum();
    data.show(headR);
    cout<<data.amount<<endl;
    cout<<sumNode;
}

void addFirst(node **headRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*headRef!=NULL){
        newNode->next=*headRef;
    }
    *headRef=newNode;
    data.amount++;
}
