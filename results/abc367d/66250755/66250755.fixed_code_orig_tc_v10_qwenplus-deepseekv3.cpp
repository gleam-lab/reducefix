#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    vector<long long> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    unordered_map<int, int> freq;
    long long ans = 0;
    freq[0] = 1;

    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            int prev_prefix = prefix[i - n];
            freq[prev_prefix]--;
            if (freq[prev_prefix] == 0) {
                freq.erase(prev_prefix);
            }
        }
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
    }

    cout << ans << endl;
    return 0;
}