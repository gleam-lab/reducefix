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
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = 0, right = 2e8 + 10; // Since max possible distance is ~2e8
        
        while (left < right) {
            ll mid = (left + right) / 2;
            // Count how many points have distance <= mid from b
            ll cnt = 0;
            int l = lower_bound(A.begin(), A.end(), b - mid) - A.begin();
            int r = upper_bound(A.begin(), A.end(), b + mid) - A.begin();
            cnt = r - l;
            
            if (cnt >= k)
                right = mid;
            else
                left = mid + 1;
        }
        
        cout << left << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}