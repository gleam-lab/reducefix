#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    vector<long long> x(n+1), y(n+1);
    x[0] = y[0] = 0; // Starting point at the origin
    
    for(long long i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    long double ans = 0;
    
    for(long long i = 1; i <= n; ++i) {
        long double dx = x[i] - x[i-1];
        long double dy = y[i] - y[i-1];
        ans += sqrt(dx * dx + dy * dy);
    }
    
    long double dx = x[n] - x[0];
    long double dy = y[n] - y[0];
    ans += sqrt(dx * dx + dy * dy);
    
    cout.precision(10);
    cout << ans << endl;
    
    return 0;
}