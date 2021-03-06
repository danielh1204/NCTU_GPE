#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& vec)
{
	for (int i = (int)vec.size() - 1; i >= 0; i--)
	{
		if (i - 1 >= 0)
		{
			if (vec[i] < vec[i - 1])
			{
				int temp = vec[i];
				vec[i] = vec[i - 1];
				vec[i - 1] = temp;
			}
		}
	}
}

int main()
{
	vector<vector<int>> vec;
	int M, N;
	cin >> M >> N;
	int c = 0;
	vector<int> svec;
	while (M--)
	{
		int t;
		cin >> t;
		svec.push_back(t);
		sort(svec);
		vec.push_back(svec);
		c++;
	}

	int j = 0;
	while (N--)
	{
		j++;
		int t;
		cin >> t;
		cout << vec[t - 1][j-1] << endl;
	}
}
