// Static member
#include<iostream>
using namespace std;
class numBox{
    public:
        static int round;
        static int val;

        numBox(){
            round++;
            val=val+10;
        }
        void setNum(int newVal){
            val=newVal;
        }
        void showData(){
            cout<<"Round "<<round<<endl;
            cout<<"Value "<<val<<endl<<endl;
        }
};
int numBox::round=0;
int numBox::val=100;
int main(){
    numBox box1;
    box1.showData();

    numBox box3;
    box3.setNum(900);
    box3.showData();
     
    numBox box2;
    box2.showData();
}