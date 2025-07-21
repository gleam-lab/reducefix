#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n;
    vector<ll> x(n + 1), p(n + 1), prefix_sum(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> x[i];

    for (int i = 1; i <= n; ++i)
        cin >> p[i], prefix_sum[i] = prefix_sum[i - 1] + p[i];

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first index where x[index] >= l using binary search
        auto l_i = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        // Find the first index where x[index] > r using binary search
        auto r_i = upper_bound(x.begin() + 1, x.end(), r) - x.begin();

        // Adjust indices to be within valid range [1, n]
        if (l_i == 0) l_i = 1;
        if (r_i > n) r_i = n;

        // Calculate the result based on adjusted indices
        ll result = prefix_sum[r_i - 1] - (l_i == 1 ? 0 : prefix_sum[l_i - 2]);
        cout << result << '\n';
    }

    return 0;
}