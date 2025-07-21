#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
typedef long long ll;

int n, m, a[N], prefix[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // Duplicate the array for circular handling
    }

    // Compute prefix sums mod m
    ll res = 0;
    cnt[0] = 1;  // To count subarrays starting from index 0
    for (int i = 1; i < 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
        res += cnt[prefix[i]];
        cnt[prefix[i]]++;
        
        // Maintain only the first n elements in the map to keep valid window
        if (i >= n) {
            cnt[prefix[i - n]]--;
            if (cnt[prefix[i - n]] == 0)
                cnt.erase(prefix[i - n]);
        }
    }

    cout << res << "\n";
    return 0;
}