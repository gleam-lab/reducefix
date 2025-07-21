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

    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }

    sort(all(candidates));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);

    for (int i = 0; i < n; i++) {
        ll needed = 0;
        for (int j = i + 1; j < n; j++) {
            if (candidates[j].first > candidates[i].first) {
                needed += candidates[j].first - candidates[i].first;
            }
        }

        if (needed > k) continue;

        ll target = (k - needed) / (n - i - 1);
        ll excess = (k - needed) % (n - i - 1);

        for (int j = i + 1; j < n; j++) {
            if (candidates[j].first <= candidates[i].first + target) {
                if (excess > 0) {
                    ans[candidates[j].second] = target + 1;
                    excess--;
                } else {
                    ans[candidates[j].second] = target;
                }
            }
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}