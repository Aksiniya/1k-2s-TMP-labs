/*
 Для списка:
 add <номер> <значение> - добавление нового элемента с определенным значением в требуемую позицию.
 get <номер> - получение значения элемента в указанной позиции.
 del <номер> - удаление элемента в указанной позиции.
 */
#include <iostream>
#include <vector>
using namespace std;

template<typename type>
class List{
    int N;
    type* list;
    int size = 0;
public:
    List(int n) {
        list = new type[n];
    }
    
    void add(int pos, type value){
        list[pos] = value;
        ++size;
    }
    
    type get(int pos){
        return list[pos];
    }
    
    void del(int pos){
        for (int i = pos; i < size - 1; ++i){
            list[i] = list[i+1];
        }
        --size;
    }
};

int main(){
    List<int> list(7);
    list.add(0, 1);
    list.add(1, 2);
    list.add(2, 3);
    list.del(1);
    cout << list.get(1) << endl;
    list.add(1, 4);
    cout << list.get(1) << endl;
    return 0;
}