#include <bits/stdc++.h>
using namespace std;

double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n+2);
    points[0] = {0, 0};
    for(int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    points[n+1] = {0, 0};

    double ans = 0;
    for(int i = 1; i <= n+1; ++i) {
        ans += dist(points[i-1], points[i]);
    }

    printf("%.10f\n", ans);
    return 0;
}