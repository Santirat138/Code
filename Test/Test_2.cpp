// Static method
#include<iostream>
using namespace std;
class numBox{
    public:
        static int num;

        numBox(){
            cout<<"Call"<<endl;
            num++;
        }
        static int getNum(){
            return num;
        }
        static void numUp(){
            num=num*10;
        }
};
int numBox::num=2;
int main(){
    cout<<"Start value "<<numBox::getNum();
    numBox box1;
    numBox box2;
    box1.numUp();
    cout<<"Total value "<<numBox::getNum();
}