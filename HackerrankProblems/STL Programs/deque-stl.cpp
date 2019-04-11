#include <iostream>
#include <deque> 
#include <vector>
using namespace std;

void print_k_max_more_time(const vector<int>& arr, int n, int k)
{
	for (auto i = 0; i <= n - k; i++)
	{
		auto max = arr[i];

		for (auto j = i + 1; j < i + k; j++)
		{
			if (max < arr[j])
				max = arr[j];
		}

		printf("%d ", max);
	}

	printf("\n");
}

void print_k_max(const vector<int>& arr, const int n, const int k)
{
	deque<int> deque;
    
    for (auto i = 0; i < n; i++)
	{        
        if (deque.empty())
	        deque.push_back(i);

        if (deque.front() <= i - k)
	        deque.pop_front();

        while (!deque.empty() && arr[i] >= arr[deque.back()])
	        deque.pop_back();

        deque.push_back(i);
        
        if (i >= k - 1)
	        cout << arr[deque.front()] << " ";
	}

    cout << endl;
}

int main(void)
{  
	int t;
	cin >> t;

	while(t--)
	{
		int n, k;
    	cin >> n >> k;
		vector<int> arr(n);

    	for (auto i = 0; i < n; i++)
      		cin >> arr[i];

    	print_k_max(arr, n, k);
  	}
  	return 0;
}