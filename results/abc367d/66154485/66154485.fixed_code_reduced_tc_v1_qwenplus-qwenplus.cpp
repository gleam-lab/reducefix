#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;

    // Try each starting point once (due to circular nature)
    for (int start = 0; start < 1; ++start) {
        vector<long long> prefix_mod(n + 1, 0);
        map<long long, long long> freq;
        freq[0] = 1;

        for (int i = 1; i <= n; ++i) {
            prefix_mod[i] = (prefix_mod[i - 1] + arr[(start + i - 1) % n]) % m;
            ans += freq[prefix_mod[i]];
            freq[prefix_mod[i]]++;
        }
    }

    cout << ans << endl;
    return 0;
}