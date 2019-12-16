#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int getFirstUnFormedNum(vector<int> &arr, int length)
	{
		int sum = 0, min = arr[0];
		int i, j;
		for (int i = 0; i < length; i++)
		{
			sum += arr[i];
			min = arr[i] < min ? arr[i] : min;
		}
		vector<int> dp(sum + 1, 0);
		for (i = 0; i < length; i++)
		{
			for (j = sum; j >= arr[i]; j--)
			{
				if (dp[j] < dp[j - arr[i]] + arr[i])
				{
					dp[j] = dp[j - arr[i]] + arr[i];
				}
				else
				{
					dp[j] = dp[j];
				}
			}
		}
			for (i = min; i <= sum; i++)
			{
				if (i != dp[i])
				{
					return i;
				}
			}
		return sum + 1;
	}
};

int main()
{


	return 0;
}