#include <iostream>
#include <vector>
#include <cmath>

typedef struct planet
{
    int x;
    int y;
    int radius;
    int include;

    planet(int _x, int _y, int _r) : x(_x), y(_y), radius(_r), include(0)
    {
    }
} planet;

int main(void)
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        int x, y, r;
        int result = 0;

        std::cin >> x >> y;
        planet start(x, y, 0);
        std::cin >> x >> y;
        planet stop(x, y, 0);

        std::vector<planet> v;
        int n;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int res = 0;
            std::cin >> x >> y >> r;
            v.push_back(planet(x, y, r));

            if (std::pow(start.x - x, 2) + std::pow(start.y - y, 2) <= std::pow(r, 2))
                res++;
            if (std::pow(stop.x - x, 2) + std::pow(stop.y - y, 2) <= std::pow(r, 2))
                res++;

            if (res < 2)
                result += res;
        }

        std::cout << result << std::endl;
    }

    return 0;
}