#include<iostream>
using namespace std;
class node{
public:
    int num;
    node *next;
};
int amount=0;
node *findNode(node **headRef, int target);
node *findPrevNode(node **headRef, int target);
void insertBefNode(node **headRef, node **tailRef, int befNum, int newNum);
void insertAftNode(node **headRef, node **tailRef, int aftNum, int newNum);
void showAll(node **headRef);
void delNode(node **headRef, node **tailRef, int target);
bool isNumTrue(node **headRef, int checkNum);
int main(){
    node *head=NULL;
    node *tail=NULL;
    node **head_ref=&head;
    node **tail_ref=&tail;
    char chIn;
    int newNum, befNum, aftNum, delNum;
    do{
        chIn=getchar();
        if(chIn=='I'){
            cin>>newNum>>befNum;
            insertBefNode(head_ref, tail_ref, befNum, newNum);
            
        }
        else if(chIn=='A'){
            cin>>newNum>>aftNum;
            insertAftNode(head_ref, tail_ref, aftNum, newNum);
        }
        else if(chIn=='D'){
            cin>>delNum;
            delNode(head_ref, tail_ref, delNum);
        }
        else if(chIn=='E'){
            break;
        }
    }
    while(true);
}
node *findNode(node **headRef, int target){
    node *checkNode=*headRef;
    bool status;
    while(checkNode!=NULL){
        if(checkNode->num==target){
            status=true;
            break;
        }
        else{
            status=false;
            checkNode=checkNode->next;
        }
    }
    if(!status){
        checkNode=NULL;
    }
    return checkNode;
}
node *findPrevNode(node **headRef, int target){
    node *prevNode=*headRef;
    node *currNode=findNode(headRef, target);
    if(currNode==*headRef){
        prevNode=NULL;
    }
    else{
        while(prevNode!=currNode){
            if(prevNode->next==currNode){
                break;
            }
            else{
                prevNode=prevNode->next;
            }
        }
    }
    return prevNode;
}
void insertBefNode(node **headRef, node **tailRef, int befNum, int newNum){
    node *newNode=new node();
    node *prevBef=findPrevNode(headRef, befNum);
    node *befNode=findNode(headRef, befNum);
    bool check=isNumTrue(headRef, newNum);
    if(check){
        newNode->num=newNum;
        if(*headRef==NULL){
            *headRef=newNode;
            *tailRef=newNode;
        }
        else{
            if((befNode!=NULL)&&(prevBef!=NULL)){
                newNode->next=befNode;
                prevBef->next=newNode;
            }
            else if((befNode==*headRef)&&(prevBef==NULL)){
                newNode->next=*headRef;
                *headRef=newNode;
            }
            else{
                (*tailRef)->next=newNode;
                *tailRef=newNode;
            }
        }
        amount++;
        showAll(headRef);
    }
}
void showAll(node **headRef){
    node *startNode=*headRef;
    while(startNode!=NULL){
        cout<<startNode->num<<" ";
        startNode=startNode->next;
    }
    cout<<endl;
}
void insertAftNode(node **headRef, node **tailRef, int aftNum, int newNum){
    node *aftNode=findNode(headRef, aftNum);
    node *newNode=new node();
    node *nextAft;
    bool check=isNumTrue(headRef, newNum);
    if(check){
        newNode->num=newNum;
        if(aftNode==NULL){
            nextAft=NULL;
        }
        else if(aftNode!=NULL){
            nextAft=aftNode->next;
        }
        if(*headRef==NULL){
            *headRef=newNode;
            *tailRef=newNode;
        }
        else{
            if((aftNode==*tailRef)&&(nextAft==NULL)){
                (*tailRef)->next=newNode;
                *tailRef=newNode;
            }
            else if((aftNode!=NULL)&&(nextAft!=NULL)){
                newNode->next=nextAft;
                aftNode->next=newNode;
            }
            else{
                (*tailRef)->next=newNode;
                *tailRef=newNode;
            }
        }
        amount++;
        showAll(headRef);
    }
}
void delNode(node **headRef, node **tailRef, int target){
    node *delNode=findNode(headRef, target);
    node *prevDel;
    node *nextDel;
    if((amount>1)&&(delNode!=NULL)){
        if(delNode==*headRef){
            *headRef=(*headRef)->next;
            delNode->next=NULL;
        }
        else if(delNode==*tailRef){
            prevDel=findPrevNode(headRef, target);
            *tailRef=prevDel;
            prevDel->next=NULL;
        }
        else if((delNode!=*headRef)&&(delNode!=*tailRef)){
            prevDel=findPrevNode(headRef, target);
            nextDel=delNode->next;
            prevDel->next=nextDel;
            delNode->next=NULL;
        }
        amount--;
        showAll(headRef);
    }
}
bool isNumTrue(node **headRef, int checkNum){
    node *checkNode=findNode(headRef, checkNum);
    bool status;
    if(checkNode!=NULL){
        status=false;
    }
    else if(checkNode==NULL){
        status=true;
    }
    else if(*headRef==NULL){
        status=true;
    }
    return status;
}