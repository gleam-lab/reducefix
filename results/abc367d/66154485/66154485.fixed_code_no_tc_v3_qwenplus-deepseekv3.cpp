#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= m;
    }

    long long ans = 0;
    vector<long long> prefix_sum(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        prefix_sum[i] = (prefix_sum[i - 1] + arr[(i - 1) % n]) % m;
    }

    unordered_map<int, int> freq;
    freq[0] = 1;
    
    for (int i = 1; i <= 2 * n; i++) {
        if (i > n) {
            int prev_mod = prefix_sum[i - n];
            freq[prev_mod]--;
            if (freq[prev_mod] == 0) {
                freq.erase(prev_mod);
            }
        }
        ans += freq[prefix_sum[i]];
        freq[prefix_sum[i]]++;
    }

    cout << ans << endl;
    return 0;
}