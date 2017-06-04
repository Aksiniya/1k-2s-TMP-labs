/* Реализация списка в виде списка сыновей
 Задача:
 Реализовать дерево (с помощью структуры или класса) в виле списка (лучше использовать список указателей) сыновей
 Входные даныые:
 N  - количество узлов дерева
 <массив курсоров на родительские элементы> (элемент. не имеющий родителя будет представляться числом -1) Значения элементов - индексы элемента в массиве курсоров

 Входные данные:
 <Элементы дерева, перечисленные в прямом порядке обхода>
 <Элементы дерева, перечисленные в обратном порядке обхода>
 <Элементы дерева, перечисленные в симметричном порядке обхода>

 Пример:
 Входные данные
 8
 -1 0 0 0 1 2 2 3

 Выходные данные:
 0 1 4 2 5 6 3 7
 4 1 5 6 2 7 3 0
 4 1 0 5 2 6 7 3
 */


#include <iostream>
#include <vector>
using namespace std;

class Tree{
    vector<vector<int>> _tree; //представление дерева в виде вектора векторов
    vector<int> _cursors; // входной вектор
    vector<int> _numbers; //0, 1, ..., n
    vector<int> _DirectTree; //прямой порядок
    vector<int> _ReverseTree; // обратный порядок
    vector<int> _SymmetricTree; //симметричный порядок
    
public:
    Tree(int N, vector<int> _v) : _tree(N), _numbers(N), _cursors(_v){
        int i = 0;
        //Задаем вектор _numbers;
        for (auto it = _numbers.begin(); it < _numbers.end(); ++it){
            *it = i++;
        }
        //Задаем дерево;
        int index;
        for (int j = 0; j < N; ++j){
            index = _cursors[j];
            if (index > -1){
                _tree[index].push_back(j);
            }
        }
    }

    //Печать дерева:
    void PrintTree(){
        for (int i = 0; i < _numbers.size(); ++i){
            vector<int> _tmp = _tree[i];
            cout << i << " ->  ";
            for (int j = 0; j < _tmp.size(); ++ j){
                cout << _tmp[j] << " ";
            }
            cout << endl;
        }
    }
    
    //Определение вектора прямого порядка обхода, где index - корень дерева;
    void SetDirectTree(int index){
        _DirectTree.push_back(index);
        
        if(!_tree[index].empty()){
            for (int i = 0; i < _tree[index].size(); ++i){
                int tmp_index = _tree[index][i];
                SetDirectTree(tmp_index);
            }
        }
    }
    
    //Распечатать дерево в прямом порядке обхода;
    void PrintDirectTree(){
        for(auto it = _DirectTree.begin(); it < _DirectTree.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    
    //Определение вектора обратного порядка обхода, где index - корень дерева;
    void SetReverseTree(int index){
        if(!_tree[index].empty()){
            vector<int> _branch = GetLeftBranch(&_tree, index);
            
            for (auto it = _branch.end()-1; it > _branch.begin()-1; --it) {
                if(_tree[*it].size() <= 1){
                    _ReverseTree.push_back(*it);
                }
                else{
                    for(int j = 1; j < _tree[*it].size(); ++j){
                        SetReverseTree(_tree[*it][j]);
                    }
                    _ReverseTree.push_back(*it);
                }
            }
        }
        else{
            _ReverseTree.push_back(index);
        }
        _ReverseTree.push_back(0);
    }
    
    //Распечатать дерево в обратном порядке обхода;
    void PrintReverseTree(){
        for (auto it = _ReverseTree.begin(); it < _ReverseTree.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    
    //Определение вектора симметричного порядка обхода, где index - корень дерева;
    void SetSymmetricTree(int index){
        if(!_tree[index].empty()){
            vector<int> _branch = GetLeftBranch(&_tree, index);
            
            for (auto it = _branch.end()-1; it > _branch.begin()-1; --it) {
                
                if(it == _branch.begin()){ }
                
                if(_tree[*it].size() <= 1){
                    _SymmetricTree.push_back(*it);
                }
                else if (_tree[*it].size() > 1){
                    _SymmetricTree.push_back(*it);
                    for(int j = 1; j < _tree[*it].size(); ++j){
                        SetSymmetricTree(_tree[*it][j]);
                    }
                }
            }
            
        }
        else{
            _SymmetricTree.push_back(index);
        }
        
    }
    
    //Распечатать дерево в симметричном порядке обхода;
    void PrintSymmetricTree(){
        for (auto it = _SymmetricTree.begin(); it < _SymmetricTree.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    
    //получить левую ветку
    vector<int> GetLeftBranch(vector<vector<int>>* _CopyTree, int index){
        vector<int> _leftBranch;
        int lastIndex = index;
        _leftBranch.push_back(index);
        // цикл идет вниз по левой ветке начиная с индекса, создание branch1
        do{
            vector<int> _tmp = _CopyTree->at(lastIndex);
            
            if (_tmp.empty()){
                break;
            }
            
            index = _tmp[0];
            _leftBranch.push_back(index);
            lastIndex = index;
        }while (1);
        
        return _leftBranch;
    }
    
};

int main(){
    //условие:
    vector<int> condition = {-1, 0, 0, 0, 1, 2, 2, 3};
    int n = 8;
    
    Tree T(n, condition);
    T.PrintTree();

    cout << "Прямой порядок:" << endl;
    T.SetDirectTree(0);
    T.PrintDirectTree();
    
    cout << "Обратный порядок:" << endl;
    T.SetReverseTree(0);
    T.PrintReverseTree();
    
    cout << "Симметричный порядок:" << endl;
    T.SetSymmetricTree(0);
    T.PrintSymmetricTree();
    
    //дополнительная проверка:
    vector<int> cond = {-1, 0,0,0,1,1,1,1,4,8,8,6,11,12,12};
    int nn = 15;
    Tree TTT(nn, cond);
    TTT.PrintTree();
    cout << "Прямой порядок:" << endl;
    TTT.SetDirectTree(0);
    TTT.PrintDirectTree();
    
    cout << "Обратный порядок:" << endl;
    TTT.SetReverseTree(0);
    TTT.PrintReverseTree();
    
    cout << "Симметричный порядок:" << endl;
    TTT.SetSymmetricTree(0);
    TTT.PrintSymmetricTree();
    
    return 0;
}