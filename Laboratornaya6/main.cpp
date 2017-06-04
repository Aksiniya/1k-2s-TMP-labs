/*
 
 Шаблонныйкласс для реализации очереди с приоритетами.
 
 Задача:
 Реализовать шаблонный класс и шаблонные методы для работы с очередью с приоритетами.
 
 Входные и выходные данныые такие же, как  для очереди с приоритетами без шаблонов.
 
 N - число команд для очереди с приоритетами.
 add <число> - добавление числа в очередь с приоритетами
 del - удаление корневого элемента из очереди
 get - вывод на печать в стандартный поток вывода значения корневого элемента очереди.
 
 
 Пример:
 Входные данные:
 3
 add 1.1
 add 0.9
 get
 
 Выходные данные
 0.9
 */

/* Реализация очереди с приоритетами
 Задача: реализовать очередь с приотритетами /=(двичное дерево, сбалансированное)=/ (лучше всего реализовывать в виде массива, где индексы сныовей n-ого узла равны 2n+1 и 2n+2 (для левого и проавого сына соответственно)).
 
 Входные данные:
 N - количество операций для данной очереди.
 [
 [последовательность
 [операций
 [
 [
 
 Операции:
 add<значение> - добавление элемента в очередь
 del - удаление минимального
 get -  вывод минимального элемента
 
 Выходные данные:
 раезультат введенных данны (выдача опреации get)
 
 пример:
 5
 add 3
 add 2
 del
 get
 add 4
 get
 
 Выходные данне:
 3
 3
 */

#include <iostream>
using namespace std;

template <typename valueType>
class Priority_Queue{
    valueType* _Queue;
    int N;
    int Q_size = 0;
public:
    Priority_Queue(int n){
        _Queue = new valueType[n];
        N = n;
    }
    
    void Add(valueType value){
        
        for(int i = 0; i < Q_size; ++i){
            if(value < _Queue[i]){
                for (int j = Q_size; j > i; --j){
                    _Queue[j] = _Queue[j-1];
                }
                _Queue[i] = value;
                ++Q_size;
                return;
            }
        }
        
        _Queue[Q_size] = value;
        ++Q_size;
    }
    
    void Del(){
        for(int i = 0; i < Q_size; ++i){
            _Queue[i] = _Queue[i+1];
        }
        --Q_size;
    };
    
    void PrintMinimal(){
        cout << _Queue[0] << endl;
    }
    
    int GetQSize(){
        return Q_size;
    }
    
    void PrintQ(){
        for(int i = 0; i < Q_size; ++i){
            cout << _Queue[i] << endl;
        }
    }
    
};

template <typename valueType>
void PrintTask(Priority_Queue<valueType>& P) {
    int operationNum; //для выбора операции
    
    if(P.GetQSize()>0){
        cout << "Доступные операции:\n1. Добавление элемента;\n2.Удаление элемента;\
        \n3.Вывод минимального элемента;" << endl;
        cout << "Введите номер операции:" << endl;
        cin >> operationNum;
        switch (operationNum) {
            case 1:
                cout << "Введите добавляемую переменную:" << endl;
                valueType value;
                cin >> value;
                P.Add(value);
                break;
            case 2:
                P.Del();
                cout << "Минимальный элемент удален;" << endl;
                break;
            case 3:
                cout << "Минимальный элемент в очереди:" << endl;
                P.PrintMinimal();
                break;
            default:
                cout << "Ошибка в выборе операции." << endl;
                break;
        }
        cout << endl;
    }
    else{
        cout << "Доступные операции:\n1. Добавление элемента;" << endl;
        cout << "Введите номер операции:" << endl;
        cin >> operationNum;
        switch (operationNum) {
            case 1:
                cout << "Введите добавляемую переменную:" << endl;
                valueType value;
                cin >> value;
                P.Add(value);
                break;
            default:
                cout << "Ошибка в выборе операции." << endl;
                break;
        }
        cout << endl;
    }

}

template <typename valueType>
void PrintQ(Priority_Queue<valueType>& P){
    if(P.GetQSize()>0){
        cout << "Элементы в очереди:" << endl;
        P.PrintQ();
    }
    else{
        cout << "Очередь пуста."  << endl;
    }
}

int main() {
    
    int n; // количество операций
    cout << "Введите количество проводимых операций с очередью:" << endl;
    cin >> n;
    
    cout << "Выберете тип очереди:\n1.char;\n2.int;\n3.double;\n4.float;" << endl;
    int OperationNum; //для выбора операции
    cin >> OperationNum;
    switch (OperationNum){
        case 1: {
            Priority_Queue<char> Pchar(n);
            for (int i = 0; i < n; ++i) {
                PrintTask(Pchar);
            }
            PrintQ(Pchar);
            break;
        }
        case 2: {
            Priority_Queue<int> Pint(n);
            for (int i = 0; i < n; ++i) {
                PrintTask(Pint);
            }
            PrintQ(Pint);
            break;
        }
        case 3: {
            Priority_Queue<double> Pdouble(n);
            for (int i = 0; i < n; ++i) {
                PrintTask(Pdouble);
            }
            PrintQ(Pdouble);
            break;
        }
        case 4: {
            Priority_Queue<float> Pfloat(n);
            for (int i = 0; i < n; ++i) {
                PrintTask(Pfloat);
            }
            PrintQ(Pfloat);
            break;
        }
        default:
            cout << "Ошибка в выборе операции." << endl;
            break;
    }

    return 0;
}
