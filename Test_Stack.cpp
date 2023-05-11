#include <iostream>
#include <stack>
using namespace std;

//functie gasire Min
int cautare_Min(stack<int>stack_1, stack<int>stack_2)
	{
	int Min = 100;

	while (stack_2.empty() == false)
		{
		stack_1.push(stack_2.top());
		if (stack_2.top() < Min)
			Min = stack_2.top();
		stack_2.pop();
		}
	return Min;
	}

int main()
	{


	//initializare/citire
	int n, k, x, Min;
	stack<int> stack_1, stack_2;
	cin >> n >> k;
	cin >> x;
	Min = 9999;
	int contor = 0;
	//initializare stack + gasire Min
	while (x)
		{
		stack_1.push(x % 10);
		if (Min > x % 10)
			Min = x % 10;
		x /= 10;
		}
		//eliminare cifre
	while (contor < k)
		{

		while (stack_1.empty() == false)
			{
			if (stack_1.top() > Min)
				{
				stack_2.push(stack_1.top());

				stack_1.pop();

				}
			else
				{

				if (contor == k)
					{
					stack_2.push(stack_1.top());
					stack_1.pop();

					}
				else
					{
					stack_1.pop();
					contor += 1;
					}
				}

			}
		Min = cautare_Min(stack_1, stack_2);
		while (stack_2.empty() == false)
			{
			if (stack_2.top() > Min)
				{
				stack_1.push(stack_2.top());

				stack_2.pop();

				}
			else
				{
				if (contor == k)
					{
					stack_1.push(stack_2.top());
					stack_2.pop();
					}
				else
					{
					stack_2.pop();
					contor += 1;
					}
				}
			}
		}
	//afisare
	x = 0;
	while (stack_1.empty() == false)
		{
		x *= 10;
		x += stack_1.top();
		stack_1.pop();
		}
	cout << x;

	return 0;
	}
