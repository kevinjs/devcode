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
	cout << "Push 8 element, stack size: " << stack.size() << " current top " << stack.getTop() << endl;
	stack.print();
	stack.pop();
	stack.pop();
	cout << "Pop 2 element, stack size: " << stack.size() << " current top " << stack.getTop() << endl;
	stack.print();
	stack.push(777);
	cout << "Push 777, stack size: " << stack.size() << " current top " << stack.getTop() << endl;
	stack.print();

	while(!stack.isEmpty())
	{
		cout << "Pop all element, current top " << stack.getTop() << endl;
		stack.pop();
	}
	cout << "stack empty, size: " << stack.size() << ", empty: " << stack.isEmpty() << endl;

	return 0;
}
