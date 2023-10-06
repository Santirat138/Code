#include<iostream>
#define MAX 10
using namespace std;
class modHash{
    public:
        int array[10];
        modHash(){
            for(int i=0;i<MAX;i++){
                array[i]=-1;
            }
        }
        void addNum(int newNum){
            int key=newNum%MAX;
            while(key<MAX){
                if(array[key]==-1){
                    array[key]=newNum;
                    break;
                }
                else if(array[key]!=-1){
                    key++;
                }
            }
        }
        int findNum(int target){
            int key=target%MAX;
            while(key<MAX){
                if(array[key]==target){
                    return array[key];
                }
                else{
                    key++;
                }
            }
            return -1;
        }
};
int main(){
    modHash mH;
    int i;
    int showNum;
    for(i=0;i<=5;i++){
        mH.addNum(i);
    }
    for(i=0;i<MAX;i++){
        cout<<mH.array[i]<<" ";
    }
}