#include "common/stack.h"
#include "iostream"
using namespace std;

int main()
{
	cout << "create stack" << endl;
	int capacity = 10;
	ArrayStack<int> stack(capacity);
	cout << "stack size: " << stack.size() << ", empty: " << stack.isEmpty() << endl;
	for(int i=0; i<8; ++i)
	{
		stack.push(i+1);
	}
	cout << "Push 8 element, stack size: " << stack.size() << endl;
	stack.print();

	return 0;
}
