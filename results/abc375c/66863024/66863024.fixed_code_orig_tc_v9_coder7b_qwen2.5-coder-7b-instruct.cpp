#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long double x = 0, y = 0, sum = 0;

    for(long long i = 0; i < n; ++i){
        long long xi, yi;
        cin >> xi >> yi;
        sum += sqrtl((xi-x)*(xi-x)+(yi-y)*(yi-y));
        x = xi;
        y = yi;
    }

    sum += sqrtl(x*x+y*y);
    cout << sum << endl;
    return 0;
}