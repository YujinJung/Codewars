#include <iostream>
#include <memory>
#include <vector>

typedef struct building
{
    std::vector<std::shared_ptr<building>> pre_build;
    int time;
    int building_time;
    int flag;

    building() : time(0), building_time(0)
    {
    }
    building(int f, int b_time) : flag(f), time(b_time), building_time(b_time)
    {
    }

    int calculate_time()
    {
        // std::cout << "call flag: " << flag + 1 << " time : " << time << std::endl;
        if (pre_build.empty())
        {
            return building_time;
        }

        int max_time = 0;
        for (auto x : pre_build)
        {
            // std::cout<<"sub flag: "<<x->flag + 1<<std::endl;; 
            int c_time = 0;
            if (x->building_time != x->time)
                c_time = x->time;
            else
                c_time = x->calculate_time();

            if (max_time < c_time)
                max_time = c_time;
        }

        time = building_time + max_time;
        // std::cout << "return flag: " << flag + 1 << " time : " << time << std::endl;

        return time;
    }
} building;

int main(void)
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N, K;
        std::cin >> N >> K;

        // build time
        std::vector<std::shared_ptr<building>> b;
        for (int j = 0; j < N; j++)
        {
            int t;
            std::cin >> t;
            b.push_back(std::make_shared<building>(j, t));
        }

        for (int j = 0; j < K; j++)
        {
            int k1, k2;
            std::cin >> k1 >> k2;
            // std::cout<<"k1, k2 : "<<k1<<" "<<k2<<std::endl;
            b.at(k2 - 1)->pre_build.push_back(b.at(k1 - 1));
        }

        int aim;
        std::cin >> aim;
        std::cout << b.at(aim - 1)->calculate_time() << std::endl;
    }

    return 0;
}