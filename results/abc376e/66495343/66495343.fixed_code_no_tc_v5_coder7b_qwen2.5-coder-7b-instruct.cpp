#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define arr array<int, 3>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[N], b[N];
pii ab[N];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        ab[i] = {a[i], b[i]};

    // Sort pairs by the product of a_i and b_i
    sort(ab + 1, ab + 1 + n);

    ll res = INF, sum = 0;
    vector<pii> selected;

    // Iterate through the sorted pairs
    for (int i = 1; i <= n; ++i) {
        if (selected.size() == k - 1) {
            // Calculate the current result
            res = min(res, (ab[i].fi * sum));
            // Remove the smallest element in the selected set
            auto it = min_element(selected.begin(), selected.end());
            sum -= it->se;
            selected.erase(it);
        }
        // Add the current element to the selected set
        selected.push_back(ab[i]);
        sum += ab[i].se;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}