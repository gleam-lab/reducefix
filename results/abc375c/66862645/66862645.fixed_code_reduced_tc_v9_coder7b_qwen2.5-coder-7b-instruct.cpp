#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    vector<long long> x(n), y(n);
    for(long long i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    long double ans = 0;
    for(long long i = 0; i < n; ++i) {
        ans += sqrtl(powl(x[i], 2) + powl(y[i], 2));
        if(i > 0) {
            ans += sqrtl(powl(x[i] - x[i-1], 2) + powl(y[i] - y[i-1], 2));
        }
    }
    
    cout.precision(15);
    cout << ans << '\n';
    
    return 0;
}