#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &array)
{
    int key, j;
    for (int i = 1; i < array.size(); i++)
    {
        key = array.at(i);
        j = i - 1;
        while (j >= 0 && array.at(j) > key)
        {
            array.at(j + 1) = array.at(j);
            j--;
        }
        array.at(j + 1) = key;
    }
}

int main()
{
    vector<int> array;
    for (int i = 0; i < 6; i++)
        array.push_back(rand() % 100);
    for (int i = 0; i < 6; i++)
        cout << array.at(i) << " ";
    cout << '\n';
    InsertionSort(array);
    for (int i = 0; i < 6; i++)
        cout << array.at(i) << " ";

    return 0;
}