#ifndef STECK_H
#define STECK_H

template <typename T>
struct NodeS{
    T data;
    NodeS* next = nullptr;
};

template <typename T>
struct Stack{
    int length = 0;
    NodeS<T>* tail = nullptr;

    void push(T data){
        NodeS<T>* new_node = new NodeS<T>{data, tail};
        tail = new_node;
        length += 1;
    }

    T pop(){
        if (length == 0) throw runtime_error("Stack is empty");

        NodeS<T>* new_node = tail->next;
        length -= 1;

        T value = tail->data;
        
        delete tail;
        tail = new_node;
        return value;
    }

    void clear(){
        while (length != 0){
            pop();
        }
    }
};

#endif