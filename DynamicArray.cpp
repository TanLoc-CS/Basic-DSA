#include<iostream>
#include<cstring>
using namespace std;

class DynamicArray{
public:
    int Size, capacity;
    float *storage;
public:
    DynamicArray(int capacity = 10){
        this->capacity = capacity;
        Size = 0;
        storage = new float[capacity];
    }
    void setCapacity(int);
    void ensureCapacity(int);
    void pack();
    void trim();
    void rangeCheck(int);
    void Set(int, float);
    float get(int);
    void removeAt(int);
    void insertAt(int, float);

    void print();
};

void DynamicArray::setCapacity(int newCapacity)
{
    float* newStorage = new float[newCapacity];
    memcpy(newStorage, storage, sizeof(float) * Size);
    capacity = newCapacity;
    delete[] storage;
    storage = newStorage;
}

void DynamicArray::ensureCapacity(int minCapacity)
{
    if (minCapacity > capacity){
        int newCapacity = capacity*3 / 2 + 1;
        if (newCapacity < minCapacity)
            newCapacity = minCapacity;
        setCapacity(newCapacity);
    }
}
void DynamicArray::pack()
{
    if (Size <= capacity / 2){
        int newCapacity = Size * 3 / 2 + 1;
        setCapacity(newCapacity);
    }
}
void DynamicArray::trim()
{
    int newCapcity = Size;
    setCapacity(newCapcity);
}
void DynamicArray::rangeCheck(int index)
{
    if (index < 0 || index >= Size)
        throw "Index out of bounds!";
}
void DynamicArray::Set(int index, float value)
{
    rangeCheck(index);
    storage[index] = value;
}
float DynamicArray::get(int index)
{
    rangeCheck(index);
    return storage[index];
}
void DynamicArray::insertAt(int index, float value)
{
    if (index < 0 || index > Size)
        throw "Index out of bounds!";

    ensureCapacity(Size + 1);

    int moveCount = Size - index;
    if (moveCount != 0)
        memmove(storage + index + 1, storage + index, sizeof(float) * moveCount);
    storage[index] = value;
    Size++;
}
void DynamicArray::removeAt(int index){
    rangeCheck(index) ;
    int moveCount = Size - index - 1 ;
    if (moveCount > 0)
    memmove(storage + index, storage + (index + 1), sizeof(float)*moveCount ) ;
    Size --;
    pack();
}
void DynamicArray::print()
{
    for (int i = 0; i < this->Size; i++)
        cout << storage[i] << " ";
    cout << '\n';
}

int main()
{
    DynamicArray* arr = new DynamicArray;
    for (int i = 0; i < 10; i++){
        arr->insertAt(i, i);
    }
    arr->print();
    arr->insertAt(1, 21.02);
    arr->print();
    return 0;
}
