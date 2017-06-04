/* 
 Для стека:
 add <значение> - добавление в стек значения
 del - удаление верхнего элемента стека
 get - получение верхнего элемента стека
 */

#include <iostream>
using namespace std;

template<typename type>
class Stack{
    type* stack;
    int size = 0;
public:
    Stack(int n){
        stack = new type[n];
    }
    
    void add(int value){
        stack[size] = value;
        ++size;
    }
    
    void del(){
        --size;
    }
    
    type get(){
        return stack[size-1];
    }
};

int main(){
    Stack<int> stack(6);
    stack.add(0);
    stack.add(5);
    stack.add(6);
    stack.del();
    cout << stack.get() << endl;
    stack.del();
    cout << stack.get() << endl;
    return 0;
}