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
    vector<pair<ll, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {a[i], i};
    }
    sort(p.begin(), p.end());
    vector<ll> prefix_sums(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sums[i] = p[i].first + sum;
        sum += p[i].first;
    }
    vector<ll> remaining_votes(k);
    iota(remaining_votes.begin(), remaining_votes.end(), 0);
    vector<ll> ans(n, -1);
    for (int i = n - 1; i >= n - m; i--) {
        ll remaining_votes_sum = prefix_sums[i] - (i == 0 ? 0 : prefix_sums[i - 1]);
        ll votes_needed = m * a[p[i].second] - remaining_votes_sum + i;
        if (votes_needed > k - remaining_votes_sum) {
            ans[p[i].second] = -1;
        } else {
            ans[p[i].second] = votes_needed;
        }
        k -= votes_needed;
    }
    for (int i = n - m - 1; i >= 0; i--) {
        ll votes_needed = m * a[p[i].second] - (i == 0 ? 0 : prefix_sums[i - 1]);
        if (votes_needed > k) {
            ans[p[i].second] = -1;
        } else {
            ans[p[i].second] = votes_needed;
        }
        k -= votes_needed;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            continue;
        }
        if (k > 0) {
            ans[i] += k;
            k = 0;
        }
        cout << ans[i] << " ";
    }
    if (k > 0) {
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = k;
            } else {
                ans[i] += k;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}