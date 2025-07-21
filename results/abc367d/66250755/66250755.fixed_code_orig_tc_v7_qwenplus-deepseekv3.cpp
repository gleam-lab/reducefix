#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }

    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
    }

    unordered_map<int, long long> freq;
    long long result = 0;
    for (int i = 0; i <= n; ++i) {
        result += freq[prefix_sum[i]];
        freq[prefix_sum[i]]++;
    }

    cout << result << endl;
    return 0;
}