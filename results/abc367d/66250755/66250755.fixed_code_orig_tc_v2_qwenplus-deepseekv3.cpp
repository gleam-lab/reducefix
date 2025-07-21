#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }

    vector<int> prefix_sum(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[(i - 1) % n]) % m;
    }

    long long res = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;

    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            int prev_mod = prefix_sum[i - n];
            freq[prev_mod]--;
            if (freq[prev_mod] == 0) {
                freq.erase(prev_mod);
            }
        }
        res += freq[prefix_sum[i]];
        freq[prefix_sum[i]]++;
    }

    cout << res << endl;
    return 0;
}