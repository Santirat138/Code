#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
        node(int numIn){
            num=numIn;
            prev=NULL;
            next=NULL;
        }
};
node *nullNode=new node(-1);
void connectNode(node *node1, node *node2);
class linkList{
    public:
        node *head=NULL;
        node *tail=NULL;
        node **headRef;
        node **tailRef;
        linkList();
        bool sameNum(int numIn);
        void addFirst(int newNum);
        void show();
        node *findNum(int target);
        void deleteNum(int target);
        void swapNum(int num1, int num2);
};
linkList::linkList(){
    headRef=&head;
    tailRef=&tail;
}
bool linkList::sameNum(int numIn){
    bool status=false;
    if(*headRef!=NULL){
        node *currNode=*headRef;
        while(currNode!=NULL){
            if(currNode->num==numIn){
                status=true;
                break;
            }
            else{
                currNode=currNode->next;
            }
        }
    }
    else{
        status=false;
    }
    return status;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((*headRef==NULL)&&(*tailRef==NULL)){
        *headRef=newNode;
        *tailRef=newNode;
    }
    else if((*headRef!=NULL)&&(*tailRef!=NULL)){
        if(sameNum(newNum)==false){
            connectNode(newNode, *headRef);
            *headRef=newNode;
        }
        else if(sameNum(newNum)==true){
            cout<<"Same number."<<endl;
        }
    }
}
void linkList::show(){
    node *currNode=*headRef;
    cout<<endl<<"Head --> Tail."<<endl;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->next;
    }
    currNode=*tailRef;
    cout<<endl<<endl<<"Tail --> Head."<<endl;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->prev;
    }
    cout<<endl<<endl;
}
node *linkList::findNum(int target){
    node *currNode=nullNode;
    if(*headRef!=NULL){
        currNode=*headRef;
        while(currNode!=NULL){
            if(currNode->next!=NULL){
                if(currNode->num==target){
                    break;
                }
                else{
                    currNode=currNode->next;
                }
            }
            else if(currNode->next==NULL){
                cout<<"Not found."<<endl;
                return nullNode;
            }
        }
    }
    else{
        cout<<"Error."<<endl;
        return nullNode;
    }
    return currNode;
}
void linkList::deleteNum(int target){
    node *targetNode=findNum(target);
    if(targetNode->num!=-1){
        if(targetNode==*headRef){
            *headRef=targetNode->next;
            (*headRef)->prev=NULL;
            targetNode->next=NULL;
        }
        else if(targetNode==*tailRef){
            *tailRef=targetNode->prev;
            (*tailRef)->next=NULL;
            targetNode->prev=NULL;
        }
        else if((targetNode!=*headRef)&&(targetNode!=*tailRef)){
            node *pTemp=targetNode->prev;
            node *nTemp=targetNode->next;
            targetNode->prev=NULL;
            targetNode->next=NULL;
            pTemp->next=nTemp;
            nTemp->prev=pTemp;
        }
    }
    else{
        cout<<"Not found."<<endl;
    }
}
void linkList::swapNum(int num1, int num2){
    node *temp=nullNode;
    node *node1=findNum(num1);
    node *node2=findNum(num2);
    if((node1!=nullNode)&&(node2!=nullNode)){
        temp->num=node1->num;
        node1->num=node2->num;
        node2->num=temp->num;
    }
    else{
        cout<<"Can't swap."<<endl;
    }
}
/*-------------------- main --------------------*/
int main(){
    linkList list1;
    for(int i=0;i<6;i++){
        list1.addFirst(i);
    }
    list1.show();
}
/*-------------------- main --------------------*/
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}