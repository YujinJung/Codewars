#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

void path(vector<vector<pair<int, int> > >& v, int i, int j, const int &n, bool& result)
{
	if (v.at(i).at(j).second == 1) return;
	v.at(i).at(j).second = 1;

	if (i < 0 || j < 0 || i > n || j > n) return;
	if (v.at(i).at(j).first == 1) return;
	if (i == n && j == n && v.at(i).at(j).first == 0)
	{
		result = true;
		return;
	}
	if (v.at(i).at(j).first == 1)
		return;

	if (i + 1 < n + 1 && result != true)
		path(v, i + 1, j, n, result);

	if (j + 1 < n + 1 && result != true)
		path(v, i, j + 1, n, result);

	if (i - 1 > 0 && result != true)
		path(v, i - 1, j, n, result);

	if (j - 1 > 0 && result != true)
		path(v, i, j - 1, n, result);

	return;
}

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

int main(void)
{
	cout << "result: " << "true false true false false" << endl;
	cout << endl;
	cout << path_finder(".W...W...W...\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n.W.W.W.W.W.W.\n...W...W...W.");
	cout << endl << endl << path_finder(".............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n......W......\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............");
	cout << endl << endl << path_finder(".............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............");
	cout << endl << endl << path_finder(".............\nWWWWWWWWWWWWW\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............");
	cout << endl << endl << path_finder(".............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n.............\n.WWWWWWWWWWWW\n.............\nWWWWWWWWWWWW.\n............W\n.WWWWWWWWWWWW\n.............");
	system("pause");
}