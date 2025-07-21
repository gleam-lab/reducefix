#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
        k--; // convert to 0-based index

        int left = 0, right = N - 1;
        ll res = 0;
        
        // Binary search to find the k-th smallest distance
        // The idea is to find the smallest distance d such that there are at least k+1 elements with distance <= d
        ll low = 0, high = 2e14; // Sufficiently large upper bound
        while (low <= high) {
            ll mid = (low + high) / 2;
            auto it_l = lower_bound(A.begin(), A.end(), b - mid);
            auto it_r = upper_bound(A.begin(), A.end(), b + mid);
            int count = it_r - it_l;
            
            if (count > k) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << res << '\n';
    }

    return 0;
}