#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double cost = 0;
    long double ans = 0;
    int nowX = 0, nowY = 0;

    for (const auto& point : points) {
        int nextX = point.first, nextY = point.second;
        cost = sqrt(pow(nextX - nowX, 2.0) + pow(nextY - nowY, 2.0));
        ans += cost;
        nowX = nextX;
        nowY = nextY;
    }

    cost = sqrt(nowX * nowX + nowY * nowY);
    ans += cost;

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}