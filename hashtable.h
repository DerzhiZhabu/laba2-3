template <typename T>
struct HashTable{

    int size = 8;

    NodeH<T>* arr = new NodeH<T>[size];

    ~HashTable(){
        delete [] arr;
    }

    int hashFunc(string key){
        int hash_result = 0;
        for (int i = 0; i < key.size(); i++){
                hash_result = ((size - 1) * hash_result + key[i]) % size;
                hash_result = (hash_result * 2 + 1) % size;
        }
        return hash_result;
    }

    void Add(string key, T value){
        int index = hashFunc(key);
        int prev_index = index;
        
        bool new_cycle = false;
        
        while (!(index == prev_index && new_cycle)){
                if (!arr[index].state){
                    arr[index].key = key;
                    arr[index].value = value;
                    arr[index].state = true;
                    return;
                }
                else if(arr[index].key == key){
                    throw runtime_error("Key exists");
                }
                index++;
                if (index >= size){
                    index = 0;
                    new_cycle = true;
                }
        }

        Resize();
        Add(key, value);
    }

    void Resize(){
        cout << "resize" << endl;
        size *= 2;
        NodeH<T>* oldArr = arr;

        arr = new NodeH<T>[size];

        for(int i = 0; i < size / 2; i++){
                if (oldArr[i].state && !oldArr[i].deleted){
                    Add(oldArr[i].key, oldArr[i].value);
                }
        }

        delete[] oldArr;
    }

    T Get(string key){
        int index = hashFunc(key);
        int prev_index = index;
        bool new_cycle = false;
        
        while (!(index == prev_index && new_cycle)){
                if (arr[index].state && arr[index].key == key){
                    return arr[index].value;
                }
                else if (arr[index].key == key && arr[index].deleted) throw runtime_error("No such key");
                else if (!arr[index].deleted && !arr[index].state) throw runtime_error("No such key");
                index++;
                if (index >= size){
                    index = 0;
                    new_cycle = true;
                }
        }

        throw runtime_error("No such key");
    }

    void Remove(string key){
        int index = hashFunc(key);
        int prev_index = index;
        bool new_cycle = false;
        
        while (!(index == prev_index && new_cycle)){
                if (arr[index].state && arr[index].key == key){
                    if (is_same<T, List<string>>::value) arr[index].value.clear();
                    arr[index].state = false;
                    arr[index].deleted = true;
                    return;
                }
                else if (arr[index].key == key && arr[index].deleted) throw runtime_error("No such key");
                else if (!arr[index].deleted && !arr[index].state) throw runtime_error("No such key");
                
                index++;
                if (index >= size){
                    index = 0;
                    new_cycle = true;
                }
        }
        throw runtime_error("No such key");
    }
};