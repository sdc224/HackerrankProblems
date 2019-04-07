#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<string, int>m;

	int q;
	cin >> q;

	while (q--)
	{
		string x;
		int type, y;

		cin >> type;

		map<string, int>::iterator it;

		switch (type)
		{
			case 1:
				cin >> x;
				cin >> y;
				if ((it = m.find(x)) != m.end())
					it->second += y;
				else
					m.insert(make_pair(x, y));
				break;

			case 2:
				cin >> x;
				if (m.find(x) != m.end())
					m.erase(m.find(x));
				break;

			case 3:
				cin >> x;
				if (m.find(x) != m.end())
					cout << m[x] << endl;
				else
					cout << "0" << endl;
				break;

			default:
				break;
		}
	}

	return 0;
}