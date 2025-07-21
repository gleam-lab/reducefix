#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    long long x = 0, y = 0, ans = 0;
    cin >> N;
    
    while (N--) {
        long long nx, ny;
        cin >> nx >> ny;
        
        ans += abs(x - nx) + abs(y - ny);
        x = nx;
        y = ny;
    }
    
    cout << ans << '\n';
}