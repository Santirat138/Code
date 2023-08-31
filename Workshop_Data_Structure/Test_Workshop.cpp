#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
};
node *head=NULL;
node **headR=&head;

int main(){
    char chIn;
    do{
        cout<<"Enter char : ";
        cin>>chIn;
        if(chIn=='a'){
            // Insert after number.
        }
        else if(chIn=='i'){
            // Insert before number.
        }
        else if(chIn=='d'){
            // Delete number.
        }
    }
    while(chIn!='e');
}
