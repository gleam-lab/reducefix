#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;
    
    long double x = 0, y = 0, ans = 0;
    for(int i = 0; i < N; ++i){
        long double nx, ny;
        cin >> nx >> ny;
        
        ans += hypot(x - nx, y - ny);
        x = nx;
        y = ny;
    }
    ans += hypot(x, y);
    
    cout << setprecision(12) << ans << '\n';
}