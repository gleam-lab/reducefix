#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Remaining votes
    ll total_remaining = k;
    for (ll ai : a) {
        total_remaining -= ai;
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<ll> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index of candidate
        ll target = a[i];

        ll low = 0;
        ll high = total_remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_score = target + mid;

            // Find how many candidates have score strictly greater than new_score
            // in the current sorted array
            int pos = lower_bound(sorted_a.begin(), sorted_a.end(), new_score + 1) - sorted_a.begin();
            int num_above = n - pos;

            // We need to ensure at least (M) candidates have scores > new_score
            // but we can boost up to (total_remaining - mid) remaining votes

            // How many more candidates (beyond pos) can we make > new_score?
            int needed = max(0, m - num_above);

            // Find how many candidates are in [pos, n)
            // These are the candidates that are <= new_score but could be boosted above it

            ll cost = 0;
            if (needed > 0) {
                int from = pos;
                int to = min(pos + needed, n);
                cost = (to - from) * (new_score + 1) - (prefix[to] - prefix[from]);
            }

            if (cost + mid <= total_remaining) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = (answer == -1 ? -1 : answer);
    }

    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";
}