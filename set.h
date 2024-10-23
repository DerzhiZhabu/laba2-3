#ifndef SET_H
#define SET_H

#include "list.h"

template<typename T>
struct Myset{
    List<T> bucket;

    bool add(T data){
        int index = 0;

        while(index < bucket.length){
            if (bucket[index] == data) return false;
            if (bucket[index] < data){
                bucket.insert(data, index);
                return true;
            }
        }

        bucket.push(data);

        return true;
    }

    T operator[](int index){
        return bucket[index];
    }

    int find(T data){
        return bucket.find(data);
    }

    void remove(T data){
        bucket.remove(data);
    }
};

#endif