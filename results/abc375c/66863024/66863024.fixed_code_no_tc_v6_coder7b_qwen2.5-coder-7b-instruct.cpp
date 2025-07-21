#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    vector<long long> x(n+1), y(n+1);
    x[0] = y[0] = 0; // Starting at the origin
    
    for(long long i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    
    long double ans = 0;
    
    for(long long i = 1; i <= n; i++){
        long double dx = x[i-1] - x[i];
        long double dy = y[i-1] - y[i];
        ans += sqrtl(dx*dx + dy*dy);
    }
    
    cout << fixed << setprecision(10) << ans << "\n";
    
    return 0;
}