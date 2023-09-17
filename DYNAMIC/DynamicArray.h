
#include <iostream>
using namespace std;
class DynamicArray
{
	int* ptr;
	int size;   
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	void Input();
	void Output() const;
	int* GetPointer()const;
	int GetSize()const;
	DynamicArray operator+(int b);
	DynamicArray operator-(int b);
	DynamicArray operator *(int b);
	DynamicArray operator - (DynamicArray b);
	DynamicArray operator + (DynamicArray b);
	DynamicArray operator++();
	DynamicArray operator--();







};