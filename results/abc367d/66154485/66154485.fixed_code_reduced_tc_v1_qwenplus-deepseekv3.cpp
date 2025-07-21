#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long total = 0;
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    unordered_map<int, int> mod_counts;
    mod_counts[0] = 1;  // empty prefix
    for (int i = 1; i <= n; i++) {
        int mod = (prefix[i] % m + m) % m;
        total += mod_counts[mod];
        mod_counts[mod]++;
    }

    cout << total << endl;
    return 0;
}