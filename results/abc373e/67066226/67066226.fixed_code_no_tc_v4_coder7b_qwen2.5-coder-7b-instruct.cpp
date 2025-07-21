#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<pair<ll, int>> candidates(n);
    for(int i = 0; i < n; i++) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end());
    vector<ll> prefix_sum(n + 1);
    for(int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].first;
    }
    vector<ll> result(n, -1);
    for(int i = 0; i < n; i++) {
        ll needed_votes = 0;
        for(int j = n - 1; j > i; j--) {
            if(j - i - 1 >= m) break;
            needed_votes += candidates[j].first + 1;
        }
        if(needed_votes <= k) {
            result[candidates[i].second] = needed_votes - candidates[i].first;
        } else {
            result[candidates[i].second] = -1;
        }
    }
    for(ll i : result) cout << i << " ";
    return 0;
}