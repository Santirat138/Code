#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
};

int main(){
    node *head=NULL;
    node **headR=&head;
    node *tail=NULL;
    node **tailR=&tail;
    
}