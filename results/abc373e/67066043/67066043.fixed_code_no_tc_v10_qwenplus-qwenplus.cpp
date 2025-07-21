#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll total_so_far = accumulate(all(a), 0LL);
    ll remaining = k - total_so_far;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index
        ll current = a[i];

        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = current + mid;

            // Binary search to find how many candidates have votes > target
            int left = upper_bound(all(sorted_a), target) - sorted_a.begin();

            // We want at least (n - M + 1) candidates with votes <= target
            // That means we can allow at most (M - 1) candidates to have more than target
            // So, if number of candidates with votes > target >= M, then candidate i is not safe

            // But we must also consider the current candidate
            int count_gt = n - left;

            if (i >= left && count_gt >= m) {
                // Candidate i is not in the top M-1, and there are too many > target
                low = mid + 1;
            } else {
                answer = mid;
                high = mid - 1;
            }
        }

        res[i] = (answer == -1 ? -1 : answer);
    }

    for (auto x : res) {
        cout << (x < 0 ? -1 : x) << ' ';
    }
}