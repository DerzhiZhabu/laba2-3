#include "set.h"
#include <iostream>

using namespace std;

void set_union(Myset& set1, Myset& set2){
    for (int i = 0; i < set2.size; i++){
        if (set2.arr[i].state && !set2.arr[i].deleted) set1.Add(set2.arr[i].value);
    }
}

void set_cross(Myset& set1, Myset& set2){
    for (int i = 0; i < set2.size; i++){
        if (set2.arr[i].state && !set2.arr[i].deleted){
            if (set1.Get(set2.arr[i].value)){
                cout << set2.arr[i].value << ' ';
            }
        }
    }
    cout << endl;
}

void set_sub(Myset& set1, Myset& set2){
    for (int i = 0; i < set2.size; i++){
        if (set2.arr[i].state && !set2.arr[i].deleted){
            if (set1.Get(set2.arr[i].value)){
                set1.Remove(set2.arr[i].value);
            }
        }
    }
    cout << endl;
}

int main(){
    Myset set1;
    Myset set2;

    set1.Add(0);
    set1.Add(1);
    set1.Add(2);
    set1.Add(3);
    set1.Add(4);
    set1.Add(5);

    set2.Add(4);
    set2.Add(5);
    set2.Add(6);
    set2.Add(7);
    set2.Add(8);
    set2.Add(9);
    set2.Add(10);

    set1.print();
    set2.print();

    set_cross(set1, set2);

    cout << endl;


    set_union(set1, set2);

    cout << endl;

    set1.print();

    cout << endl;


    set_sub(set1, set2);

    set1.print();


}