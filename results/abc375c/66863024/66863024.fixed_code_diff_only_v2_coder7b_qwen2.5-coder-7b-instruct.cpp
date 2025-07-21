#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double ans = 0;
    for (int i = 0; i < N; ++i) {
        long long dx = points[i].first;
        long long dy = points[i].second;
        ans += sqrtl(dx * dx + dy * dy);
    }

    ans += sqrtl(points[N-1].first * points[N-1].first + points[N-1].second * points[N-1].second);

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}