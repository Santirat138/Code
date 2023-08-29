    // e for enqueue number in to queue.|
    // d for dequeue number.|
    // p for show the first to last number.
    // n for show amount of number in queue.|
    // s for show the first and the last number in queue.|
    // x for end program.|
#include<iostream>
using namespace std;
class node{
public:
    int num;
    node *next;
};
node *first=NULL;
node **firstR=&first;
node *last=NULL;
node **lastR=&last;
int amount=0;
void enqueue(int newNum);
int dequeue();
void showAll();
int main(){
    char chIn;
    int numIn;
    int numOut;
    do{
        cout<<"Enter char : ";
        cin>>chIn;
        if(chIn=='e'){
            cout<<"Enter number : ";
            cin>>numIn;
        }
        else if(chIn=='d'){
            numOut=dequeue();
            cout<<numOut<<endl;
        }
        else if(chIn=='p'){
            showAll();
        }
        else if(chIn=='n'){
            cout<<amount<<endl;
        }
        else if(chIn=='s'){
            cout<<"The first is "<<(*firstR)->num<<endl;
            cout<<"The last is "<<(*lastR)->num<<endl;
        }
    }
    while(chIn!='x');
}
void enqueue(int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*firstR!=NULL){
        (*lastR)->next=newNode;
    }
    else{
        *firstR=newNode;
    }
    *lastR=newNode;
    amount++;
}
int dequeue(){
    if(*firstR!=NULL){
        node *temp=*firstR;
        *firstR=(*firstR)->next;
        temp->next=NULL;
        return temp->num;
    }
    else{
        return -1;
    }
}
void showAll(){
    node *show=*firstR;
    while(show!=NULL){
        cout<<show->num<<" ";
        show=show->next;
    }
}