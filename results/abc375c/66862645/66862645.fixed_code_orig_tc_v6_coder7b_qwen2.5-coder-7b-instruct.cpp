#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    vector<long long> x(n+1), y(n+1);
    x[0] = y[0] = 0;
    
    for(long long i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    long double total_cost = 0;
    
    for(long long i = 1; i <= n; ++i) {
        total_cost += sqrt((x[i] - x[i-1]) * (x[i] - x[i-1]) + (y[i] - y[i-1]) * (y[i] - y[i-1]));
    }
    
    total_cost += sqrt(x[1] * x[1] + y[1] * y[1]);
    
    printf("%.15Lf\n", total_cost);
    
    return 0;
}