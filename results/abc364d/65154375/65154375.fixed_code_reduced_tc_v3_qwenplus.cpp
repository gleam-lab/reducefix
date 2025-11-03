#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the A array to enable binary search and two pointers
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // We want to find the k-th smallest distance from b to any point in A
        // Instead of computing all distances, we can use binary search on the answer (distance)
        // But note: k-th closest means we need to find how many points are within a certain radius
        
        // However, simpler approach: use lower_bound to find position where b would be inserted
        auto it = lower_bound(A.begin(), A.end(), b);
        
        // Now consider left and right parts around b
        vector<ll> candidates;
        
        // Collect potential positions: we don't need all, but at most k from left and k from right
        // Left side: go backwards from it
        auto lit = it;
        for (int i = 0; i < k && lit != A.begin(); i++) {
            --lit;
            candidates.push_back(abs(*lit - b));
        }
        
        // Right side: go forwards from it
        auto rit = it;
        for (int i = 0; i < k && rit != A.end(); i++) {
            candidates.push_back(abs(*rit - b));
            ++rit;
        }
        
        // Sort the candidate distances
        sort(candidates.begin(), candidates.end());
        
        // The k-th smallest distance (1-indexed)
        cout << candidates[k-1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}