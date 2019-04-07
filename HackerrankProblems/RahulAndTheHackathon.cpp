#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int arr[100];
string str;

void prime_no(int n)
{
	int i = 3, c, j = 0;
 
	arr[j++] = 2;
	
	for (auto count = 2 ; count <= n ;  )
	{
		for ( c = 2 ; c <= i - 1 ; c++ )
		{
			if ( i%c == 0 )
			break;
		}
		if ( c == i )
		{
			arr[j++] = i;
			count++;
		}
		i++;
   }         
}

int main() 
{
	int n = 0, i, hit = 0, test_case;
	cin >> test_case;

	char username_db[8][32]={};
	prime_no(test_case);

	while (test_case)
	{
		auto status = 0;
		char username[32];
		cin >> username;

		for (i = 0; i <= n; i++)
		{
			if(strcmp(username, username_db[i]) != 0)
			{
				status = 1;
			}
		}
		
		/*if(hit != 0)
		{
			printf("%s", username);
			status = 2;
			username_db[i] = username;
		}*/

		if(status == 0)
		{
			printf("OK\n");
			strcpy_s(username_db[i], username);
		}
		
		n++;
		test_case--;
	}

	return 0;
}