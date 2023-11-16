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
            if(currNode->num==target){
                break;
            }
            else{
                currNode=currNode->next;
            }
        }
        cout<<"Not found."<<endl;
        return nullNode;
    }
    else{
        cout<<"Head is NULL."<<endl;
        return nullNode;
    }
    return currNode;
}
/*-------------------- main --------------------*/
int main(){
    linkList list1;
    for(int i=0;i<6;i++){
        list1.addFirst(i);
    }
    list1.show();
    node *find=list1.findNum(24);
    cout<<find->num;
}
/*-------------------- main --------------------*/
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}