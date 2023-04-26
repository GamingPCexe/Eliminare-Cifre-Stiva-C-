

#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<char> stack_1, stack_2;
	char aux;
	for (int i = 0; i < 5; i++)
	{
		cin >> aux;
		stack_1.push(aux);
		stack_2.push(stack_1.top());
	}
	while (!stack_2.empty() )
	{
		cout << stack_2.top()<<'\n';
		stack_2.pop();
	}
	while(!stack_1.empty())
	{
		cout << stack_1.size() << '\n';
		stack_1.pop();
	}
}

