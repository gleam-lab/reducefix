#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vl a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // Precompute prefix sums for efficient range sum queries
    vl prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    
    auto get_sum = [&](int l, int r) {
        return prefix[r] - prefix[l];
    };
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search to find the k-th smallest distance
        ll low = 0, high = 2e14 + 10; // Safe upper bound
        ll answer = high;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            
            // Find the range [L, R) of elements in 'a' within distance 'mid' from 'b'
            int L = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int R = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            
            if (R - L >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << "\n";
    }
}