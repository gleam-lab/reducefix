#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1), prefix(n + 1);

    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) cin >> p[i];

    prefix[0] = 0;
    for(int i = 1; i <= n; ++i) 
        prefix[i] = prefix[i - 1] + p[i];

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        // Find the smallest index j such that x[j] >= l using binary search
        auto it_l = lower_bound(x.begin(), x.end(), l);
        int j = distance(x.begin(), it_l);

        // Find the largest index k such that x[k] <= r using binary search
        auto it_r = upper_bound(x.begin(), x.end(), r);
        int k = distance(x.begin(), it_r) - 1;

        // Calculate the sum of p[i] for i from j to k
        long long result = prefix[min(k, n)] - prefix[max(j - 1, 0)];
        cout << result << endl;
    }

    return 0;
}