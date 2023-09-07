#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
};
class info{
    public:
        float avg;
        int sum;
        int amount=0;
        void calSum(node **headRef){
            node *currNode=*headRef;
            sum=0;
            while(currNode!=NULL){
                sum=sum+currNode->num;
                currNode=currNode->next;
            }
        }
        void calAvg(){
            avg=sum/amount;
        }

};
info data;
bool isSameNum(node **headRef, int checkNum);
void connectNode(node *node1, node *node2);
void addHead(node **headRef, node **tailRef, int newNum);
void show(node **headRef, node **tailRef);
node *findNum(node **headRef, int target);
//------------------ main ------------------
int main(){
    node *head=NULL;
    node **headR=&head;
    node *tail=NULL;
    node **tailR=&tail;
    info infoNode;
    int i;
    for(i=0;i<=5;i++){
        addHead(headR, tailR, i);
    }
    show(headR, tailR);
    data.calSum(headR);
    int totalNum=data.sum;
    cout<<totalNum;
}
//------------------ main ------------------
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}
void addHead(node **headRef, node **tailRef, int newNum){
    if(!isSameNum(headRef, newNum)){
        node *newNode=new node();
        newNode->num=newNum;
        if((*headRef!=NULL)&&(*tailRef!=NULL)){
            connectNode(newNode, *headRef);
        }
        else if((*headRef==NULL)||(*tailRef==NULL)){
            *tailRef=newNode;
        }
        *headRef=newNode;
        data.amount++;
    }
    else{
        cout<<"Can't add "<<newNum<<endl;
    }
}
void show(node **headRef, node **tailRef){
    node *startNode=*headRef;
    node *endNode=*tailRef;
    cout<<"Head --> Tail."<<endl;
    while(startNode!=NULL){
        cout<<startNode->num<<" ";
        startNode=startNode->next;
    }
    cout<<endl<<endl<<"Tail --> Head."<<endl;
    while(endNode!=NULL){
        cout<<endNode->num<<" ";
        endNode=endNode->prev;
    }
    cout<<endl;
}
bool isSameNum(node **headRef, int checkNum){
    bool status=false;
    if(*headRef!=NULL){
        node *checkNode=*headRef;
        while(checkNode!=NULL){
            if(checkNode->num==checkNum){
                status=true;
                break;
            }
            else{
                checkNode=checkNode->next;
            }
        }
        return status;
    }
    else if(*headRef==NULL){
        return status;
    }
}
node *findNum(node **headRef, int target){
    if(*headRef!=NULL){
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
    else{
        cout<<"Not found."<<endl;
        return NULL;
    }
}