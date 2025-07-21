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
        k -= a[i];
    }

    // Create sorted version of a
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }
    sort(all(candidates));

    vector<ll> sorted_a(n);
    for (int i = 0; i < n; i++) {
        sorted_a[i] = candidates[i].first;
    }

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_a[i];
    }

    vector<ll> result(n, -1);

    for (int i = 0; i < n; i++) {
        ll low = 0;
        ll high = k;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = a[i] + mid;

            // Binary search to find how many candidates have votes > target
            int idx = n - (upper_bound(sorted_a.begin(), sorted_a.end(), target) - sorted_a.begin());

            if (idx < m) {
                // Candidate i is already in top M candidates
                answer = mid;
                high = mid - 1;
            } else {
                // Need to increase their votes
                low = mid + 1;
            }
        }

        result[candidates[i].second] = answer;
    }

    for (int i = 0; i < n; i++) {
        cout << max(0LL, result[i]) << " ";
    }
    cout << "\n";
}