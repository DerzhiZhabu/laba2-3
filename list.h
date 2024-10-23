#ifndef NODE_D
#define NODE_D

template <typename T>
struct NodeD{
    T data;
    NodeD* next = nullptr;
    NodeD* prev = nullptr;
};

#endif

#ifndef LIST_H
#define LIST_H

template <typename T>
struct List{
    int length = 0;
    NodeD<T>* head = new NodeD<T>;
    NodeD<T>* tail = head;

    void push(T data){
        NodeD<T>* new_node = new NodeD<T>{data, nullptr, tail};
        tail -> next = new_node;
        tail = new_node;
        length += 1;
    }

    void pushf(T data){
        insert(data, 0);
    }

    T operator[](int index){
        return get(index);
    }

    T pop(){
        if (length == 0) throw runtime_error("List is empty");

        NodeD<T>* last = tail;

        T data = last -> data;
        tail -> prev -> next = nullptr;
        tail = tail -> prev;

        length --;

        delete last;
        return data;
    }

    T get(int index){
        if (index >= length || index < 0) throw runtime_error("Out of range");

        NodeD<T>* tek = head -> next;
        while (index != 0){
            tek = tek -> next;
            index --;
        }
        return tek -> data;
    }

    int find(T data){
        
        for (int index = 0; index < length; index++){
            if (get(index) == data){
                return index;
            }
        }

        return -1;
    }

    void del(int index){
        if (index >= length || index < 0) throw runtime_error("Out of range");
        if (index == length - 1) pop();

        NodeD<T>* tek = head -> next;
        while (index != 0){
            tek = tek -> next;
            index --;
        }

        NodeD<T>* pred = tek -> prev;
        pred -> next = tek -> next;
        pred -> next -> prev = pred;

        delete tek;
        length --;

    }

    void remove(T data){
        int index = find(data);

        if(index == -1) throw runtime_error("No value");

        del(index);
    }

    void insert(T data, int index){
        if (index > length || index < 0) throw runtime_error("Out of range");

        if (index == length){
            push(data);
        }

        else if (index >= 0){
            NodeD<T>* new_node = new NodeD<T>;
            new_node -> data = data;
            NodeD<T>* tek = head -> next;

            while (index != 0){
                tek = tek -> next;
                index --;
            }

            new_node -> prev = tek -> prev;
            tek -> prev -> next = new_node;
            tek -> prev = new_node;
            new_node -> next = tek;
            length++;
        }

    }

    void clear(){
        NodeD<T>* prev;
        NodeD<T>* tek = tail;
        while (tek != head){
            prev = tek ->prev;
            delete tek;
            tek = prev;
        }
        delete tek;
    }
};

#endif