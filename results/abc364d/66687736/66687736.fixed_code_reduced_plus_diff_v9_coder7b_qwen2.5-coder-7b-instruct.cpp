#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct Point {
    int x, idx;
};

bool cmp(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x;
        points[i].idx = i;
    }
    
    vector<vector<pair<int, int>>> queries(q);
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries[i] = {{b, i}};
    }
    
    sort(points.begin(), points.end(), cmp);
    
    for (auto& query : queries) {
        int b = query[0].first;
        int qi = query[0].second;
        
        vector<int> distances;
        for (const auto& p : points) {
            distances.push_back(abs(p.x - b));
        }
        
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        
        cout << distances[k - 1] << "\n";
    }
    
    return 0;
}