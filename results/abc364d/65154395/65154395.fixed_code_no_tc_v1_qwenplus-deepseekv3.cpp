#include<bits/stdc++.h>
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
        ll b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        // Binary search to find the smallest 'd' such that at least 'k' points have distance <= d from b
        ll low = 0, high = 2e14;
        ll answer = high;
        while (low <= high) {
            ll mid = (low + high) / 2;
            // Count the number of points in A with |A_i - b| <= mid
            auto it_low = lower_bound(A.begin(), A.end(), b - mid);
            auto it_high = upper_bound(A.begin(), A.end(), b + mid);
            int count = it_high - it_low;
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}