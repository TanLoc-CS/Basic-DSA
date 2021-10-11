#include<iostream>

using namespace std;

int BiSearch(int* arr, int items, int length)
{
    int pos, mid;
    int low = 0, high = length;
    while (high >= low){
        mid = (low + high) / 2;
        pos = arr[mid];
        if (pos == items)
            return mid;
        if (pos > items)
            high = mid + 1;
        else 
            low = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[10] = {0,2,4,6,8,10,12,14,16,18};
    int length = sizeof(arr)/sizeof(*arr);
    int items;
    cin >> items;
    cout << BiSearch(arr, items, length);
    return 0;
}