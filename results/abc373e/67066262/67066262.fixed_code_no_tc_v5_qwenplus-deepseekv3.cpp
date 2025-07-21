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
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    ll rem = k - total;
    for (int i = 0; i < n; i++) {
        ll low = 0, high = rem + 1;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = b[i] + mid;
            ll pos = upper_bound(all(b), new_vote) - b.begin();
            pos = n - pos;
            if (pos < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1) {
            ll new_vote = b[i] + best;
            ll sum_extra = 0;
            ll cnt = 0;
            ll pos = upper_bound(all(b), new_vote) - b.begin();
            for (int j = pos; j < n; j++) {
                if (b[j] >= new_vote) {
                    sum_extra += (b[j] - new_vote + 1);
                    cnt++;
                }
            }
            if (sum_extra <= rem - best) {
                ans[ord[i]] = best;
            } else {
                ll needed = sum_extra - (rem - best);
                if (best + needed <= rem) {
                    ans[ord[i]] = best + needed;
                } else {
                    ans[ord[i]] = -1;
                }
            }
        } else {
            ans[ord[i]] = -1;
        }
    }
    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;
}