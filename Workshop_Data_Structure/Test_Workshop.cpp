#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
};
node *head=NULL;
node **headR=&head;
bool isSameNum(int numCheck);
void addFirst(int newNum);
void addLast(int newNum);
node *findNum(int target);
void show();
int main(){
    char chIn;
    int newNumIn;
    int numPos;
    do{
        cout<<"Enter char : ";
        cin>>chIn;
        if(chIn=='i'){
                // Insert before number.
            cout<<"Enter new number and insert before number : ";
            cin>>newNumIn>>numPos;
        }
        else if(chIn=='a'){
                // Insert after number.
            cout<<"Enter new number and insert after number : ";
            cin>>newNumIn>>numPos;
        }
        else if(chIn=='d'){
                // Delete number.
            cout<<"Enter number that want to delete : ";

        }
    }
    while(chIn!='e');
}
bool isSameNum(int numCheck){
        // True --> Have same number.
        // False --> Don't have same number.
    node *checkNode=*headR;
    bool status=false;
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
void addFirst(int newNum){
    if(!isSameNum(newNum)){
        node *newNode=new node();
        newNode->num=newNum;
        if(*headR!=NULL){
            newNode->next=*headR;
        }
        *headR=newNode;
    }
    else if(isSameNum(newNum)){
        cout<<"Number "<<newNum<<" is already exist."<<endl;
    }
}
void addLast(int newNum){
    if(!isSameNum(newNum)){
        node *newNode=new node();
        newNode->num=newNum;
        if(*headR!=NULL){
            node *lastNode=*headR;
            while(lastNode!=NULL){
                if(lastNode->next==NULL){
                    break;
                }
                else{
                    lastNode=lastNode->next;
                }
            }
            lastNode->next=newNode;
        }
        else if(*headR==NULL){
            *headR=newNode;
        }
    }
    else if(isSameNum(newNum)){
        cout<<"Number "<<newNum<<" is already exist."<<endl;
    }
}
node *findNum(int target){
    node *currNode=*headR;
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
void show(){
    node *showNode=*headR;
    cout<<"Head --> Tail."<<endl;
    while(showNode!=NULL){
        cout<<showNode->num<<" ";
        showNode=showNode->next;
    }
}