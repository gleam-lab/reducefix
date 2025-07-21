#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> suffix_sum(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + a[i];
    }

    auto check = [&](ll add_votes) {
        vector<ll> new_a(n);
        copy(begin(a), end(a), begin(new_a));

        for (int i = 0; i < n; ++i) {
            new_a[i] += add_votes;
        }

        sort(rbegin(new_a), rend(new_a));

        for (int i = 0; i < m - 1; ++i) {
            new_a[i] = 0;
        }

        ll total_votes = accumulate(begin(new_a), end(new_a), 0LL);
        return total_votes <= k;
    };

    vector<ll> results(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= k) {
            results[i] = 0;
            continue;
        }

        ll left = 0, right = k - a[i];
        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        results[i] = left;
    }

    for (int i = 0; i < n; ++i) {
        if (results[i] == k - a[i]) {
            results[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}