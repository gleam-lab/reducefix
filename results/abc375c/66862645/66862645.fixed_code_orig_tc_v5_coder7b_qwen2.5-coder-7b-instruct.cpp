#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    vector<pair<long long, long long>> points(n);
    for (long long i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double cost = 0;
    long double ans = 0;
    long long nowX = 0, nowY = 0;

    for (const auto& [nextX, nextY] : points) {
        cost = sqrtl(powl(nowX - nextX, 2) + powl(nowY - nextY, 2));
        ans += cost;
        nowX = nextX;
        nowY = nextY;
    }

    cost = sqrtl(powl(nowX - 0, 2) + powl(nowY - 0, 2));
    ans += cost;

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}