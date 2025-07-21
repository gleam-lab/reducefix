#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    long double ans = 0;
    long double x = 0, y = 0;
    
    for (int i = 0; i < N; ++i) {
        long long nx, ny;
        cin >> nx >> ny;
        
        ans += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        
        x = nx;
        y = ny;
    }
    
    ans += sqrt(x * x + y * y);
    
    cout << fixed << setprecision(8) << ans << endl;
    
    return 0;
}