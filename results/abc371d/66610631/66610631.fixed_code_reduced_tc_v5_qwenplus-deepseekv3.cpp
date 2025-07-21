#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; ++i) {
        cin >> pairs[i].first;
    }
    for(int i = 0; i < n; ++i) {
        cin >> pairs[i].second;
    }
    sort(pairs.begin(), pairs.end());

    vector<ll> prefix(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + pairs[i - 1].second;
    }

    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto left_it = lower_bound(pairs.begin(), pairs.end(), make_pair(l, 0));
        auto right_it = upper_bound(pairs.begin(), pairs.end(), make_pair(r, INT_MAX));
        int left_idx = left_it - pairs.begin();
        int right_idx = right_it - pairs.begin();
        cout << (prefix[right_idx] - prefix[left_idx]) << '\n';
    }
    return 0;
}