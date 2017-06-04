/*
 Для очереди:
 add <значение> - добавление в конец очереди значения
 get - получение значения элемента в начале очереди
 del - удаление элемента из начала очереди
*/
#include <iostream>
using namespace std;

template <typename type>
class Queue{
    type* queue;
    int size = 0;
public:
    Queue(int n){
        queue = new type[n];
    }
    
    void add(type value){
        queue[size] = value;
        ++size;
    }
    
    type get(){
        return queue[0];
    }
    
    void del(){
        for (int i = 0; i < size - 1; ++i){
            queue[i] = queue[i+1];
        }
    }
};

int main(){
    Queue<int> queue(6);
    queue.add(4);
    queue.add(6);
    queue.add(9);
    cout << queue.get() << endl;
    queue.del();
    cout << queue.get() << endl;
    return 0;
}