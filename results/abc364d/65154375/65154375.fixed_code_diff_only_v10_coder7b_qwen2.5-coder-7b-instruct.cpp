#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v), end(v)
#define sz(x) (int)(x).size()

vector<int> a;

struct Point {
    int coord, index;
};

bool cmp(const Point& p1, const Point& p2) {
    return p1.coord < p2.coord;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].coord;
        points[i].index = i;
    }

    sort(all(points));

    while (q--) {
        int b, k;
        cin >> b >> k;
        
        // Calculate distances
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = abs(points[i].coord - b);
        }
        
        // Sort distances
        sort(all(distances));
        
        // Get the k-th smallest distance
        cout << distances[k - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; // For multiple test cases
    // cin >> t;
    while (t--) solve();
    
    return 0;
}