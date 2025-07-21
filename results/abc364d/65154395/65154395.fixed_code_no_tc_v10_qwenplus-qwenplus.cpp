#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the A array for binary search purposes
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search to find the k-th closest distance
        auto get_kth_distance = [&](int k) {
            // We'll use a two pointer approach from the position of b in the sorted array
            int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
            
            int left = pos - 1;
            int right = pos;
            int count = 0;
            
            while (count < k && (left >= 0 || right < N)) {
                if (left >= 0 && (right >= N || abs(A[left] - b) <= abs(A[right] - b))) {
                    left--;
                } else {
                    right++;
                }
                count++;
            }
            
            if (count < k) return -1LL; // Should not happen
            
            // Find the actual k-th distance
            if (left >= 0 && (right >= N || abs(A[left] - b) <= abs(A[right] - b))) {
                return abs(A[left + (k - count)] - b);
            } else {
                return abs(A[right - 1 - (k - count)] - b);
            }
        };
        
        cout << get_kth_distance(k) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}