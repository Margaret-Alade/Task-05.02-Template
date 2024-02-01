//
//  main.cpp
//  Task-05.02 Template
//
//  Created by Маргарет  on 30.01.2024.
//

#include <iostream>

template <class T>
class table {
private:
    T** elements;
    unsigned int ROWS_;
    unsigned int COLS_;
public:
    table() {
        ROWS_=0;
        COLS_=0;
        elements=NULL;
    }
    table (unsigned int ROWS, unsigned int COLS) {
        this->ROWS_ = ROWS;
        this->COLS_ = COLS;
        elements = new T*[ROWS];
        for (unsigned int i = 0; i < ROWS; i++) {
            elements[i] = new T[COLS];
        }
    }
    
    T* operator[](unsigned int index){
        return elements[index];
    }
    
    T* operator[](unsigned int index) const{
        return elements[index];
    }
    
    unsigned int size() const {
        return ROWS_ * COLS_;
    }
    
    
    
    ~table() {
        for (unsigned int i = 0; i < ROWS_; i++) {
            delete[]elements[i];
        }
        delete[]elements;
    }
};

int main(int argc, const char * argv[]) {
    table<int> table_1(2, 3);
    table_1[0][0] = 4;
    table_1[0][1] = 3;
    std::cout << table_1[0][0] << " " << table_1[0][1] << "\n";
    std::cout << "Размер таблицы: " << table_1.size() << "\n";
    return 0;
}
