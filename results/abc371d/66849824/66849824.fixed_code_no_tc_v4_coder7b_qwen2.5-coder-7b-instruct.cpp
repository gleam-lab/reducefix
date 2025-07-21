#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n;
    vector<ll> pos(n), population(n);
    for(int i = 0; i < n; ++i) cin >> pos[i];
    for(int i = 0; i < n; ++i) cin >> population[i];

    vector<ll> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for(int i = 0; i < n; ++i) prefix_sum[i + 1] = prefix_sum[i] + population[i];

    cin >> q;
    while(q--) {
        int left, right;
        cin >> left >> right;
        auto it_left = lower_bound(pos.begin(), pos.end(), left);
        auto it_right = upper_bound(pos.begin(), pos.end(), right);

        int idx_left = it_left - pos.begin();
        int idx_right = it_right - pos.begin();

        if(idx_left == n || pos[idx_left] > right) --idx_left;
        if(idx_right == 0 || pos[idx_right - 1] < left) ++idx_right;

        ll result = prefix_sum[min(idx_right, n)] - prefix_sum[max(0, idx_left)];
        cout << result << '\n';
    }

    return 0;
}