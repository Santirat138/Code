#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prec;
        node *next;
};
struct nodeData{
    int amount=0;
    int max;
    int min;
    double avg=0;
    int sum=0;
}info;
node *nullNode=new node();
void connectNode(node *node1, node *node2);
bool isSameNum(node **headRef, int numCheck);
void addFirst(node **headRef, node **tailRef, int newNum);
void addLast(node **headRef, node **tailRef, int newNum);
void showHT(node **headRef, node **tailRef);
node *findNum(node **headRef, node **tailRef, int target);
void insertBef(node **headRef, node **tailRef, int numBef, int newNum);
void insertAft(node **headRef, node **tailRef, int numAft, int newNum);
void deleteNum(node **headRef, node **tailRef, int target);
void swapNum(node **headRef, node **tailRef, int num1, int num2);
void onlyNum(node **headRef, node **tailRef, int num);
void maxNum(node **headRef);
void minNum(node **headRef);
void avg(node **headRef);
void sum(node **headRef);
void bbSort(node **headRef, node **tailRef);
int main(){
    node *head=NULL;
    node *tail=NULL;
    node **headR=&head;
    node **tailR=&tail;
    int i;
    for(i=0;i<=5;i++){
        addFirst(headR, tailR, i);
    }
    showHT(headR, tailR);
}
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prec=node1;
}
bool isSameNum(node **headRef, int numCheck){
        // True --> Same number.
        // False --> Not same number.
    bool status=false;
    node *checkNode=*headRef;
    while(checkNode!=NULL){
        if(checkNode->num==numCheck){
            status=true;
            break;
        }
        else{
            checkNode=checkNode->next;
        }
    }
    return status;
}
void addFirst(node **headRef, node **tailRef, int newNum){
    if(!isSameNum(headRef, newNum)){
        node *newNode=new node();
        newNode->num=newNum;
        if((*headRef==NULL)&&(*tailRef==NULL)){
            *headRef=newNode;
            *tailRef=newNode;
        }
        else{
            connectNode(newNode, *headRef);
            *headRef=newNode;
        }
        info.amount++;
    }
    else if(isSameNum(headRef, newNum)){
        cout<<newNum<<" is already exist."<<endl;
    }
}
void addLast(node **headRef, node **tailRef, int newNum){
    if(!isSameNum(headRef, newNum)){
        node *newNode=new node();
        newNode->num=newNum;
        if((*headRef==NULL)&&(*tailRef==NULL)){
            *headRef=newNode;
            *tailRef=newNode;
        }
        else{
            connectNode(*tailRef, newNode);
            *tailRef=newNode;
        }
        info.amount++;
    }
    else if(isSameNum(headRef, newNum)){
        cout<<newNum<<" is already exist."<<endl;
    }
}
void showHT(node **headRef, node **tailRef){
    node *startNode=*headRef;
    node *endNode=*tailRef;
    cout<<endl<<"Head --> Tail."<<endl;
    while(startNode!=NULL){
        cout<<startNode->num<<" ";
        startNode=startNode->next;
    }
    cout<<endl<<endl<<"Tail --> Head."<<endl;
    while(endNode!=NULL){
        cout<<endNode->num<<" ";
        endNode=endNode->prec;
    }
    cout<<endl<<"_______________________"<<endl;
}
node *findNum(node **headRef, node **tailRef, int target){
    nullNode->num=-1;
    node *currNode=*headRef;
    while(currNode!=NULL){
        if(currNode->num==target){
            break;
        }
        else if(currNode->num!=target){
            currNode=currNode->next;
            if(currNode==NULL){
                currNode=nullNode;
                break;
            }
        }
    }
    return currNode;
}
void insertBef(node **headRef, node **tailRef, int numBef, int newNum){
    if(!isSameNum(headRef, newNum)){
        node *befNode=findNum(headRef, tailRef, numBef);
        if(befNode->num!=-1){
            node *newNode=new node();
            newNode->num=newNum;
            if(befNode==*headRef){
                connectNode(newNode, *headRef);
                *headRef=newNode;
            }
            else if(befNode!=*headRef){
                node *precBef=befNode->prec;
                connectNode(newNode, befNode);
                connectNode(precBef, newNode);
            }
            info.amount++;
        }
        else if(befNode->num==-1){
            cout<<"Can't find number "<<numBef<<"."<<endl;
        }
    }
    else if(isSameNum(headRef, newNum)){
        cout<<newNum<<" is already exist."<<endl;
    }
}
void insertAft(node **headRef, node **tailRef, int numAft, int newNum){
    if(!isSameNum(headRef, newNum)){
        node *aftNode=findNum(headRef, tailRef, numAft);
        if(aftNode->num!=-1){
            node *newNode=new node();
            newNode->num=newNum;
            if(aftNode==*tailRef){
                connectNode(*tailRef, newNode);
                *tailRef=newNode;
            }
            else if(aftNode!=*tailRef){
                node *nextAft=aftNode->next;
                connectNode(newNode, nextAft);
                connectNode(aftNode, newNode);
            }
            info.amount++;
        }
        else if(aftNode->num==-1){
            cout<<"Can't find number "<<numAft<<"."<<endl;
        }
    }
    else if(isSameNum(headRef, newNum)){
        cout<<newNum<<" is already exist."<<endl;
    }
}
void deleteNum(node **headRef, node **tailRef, int target){
    node *delNode=findNum(headRef, tailRef, target);
    if(delNode->num==-1){
        cout<<"Can't delete "<<target<<"."<<endl;
    }
    else if(delNode->num!=-1){
        if(delNode==*headRef){
            *headRef=(*headRef)->next;
            (*headRef)->prec=NULL;
            delNode->next=NULL;
        }
        else if(delNode==*tailRef){
            *tailRef=(*tailRef)->prec;
            (*tailRef)->next=NULL;
            delNode->prec=NULL;
        }
        else if((delNode!=*headRef)&&(delNode!=*tailRef)){
            node *befDel=findNum(headRef, tailRef, target)->prec;
            node *nextDel=findNum(headRef, tailRef, target)->next;
            connectNode(befDel, nextDel);
            delNode->prec=NULL;
            delNode->next=NULL;
        }
        info.amount--;
    }
}
void swapNum(node **headRef, node **tailRef, int num1, int num2){
    node *node1=findNum(headRef, tailRef, num1);
    node *node2=findNum(headRef, tailRef, num2);
    node *temp=new node();
    temp->num=node1->num;
    node1->num=node2->num;
    node2->num=temp->num;
}
void onlyNum(node **headRef, node **tailRef, int num){
    node *nodeRem=findNum(headRef, tailRef, num);
    if(nodeRem->num!=-1){
        node *precNode=findNum(headRef, tailRef, num)->prec;
        node *nextNode=findNum(headRef, tailRef, num)->next;
        if(nodeRem==*headRef){
            *tailRef=nodeRem;
            nextNode->prec=NULL;
            nodeRem->next=NULL;
        }
        else if(nodeRem==*tailRef){
            *headRef=nodeRem;
            precNode->next=NULL;
            nodeRem->prec=NULL;
        }
        else if((nodeRem!=*headRef)&&(nodeRem!=*tailRef)){
            *headRef=nodeRem;
            *tailRef=nodeRem;
            precNode->next=NULL;
            nextNode->prec=NULL;
            nodeRem->prec=NULL;
            nodeRem->next=NULL;
        }
        else if((nodeRem==*headRef)&&(nodeRem==*tailRef)){
            cout<<"Already has 1 node."<<endl;
        }
        info.amount=1;
    }
    else if(nodeRem->num==-1){
        cout<<"Can't find number "<<num<<"."<<endl;
    }
}
void maxNum(node **headRef){
    if(*headRef!=NULL){
        node *maxNode=*headRef;
        node *currNode=*headRef;
        while(currNode!=NULL){
            if(maxNode->num<currNode->num){
                maxNode=currNode;
            }
            else{
                currNode=currNode->next;
            }
        }
        info.max=maxNode->num;
    }
    else if(*headRef==NULL){
        cout<<"Head is empty."<<endl;
    }
}
void minNum(node **headRef){
    if(*headRef!=NULL){
        node *minNode=*headRef;
        node *currNode=*headRef;
        while(currNode!=NULL){
            if(minNode->num>currNode->num){
                minNode=currNode;
            }
            else{
                currNode=currNode->next;
            }
        }
        info.min=minNode->num;
    }
    else if(*headRef==NULL){
        cout<<"Head is empty."<<endl;
    }
}
void avg(node **headRef){
    info.avg=info.sum/info.amount;
}
void sum(node **headRef){
    node *currNode=*headRef;
    while(currNode!=NULL){
        info.sum=info.sum+currNode->num;
        currNode=currNode->next;
    }
}
void bbSort(node **headRef, node **tailRef){
    int i, j;
    node *currNode=*headRef;
    for(i=info.amount;i>0;i--){
        for(j=0;j<i;j++){
            if(currNode->num>currNode->next->num){
                swapNum(headRef, tailRef, currNode->num, currNode->next->num);
            }
        }
    }
}