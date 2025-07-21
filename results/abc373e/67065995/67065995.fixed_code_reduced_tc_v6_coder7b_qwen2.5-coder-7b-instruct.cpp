#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<ll, int>> sorted_a(n);
    for(int i = 0; i < n; ++i) {
        sorted_a[i] = {a[i], i};
    }
    sort(sorted_a.begin(), sorted_a.end());

    vector<ll> prefix_sum(n + 1);
    for(int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_a[i].first;
    }

    vector<ll> result(n, -1);
    for(int i = 0; i < n; ++i) {
        int id = sorted_a[i].second;
        ll votes_needed = 0;
        if(i >= n - m) {
            votes_needed = k + 1 - prefix_sum[n] + prefix_sum[i + 1];
        } else {
            int left = i + 1, right = n - m - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(prefix_sum[mid + 1] - prefix_sum[i + 1] >= (prefix_sum[n] - prefix_sum[mid + 1]) * (sorted_a[i].first + mid + 1)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if(left < n - m) {
                votes_needed = left + 1 - sorted_a[i].first;
            } else {
                votes_needed = k + 1 - prefix_sum[n] + prefix_sum[i + 1];
            }
        }
        result[id] = max(votes_needed, 0LL);
    }

    for(ll x : result) {
        cout << x << " ";
    }
    return 0;
}