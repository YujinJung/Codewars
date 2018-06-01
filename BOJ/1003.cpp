#include <iostream>

int main(void)
{
    int N;
    std::cin >> N;

    for(int i = 0; i < N; ++i){
        int fiboNum;
        std::cin >> fiboNum;

        int ret[num][2];
        
        ret[0][0]  = 1;
        ret[1][0] = 0;

        std::cout<<ret[0][0] << " "<<ret[1][0] << std::endl;
    }

    return 0;
}