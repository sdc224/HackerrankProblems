/*#include <iostream>
#include <iomanip>

using namespace std;

void decimal_to_hexadecimal(const int decimal)
{
	auto hex_remainder = 0;

	if (!decimal)
		return;

	hex_remainder = decimal % 16;
	decimal_to_hexadecimal(decimal / 16);
		
	if (hex_remainder > 9)
	{
		cout << static_cast<char>(55 + hex_remainder);
	}
	else
	{
		cout << hex_remainder;
	}
}

int count_no_of_digits(int digit)
{
	auto count = 0;

	while (digit != 0)
	{
		digit /= 10;
		++count;
	}

	return count;
}

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		double a, b, c;
		cin >> a >> b >> c;

		// For First
		cout << "0x";
		decimal_to_hexadecimal(static_cast<int>(a));
		cout << endl;

		const auto no_of_underscores = count_no_of_digits(static_cast<int>(b)) + 2;

		for (auto i = 0; i <= no_of_underscores; i++)
			cout << "_";

		// For Second
		if (b < 0)
			cout << "-";
		else
			cout << "+";

		cout << fixed;
		cout << setprecision(2) << b << endl;

		// For Third
		cout << scientific;
		cout << setprecision(9) << c << endl;
	}

	return 0;
}*/


// Submitted code for hackerrank
#include <iostream>
#include <iomanip> 
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (t--)
	{
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		// LINE 1 
        cout << hex << left << showbase << nouppercase;														// formatting
        cout << static_cast<long long>(A) << endl;															// actual printed part

        // LINE 2
        cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2);         // formatting
        cout << B << endl;																					// actual printed part

        // LINE 3
        cout << scientific << uppercase << noshowpos << setprecision(9);									// formatting
        cout << C << endl;																					// actual printed part
	}

	return 0;
}