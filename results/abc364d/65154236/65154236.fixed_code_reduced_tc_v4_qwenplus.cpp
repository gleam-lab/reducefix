#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-indexed
        
        // Find the position where b would be inserted
        auto it = lower_bound(A.begin(), A.end(), b);
        int pos = it - A.begin();
        
        // We consider candidates from left and right of b
        // We'll use two pointers to collect distances in sorted order until we get k+1 elements
        int left = pos - 1;
        int right = pos;
        
        // We only need to go up to k-th closest
        for (int i = 0; i <= k; i++) {
            if (left < 0) {
                // Only take from right
                if (i == k) {
                    cout << abs(A[right] - b) << '\n';
                    break;
                }
                right++;
            } else if (right >= N) {
                // Only take from left
                if (i == k) {
                    cout << abs(A[left] - b) << '\n';
                    break;
                }
                left--;
            } else {
                // Take the closer one
                ll dist_left = b - A[left];
                ll dist_right = A[right] - b;
                
                if (dist_left <= dist_right) {
                    if (i == k) {
                        cout << dist_left << '\n';
                        break;
                    }
                    left--;
                } else {
                    if (i == k) {
                        cout << dist_right << '\n';
                        break;
                    }
                    right++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}