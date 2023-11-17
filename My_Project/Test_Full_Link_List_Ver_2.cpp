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
        int amount=0;
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
        node *findPos(int pos);
        void insertAt(int newNum, int numAft, int numBef);
        void insertPos(int newNum, int posAft, int posBef);
        void deletePos(int delPos);
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
    amount++;
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
        amount--;
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
node *linkList::findPos(int pos){
    if(*headRef!=NULL){
        if((pos<=amount)&&(pos>0)){
            node *currNode=*headRef;
            int walk=0;
            while(walk!=pos-1){
                currNode=currNode->next;
                walk++;
            }
            return currNode;
        }
        else{
            cout<<"Error"<<endl;
        }
    }
    else{
        cout<<"Error."<<endl;
    }
    return nullNode;
}
void linkList::insertAt(int newNum, int numAft, int numBef){
    if((*headRef!=NULL)&&(*headRef!=*tailRef)){
        node *nodeAft=findNum(numAft);
        node *nodeBef=findNum(numBef);
        if(sameNum(newNum)==false){
            node *newNode=new node(newNum);
            if(nodeAft->next==nodeBef){
                connectNode(nodeAft, newNode);
                connectNode(newNode, nodeBef);
            }
            else{
                cout<<"Can't insert."<<endl;
            }
        }
        else{
            cout<<"Same number."<<endl;
        }
    }
    else{
        cout<<"Can't insert."<<endl;
    }
}
void linkList::insertPos(int newNum, int posAft, int posBef){
    // If pos<0 --> add first.
    // If pos>amount --> add last.
    if((*headRef!=NULL)&&(*headRef!=*tailRef)){
        if(sameNum(newNum)==false){
            int walk=0;
            node *newNode=new node(newNum);
            node *nodeWalk=*headRef;
            node *nodeAft;
            node *nodeBef;
            if((posBef-posAft==1)&&(posAft>0)&&(posBef<=amount)){
                while(nodeWalk!=NULL){
                    if(walk<posAft){
                        nodeWalk=nodeWalk->next;
                        walk++;
                    }
                    else if(walk==posAft){
                        nodeAft=nodeWalk->prev;
                        nodeBef=nodeWalk;
                        connectNode(newNode, nodeBef);
                        connectNode(nodeAft, newNode);
                        amount++;
                        break;
                    }
                }
            }
            else if(posAft<=0){
                addFirst(newNum);
            }
            else if(posBef>amount){
                connectNode(*tailRef, newNode);
                *tailRef=newNode;
            }
        }
        else{
            cout<<"Can't insert."<<endl;
        }
    }
    else{
        cout<<"Can't insert."<<endl;
    }
}
void deletePos(int delPos){
    node *delNode=findPos(delPos);
    
}
/*-------------------- main --------------------*/
int main(){
    linkList list1;
    for(int i=0;i<6;i++){
        list1.addFirst(i);
    }
    list1.insertPos(100, 0, 1);
    list1.show();
}
/*-------------------- main --------------------*/
void connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}