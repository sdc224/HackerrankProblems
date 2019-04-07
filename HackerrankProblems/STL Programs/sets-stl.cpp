#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int q;
	cin >> q;

	set<int>s;

	while (q--)
	{
		int x, y;

		cin >> y >> x;		

		switch (y)
		{
			case 1:
				s.insert(x);
				break;

			case 2:
				s.erase(x);
				break;

			case 3:
				if (s.find(x) != s.end())
					cout << "Yes" << endl;
				else
					cout << "No" << endl;

			default:
				break;
		}
	}
	
	return 0;
}