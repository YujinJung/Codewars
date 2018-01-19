#include <deque>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;
struct Image
{
	unsigned *pixels;
	unsigned width, height;

	Image(unsigned *pixels_, int w, int h)
	{
		pixels = pixels_;
		width = w;
		height = h;
	}
	vector<unsigned> central_pixels(unsigned colour) const;
};

vector<unsigned> Image::central_pixels(unsigned colour) const
{
	// pixels[i][j] = *(pixel + (i * width) + j)
	int depth = 987654321;
	vector<unsigned> result;

	// all path can start
	for (int i = 0; i < width*height; i++)
	{
		if (*(pixels + i) != colour)
			continue;
		// BFS
		// Queue
		deque<pair<unsigned, int> > d; // index, depth
		d.push_back(make_pair(i, 0));
		while (!d.empty())
		{
			unsigned loopIndex = d.front().first;
			unsigned loopDepth = d.front().second;
			d.pop_front();

			// depth over
			if (loopDepth > depth) break;


			if (*(pixels + loopIndex) != colour)
			{
				if (depth == 987654321) depth = loopDepth;
				result.push_back(loopIndex);
				continue;
			}

			loopDepth++;

			// up; i - width 
			if ((int)loopIndex - (int)width > 0) d.push_back(make_pair(i, loopDepth));

			// down; i + width 
			if (loopIndex + width > width * height) d.push_back(make_pair(i, loopDepth));

			// right; i + 1
			if ((int)(loopIndex % width) + 1 < width) d.push_back(make_pair(i, loopDepth));

			// left; i - 1
			if ((int)(loopIndex % width) - 1 > 0) d.push_back(make_pair(i, loopDepth));

		}

	}
	return result;
}

int main(void)
{
	Image image({ 1, 1, 4, 4, 4, 4, 2, 2, 2, 2,
		1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
		1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
		1, 1, 1, 1, 1, 3, 2, 2, 2, 2,
		1, 1, 1, 1, 1, 3, 3, 3, 2, 2,
		1, 1, 1, 1, 1, 1, 3, 3, 3, 3 }, 10, 6);

	image.central_pixels(1);
	return 0;
}