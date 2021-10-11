#include <iostream>
#include <random>
#include <cmath>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    random_device rd;
    mt19937 rng(rd());
    int *arr = new int[rng()];

    for (int i = 0; i < 10; i++)
        arr[i] = rng() % 100;

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    cout << endl;
    selectionSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}