#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a;
vector<pair<ll, int>> distances;

void solve() {
    int n, q; cin >> n >> q;
    
    // Read coordinates of points A
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Process each query
    for(int i = 1; i <= q; i++) {
        ll b; int k; cin >> b >> k;
        
        // Calculate all distances from point B_j to points A_i
        distances.clear();
        for(int j = 1; j <= n; j++) {
            distances.push_back({abs(a[j] - b), j});
        }
        
        // Sort distances in ascending order
        sort(distances.begin(), distances.end());
        
        // Output the k-th smallest distance
        cout << distances[k - 1].first << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}