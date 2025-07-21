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

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = (prefix[i] + a[i]) % m;
    }

    unordered_map<int, long long> freq;
    freq[0] = 1;
    long long result = 0;

    for (int i = 1; i <= n; ++i) {
        int mod = prefix[i];
        result += freq[mod];
        freq[mod]++;
    }

    cout << result << endl;
    return 0;
}