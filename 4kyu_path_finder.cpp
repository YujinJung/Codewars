#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

bool path_finder(string maze) {

	vector<vector<pair<int, int>> > v;
	int n = 0;

	for (int i = 0; i < maze.size(); i++)
	{
		vector<pair<int, int> > input;
		int k = 0;
		while (maze.at(i) != '\n')
		{
			if (maze.at(i) == '.')
				input.push_back(make_pair(0, 0));
			else if (maze.at(i) == 'W')
				input.push_back(make_pair(1, 0));

			i++;
			if (i == maze.size()) break;
		}
		v.push_back(input);
	}

	n = v.size() - 1;
	bool result = false;

	cout << endl;
	cout << endl;
	cout << endl;

	int i = 0, j = 0;
	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	int k = 0;
	while (!q.empty() && !(result))
	{
		k++;
		i = q.front().first; j = q.front().second;
		q.pop_front();
		if (i == n && j == n) return true;

		if (i + 1 < n + 1)
		{
			if (v.at(i + 1).at(j).first == 0 && v.at(i + 1).at(j).second == 0)
			{
				q.push_back(make_pair(i + 1, j));
				v.at(i + 1).at(j).second = 1;
			}
		}

		if (j + 1 < n + 1)
		{
			if (v.at(i).at(j + 1).first == 0 && v.at(i).at(j + 1).second == 0)
			{
				q.push_back(make_pair(i, j + 1));
				v.at(i).at(j + 1).second = 1;
			}
		}

		if (i - 1 >= 0)
		{
			if (v.at(i - 1).at(j).first == 0 && v.at(i - 1).at(j).second == 0)
			{
				q.push_back(make_pair(i - 1, j));
				v.at(i - 1).at(j).second = 1;
			}
		}

		if (j - 1 >= 0)
		{
			if (v.at(i).at(j - 1).first == 0 && v.at(i).at(j - 1).second == 0)
			{
				q.push_back(make_pair(i, j - 1));
				v.at(i).at(j - 1).second = 1;
			}
		}
	}
	return false;
}
