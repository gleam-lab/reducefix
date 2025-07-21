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
        k--; // Convert to 0-based index for easier handling

        // Lambda to count how many elements are <= x
        auto count_less_equal = [&](ll x) {
            return upper_bound(A.begin(), A.end(), x) - A.begin();
        };

        // Binary search to find the k-th closest element
        ll left = -2e18, right = 2e18;
        ll answer = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            ll cnt = count_less_equal(b + mid) - count_less_equal(b - mid - 1);
            if (cnt > k) {
                right = mid - 1;
                answer = mid;
            } else {
                left = mid + 1;
            }
        }

        // Now, find the exact k-th closest element
        vector<ll> candidates;
        ll low = b - answer, high = b + answer;
        auto lower = lower_bound(A.begin(), A.end(), low);
        auto upper = upper_bound(A.begin(), A.end(), high);
        for (auto it = lower; it != upper; ++it) {
            candidates.push_back(abs(*it - b));
        }
        sort(candidates.begin(), candidates.end());
        cout << candidates[k] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}