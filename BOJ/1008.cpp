#include <cstdio>
using namespace std;
 
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    double d = (double) a / b;
    printf("%.9lf\n", d);
}