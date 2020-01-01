#include "common/list.h"
#include "iostream"
using namespace std;

int main()
{
	cout << "create list" << endl;
	List<int> list;
	int idx = 0;
	int val = 0;
	cout << "list size: " << list.size() << ", empty: " << list.isEmpty() << endl;
	for(int i=0; i<10; ++i)
	{
		list.insert(i+1, -1);
	}
	cout << "Insert 10 element, list size: " << list.size() << endl;
	list.print();
	val = 187;
	idx = 5;
	list.insert(val, idx);
	cout << "Insert val " << val << " at idx " << idx << ", list size: " << list.size() << endl;
	list.print();
	idx = 7;
	int idxRet = list.search(idx);
	cout << "search idx " << idx << ": " << idxRet << endl;
	idx = 2;
	val = 6;
	list.insert(6, idx);
	cout << "Insert val " << val << " at idx " << idx << ", list size: " << list.size() << endl;
	list.print();
	val = 6;
	list.remove(val);
	cout << "Remove all val = " << val << ", list size: " << list.size() << endl;
	list.print();
	idx = 10;
	list.removeIdx(idx);
	cout << "Remove idx " << idx << ", list size: " << list.size() << endl;
	list.print();
	list.removeAll();
	cout << "Remove all, list size: " << list.size() << endl;
	list.print();
	for(int i=0; i<10; ++i)
	{
		list.insert(i+1, 0);
	}
	cout << "Insert 10 element, list size: " << list.size() << endl;
	list.print();
	int start = -1;
	int end = 1;
	cout << "print list[" << start << ", " << end << "]" << endl;
	list.print(start, end);


	return 0;
}
