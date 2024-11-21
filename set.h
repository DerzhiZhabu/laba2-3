#ifndef SET_H
#define SET_H

#include <iostream>

using namespace std;

template <typename T>
struct NodeS{
    int key;
    T value;
    bool state = false;
    bool deleted = false;
};


struct Myset{


    int size = 8;

    NodeS<int>* arr = new NodeS<int>[size];

    ~Myset(){
        delete [] arr;
    }

    int hashFunc(int key){
        int hash_result = 0;
        
        hash_result = key % size;

        return hash_result;
    }

    void print(){
        for (int i = 0; i < size; i++){
            if (arr[i].state && !arr[i].deleted) cout << arr[i].value << ' '; 
        }
        cout << endl;
    }

    void Add(int value){
        int index = hashFunc(value);
        int key = value;
        
        while (index < size){
            if (!arr[index].state){
                arr[index].key = key;
                arr[index].value = value;
                arr[index].state = true;
                return;
            }
            else if(arr[index].key == key){
                return;
            }
            index++;
        }

        Resize();
        Add(value);
    }

    void Resize(){
        size *= 2;
        NodeS<int>* oldArr = arr;

        arr = new NodeS<int>[size];

        for(int i = 0; i < size / 2; i++){
            if (oldArr[i].state && !oldArr[i].deleted){
                Add(oldArr[i].value);
            }
        }

        delete[] oldArr;
    }

    bool Get(int key){
        int index = hashFunc(key);
        
        while (index < size){
            if (arr[index].state && arr[index].key == key){
                return true;
            }
            else if (arr[index].key == key && arr[index].deleted) break;
            else if (!arr[index].deleted && !arr[index].state) break;
            index++;
        }

        return false;
    }

    void Remove(int key){
        int index = hashFunc(key);
        while (index < size){
            if (arr[index].state && arr[index].key == key){
                arr[index].state = false;
                arr[index].deleted = true;
                return;
            }
            else if (arr[index].key == key && arr[index].deleted) throw runtime_error("No such key");
            else if (!arr[index].deleted && !arr[index].state) throw runtime_error("No such key");
            index++;
        }
        return;
    }
};

#endif