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
