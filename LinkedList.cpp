#include<iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};
 
int main()
{
    Node coca, pepsi;
    coca.value = 13;
    coca.next = &pepsi;
    pepsi.value = 10;
    return 0;
}