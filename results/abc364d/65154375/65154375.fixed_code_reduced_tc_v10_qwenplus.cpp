#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Find the position where b would be inserted
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();
        
        // We'll consider points around b: left part [0, pos-1] and right part [pos, N-1]
        vector<ll> distances;
        
        // Collect all distances from B_j to each A_i
        for (int i = 0; i < N; i++) {
            distances.push_back(abs(a[i] - b));
        }
        
        // Sort distances to find the k-th smallest
        sort(distances.begin(), distances.end());
        
        cout << distances[k - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}