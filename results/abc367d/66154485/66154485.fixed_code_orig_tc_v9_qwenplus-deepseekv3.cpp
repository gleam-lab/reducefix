#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    for (int i = 0; i <= n; ++i) {
        prefix[i] %= m;
        if (prefix[i] < 0) {
            prefix[i] += m;
        }
    }

    unordered_map<int, int> freq;
    freq[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
    }

    cout << ans << endl;
    return 0;
}