#include<iostream>
using namespace std;

int picking_numbers(const int a[], const int size)
{
	auto max = 0;

	for (auto i = 0; i < size - 1; i++)
	{
		if (a[i] + a[i + 1] > max)
			max = a[i] + a[i + 1];
	}

	return max;
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	int a[100];

	for (auto i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	const auto result = picking_numbers(a, n);
	cout << result << endl;
	system("pause");
	return 0;
	
}
