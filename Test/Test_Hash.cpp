#include<iostream>
#define MAX 10
using namespace std;
class HashTable{
    private:
        int table[MAX];
        int hash(int key){
            return key%MAX;
        }
    public:
        HashTable(){
            for(int i=0;i<MAX;i++){
                table[i]=-1;
            }
        }
        void insert(int key, int value){
            int index=hash(key);
            table[index]=value;
        }
        int search(int key){
            int index=hash(key);
            if(table[index]!=-1){
                return table[index];
            }
            else{
                return -1;
            }
        }
        
};
int main(){
    HashTable ht;
    ht.insert(3, 1);
    
}