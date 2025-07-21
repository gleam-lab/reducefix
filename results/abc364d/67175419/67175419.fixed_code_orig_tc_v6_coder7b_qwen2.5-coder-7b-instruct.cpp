#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<pair<int, int>>> sorted_dists(q);
    
    // Precompute distances and sort them
    for(int j = 1; j <= q; ++j) {
        int b, k;
        cin >> b >> k;
        
        for(int i = 1; i <= n; ++i) {
            sorted_dists[j].push_back({abs(b - a[i]), i});
        }
        sort(sorted_dists[j].begin(), sorted_dists[j].end());
    }

    // Answer queries using precomputed distances
    for(int j = 1; j <= q; ++j) {
        int result = sorted_dists[j][k - 1].first;
        cout << result << "\n";
    }

    return 0;
}