#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vll a(N);
    rep(i, N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // We want to find the k-th smallest distance from B to any A_i
        // Instead of computing all distances, we can use binary search on the answer
        // But note: we need the k-th smallest distance, so we can also consider
        // finding how many points are within a certain radius
        
        // However, simpler approach: use two pointers or binary search to find
        // the k-th closest point by considering candidates around b
        
        // Find the position where b would be inserted
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();
        
        // We'll maintain a range [l, r] of indices in a that are candidates
        // for being among the k closest points to b
        int l = max(0, pos - k);
        int r = min(N-1, pos + k);
        
        // Extract candidate distances
        vll dists;
        for (int i = l; i <= r; i++) {
            dists.push_back(abs(a[i] - b));
        }
        
        // Sort and get the k-th smallest
        sort(dists.begin(), dists.end());
        cout << dists[k-1] << '\n';
    }
}