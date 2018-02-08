#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    int number;
    int sum, subsum;

    std::cin >> number;

    for(int i = 0; i < number; i++){
        std::cin >> s;

        sum = subsum = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if(s.substr(i,1) == "O"){
                subsum++;
                sum += subsum;
            }else{
                subsum = 0;
            }
        }
        std::cout << sum << '\n';
    }
}