#include <iostream>
#include <list>

using namespace std;

typedef struct point {
	point()
		: x(0), y(0)
	{}
	point(int a, int b)
		: x(a), y(b)
	{}

	int x;
	int y;
} point;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int width, height, K;

		int pos[51][51] = { 0, }; // 0 - no plant, 1 - plant, 2 - visit
		list<point> ppos;

		cin >> width >> height >> K;
		for (int j = 0; j < K; ++j)
		{
			point temp;
			cin >> temp.x >> temp.y;
			ppos.push_back(temp);
			pos[temp.x][temp.y] = 1;
		}

		int ret = 0;
		while (!ppos.empty())
		{
			list<point> bfs;
			bfs.push_back(ppos.front());
			ppos.pop_front();

			// visited
			if (pos[bfs.front().x][bfs.front().y] == 2)
				continue;

			while (!bfs.empty())
			{
				point cur = bfs.front();
				bfs.pop_front();

				if (cur.x < 0 || cur.x > width - 1) // check x
					continue;
				if (cur.y < 0 || cur.y > height - 1) // check y
					continue;
				if (pos[cur.x][cur.y] != 1) // if plant and unvisited
					continue;

				pos[cur.x][cur.y] = 2;

				bfs.push_back(point(cur.x, cur.y - 1));
				bfs.push_back(point(cur.x, cur.y + 1));
				bfs.push_back(point(cur.x - 1, cur.y));
				bfs.push_back(point(cur.x + 1, cur.y));
			} // bfs while

			++ret;
		} // ppos while

		cout << ret << endl;
	} // Test case

	return 0;
}