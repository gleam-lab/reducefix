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
        
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int pos = left;
        
        int low = 0, high = 2e8;
        ll res = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            int l = lower_bound(A.begin(), A.end(), b - mid) - A.begin();
            int r = upper_bound(A.begin(), A.end(), b + mid) - A.begin();
            if (r - l >= k) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}