    // u for push number in to stack.|
    // o for pop number.|
    // t for show top number.|
    // p for sort first to last input.|
    // n for show amount of number in stack.|
    // x for end program.
#include<iostream>
using namespace std;
class node{
public:
    int num;
    node *next;
};
int amount=0;
node *top=NULL;
node **topR=&top;
void push(int newNum);
int pop();
void showTop();
void showSort();
int main(){
    char chIn;
    int numIn;
    int numOut;
    do{
        cout<<"Enter charIn : ";
        cin>>chIn;
        if(chIn=='u'){
            cout<<"Enter number : ";
            cin>>numIn;
            push(numIn);
        }
        else if(chIn=='o'){
            numOut=pop();
            cout<<numOut<<endl;
        }
        else if(chIn=='t'){
            showTop();
        }
        else if(chIn=='p'){
            showSort();
        }
        else if(chIn=='n'){
            cout<<amount<<endl;
        }
    }
    while(chIn!='x');
}
void push(int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*topR!=NULL){
        newNode->next=*topR;
    }
    *topR=newNode;
    amount++;
}
int pop(){
    if(*topR!=NULL){
        node *temp=*topR;
        *topR=(*topR)->next;
        temp->next=NULL;
        return temp->num;
    }
    else{
        return -1;
    }
}
void showTop(){
    cout<<(*topR)->num<<endl;
}
void showSort(){
    int array[amount];
    int i;
    for(i=0;i<amount;i++){
        array[i]=pop();
    }
    for(i=amount-1;i>=0;i--){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}