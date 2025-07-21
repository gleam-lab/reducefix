#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
        int low = 0, high = N - 1;
        // Binary search to find the k-th closest point
        // We need to find the point where exactly k-1 points are closer or equal in distance
        auto cmp = [&](int mid) {
            // The number of points <= A[mid] is mid + 1
            // But we need to find the k-th smallest distance
            // So we need to consider the distances |A[i] - b|
            // We can use binary search to find the k-th smallest |A[i] - b|
            // The idea is to find the smallest d such that there are at least k points with |A[i] - b| <= d
            ll left = lower_bound(A.begin(), A.end(), b) - A.begin();
            ll right = upper_bound(A.begin(), A.end(), b) - A.begin();
            if (k <= right - left) {
                return 0; // There are at least k points at distance 0
            }
            ll needed = k - (right - left);
            ll l = 0, r = 1e18;
            ll ans = 1e18;
            while (l <= r) {
                ll mid_dist = (l + r) / 2;
                ll cnt = right - left;
                // Count points with A[i] < b - mid_dist
                ll left_cnt = lower_bound(A.begin(), A.end(), b - mid_dist) - A.begin();
                cnt += left - left_cnt;
                // Count points with A[i] > b + mid_dist
                ll right_cnt = upper_bound(A.begin(), A.end(), b + mid_dist) - A.begin();
                cnt += right_cnt - right;
                if (cnt >= k) {
                    ans = mid_dist;
                    r = mid_dist - 1;
                } else {
                    l = mid_dist + 1;
                }
            }
            return ans;
        };
        
        ll d = cmp(0);
        cout << d << '\n';
    }
    return 0;
}