#include "DynamicArray.h"
#include<Windows.h>
#include <iostream>
using namespace std;
DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
    cout << "Construct by 1 param\n";
    size = S;
    ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
    cout << "Copy construct\n";
    size = a.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[i];
    }
}
DynamicArray::~DynamicArray()
{
    cout << "Destruct\n";
    if (ptr != 0)
    {
        delete[] ptr;
    }
}
void DynamicArray::Input()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 20;
    }
}
void DynamicArray::Output() const
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << "\n---------------------------------\n";
}
int* DynamicArray::GetPointer() const
{
    return ptr;
}
int DynamicArray::GetSize()const
{
    return size;
}
DynamicArray DynamicArray:: operator+(int b)
{
    DynamicArray res;
    res.size = size + b;
    res.ptr = new int[res.size];
    for (int i = 0; i < res.size; i++)
    {
        if (i < size)
            res.ptr[i] = ptr[i];
        else
            res.ptr[i] = 0;
    }
    return res;
}
DynamicArray DynamicArray:: operator-(int b)
{
    DynamicArray res;
    if (size > b)
    {
        res.size = size - b;
        res.ptr = new int[res.size];
        for (int i = 0; i < res.size; i++)
        {
            res.ptr[i] = ptr[i];
        }
    }
    else
    {
        cout << "Error! Array must be more than b" << endl;
        return *this;
    }
    return res;
}
DynamicArray DynamicArray:: operator *(int b)
{
    DynamicArray res;
    res.size = size;
    res.ptr = new int[res.size];
    for (int i = 0; i < res.size; i++)
        res.ptr[i] = ptr[i] * b;
    return res;
}
DynamicArray DynamicArray:: operator - (DynamicArray b)
{
    if (size < b.size)
    {
        cout << "Error!" << endl;
        return *this;
    }
    DynamicArray res;
    res.size = size - b.size;
    res.ptr = new int[res.size];
    for (int i = 0; i < res.size; i++)
    {
        res.ptr[i] = ptr[i];
    }
    return res;
}
DynamicArray DynamicArray:: operator + (DynamicArray b)
{
    DynamicArray res;
    res.size = size + b.size;
    res.ptr = new int[res.size];
    for (int i = 0,j=0; i < res.size; i++)
    {
        if (i < size)
        {
            res.ptr[i] = ptr[i];
        }
        else
        {
            
            res.ptr[i] = b.ptr[j++];
            
        }

    }
    return res;
}
DynamicArray DynamicArray:: operator++()
{
    DynamicArray res;
    res.size = size + 1;
    res.ptr = new int[res.size];
    for (int i = 0; i < res.size - 1; i++)
        res.ptr[i] = ptr[i];
    res.ptr[res.size - 1] = 0;
    return res;
}
DynamicArray DynamicArray:: operator --()
{
    DynamicArray res;
    res.size = size - 1;
    res.ptr = new int[res.size];
    for (int i = 0; i < res.size; i++)
        res.ptr[i] = ptr[i];
    return res;
}