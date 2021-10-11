#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSort(vector<int> &array)
{
    for (int i = 0; i < array.size() - i; i++)
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array.at(i) > array.at(j))
                swap(array.at(i), array.at(j));
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
    BubbleSort(array);
    for (int i = 0; i < 6; i++)
        cout << array.at(i) << " ";

    return 0;
}