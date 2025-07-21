#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        
        // Binary search to find the k-th smallest distance
        // We need to find the k-th element in the sorted list of absolute differences |a_i - b|
        // This can be done by finding the k-th smallest element in the sorted differences
        
        // To optimize, we can use two binary searches:
        // 1. Find the position of b in the sorted array a
        // 2. The k-th smallest distance will be among the elements around this position
        
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();
        
        vector<ll> candidates;
        int l = max(0, pos - k);
        int r = min(N - 1, pos + k - 1);
        for (int i = l; i <= r; ++i) {
            candidates.push_back(abs(a[i] - b));
        }
        sort(candidates.begin(), candidates.end());
        
        cout << candidates[k - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}