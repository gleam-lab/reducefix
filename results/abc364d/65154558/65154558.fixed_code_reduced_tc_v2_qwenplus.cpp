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
        
        // We'll collect distances from nearby points around b
        vector<ll> dists;
        
        // Add points from left and right of b
        // We need at most k elements on each side to ensure we have k-th smallest
        int left = pos - 1, right = pos;
        for (int i = 0; i < k && left >= 0; i++, left--) {
            dists.push_back(abs(a[left] - b));
        }
        for (int i = 0; i < k && right < N; i++, right++) {
            dists.push_back(abs(a[right] - b));
        }
        
        // Sort the collected distances
        sort(dists.begin(), dists.end());
        
        // Output the k-th smallest distance (1-indexed)
        cout << dists[k-1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}