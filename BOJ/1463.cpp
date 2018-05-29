#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

// 정수가 x에 사용할 수 있는 연산
// 1. x가 3으로 나누어 떨어지면 3으로 나눔
// 2. x가 2로 나누어 떨어지면 2로 나눔
// 3. 1을 뺀다

int main(void)
{
	int num;
	cin >> num;

	list<pair<int, int>> queue; // queue / number, depth
	vector<int> cache(num, -1); // cache

	int depth;
	queue.push_back(make_pair(num, 0));

	while (!queue.empty()) {
		int cur = queue.front().first;
		int curDepth = queue.front().second;
		queue.pop_front();

		int& ret = cache[cur - 1];
		if (cur == 1) {
			depth = curDepth;
			break;
		}

		if (cur % 3 == 0)
			queue.push_back(make_pair(cur / 3, curDepth + 1));
		if (cur % 2 == 0)
			queue.push_back(make_pair(cur / 2, curDepth + 1));
		queue.push_back(make_pair(cur - 1, curDepth + 1));
	}

	cout << depth << endl;

	return 0;
}