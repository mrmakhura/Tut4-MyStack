#include <iostream>
#include <string>
#include "MyStack.h"

using namespace std;

void instruc()
{
	cout << "\nPress [1] to Push or [2] to Pop or [3] to Delete Stack : ";
}

template<typename T>
void Driver(MyStack<T> &listObject)
{
	T max;
	cout << "Welcome to MyStack , Lets Get you started \n\n ";
	cout << "Ok , Lets get one thing straight how big must the Stack be : ";
	cin >> max;
	cout << "\n\nThank you ... Ready Steady Go .. \n\n";
	//instruc();
	int choice;
	T value;
	
	listObject.setMax(max);
		do
		{
			instruc();
			cin >> choice;

			switch (choice)
			{
			case 1:
				cout << "Enter Your Value : ";
				cin >> value;
				listObject.push(value);
				system("cls");
				listObject.peek();
				break;
			case 2:

				listObject.pop(value);
				system("cls");
				listObject.peek();
				
				break;
			}


		} while (choice < 3);


}

int main()
{
	MyStack<int> theStack;

	Driver(theStack);

	system("pause");
	return 0;
}