#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Binary search for the smallest radius r such that there are at least k points within distance r from b.
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

        // Binary search bounds: from 0 to max possible distance
        ll left = 0, right = 2e8 + 1;

        auto count_points_in_radius = [&](ll radius) {
            ll low = b - radius;
            ll high = b + radius;
            // Use lower_bound and upper_bound to find how many elements in A are within [low, high]
            auto l = lower_bound(A.begin(), A.end(), low);
            auto r = upper_bound(A.begin(), A.end(), high);
            return r - l;
        };

        // Binary search to find the k-th smallest distance
        while (left < right) {
            ll mid = (left + right) / 2;
            if (count_points_in_radius(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        cout << left << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}