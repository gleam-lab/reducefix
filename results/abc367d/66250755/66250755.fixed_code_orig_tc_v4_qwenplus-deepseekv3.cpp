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

    vector<int> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    unordered_map<int, int> freq;
    long long res = 0;
    freq[0] = 1;

    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            int prev_mod = prefix[i - n] % m;
            freq[prev_mod]--;
            if (freq[prev_mod] == 0) {
                freq.erase(prev_mod);
            }
        }
        res += freq[prefix[i]];
        freq[prefix[i]]++;
    }

    cout << res << endl;
    return 0;
}