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

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        ll low = 0, high = 2e18;
        ll answer = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            ll left = b - mid;
            ll right = b + mid;
            
            auto it_l = lower_bound(A.begin(), A.end(), left);
            auto it_r = upper_bound(A.begin(), A.end(), right);
            ll count = it_r - it_l;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}