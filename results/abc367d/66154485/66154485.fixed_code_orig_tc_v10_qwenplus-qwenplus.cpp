#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Prefix sum modulo m
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }

    // Count frequencies of each mod value
    map<int, int> freq;
    for (int mod : prefix_mod) {
        freq[mod]++;
    }

    long long ans = 0;
    // For each unique mod value, count pairs that cancel it modulo m
    for (auto& [r, count] : freq) {
        if (count >= 2) {
            ans += 1LL * count * (count - 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}