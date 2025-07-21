#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    long long sum = 0;
    map<int, int> freq;

    // Input array elements and calculate the running sum modulo m
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = (sum + a[i]) % m;

        // Frequency map for modulo results
        freq[sum]++;
    }

    // If sum is 0, we can directly return 1 because the sum is already zero
    if (sum == 0) {
        cout << 1 << '\n';
        return;
    }

    long long res = 0;

    // We need to calculate the number of zeros modulo m using the frequency map
    // The frequency of 0 modulo m is the answer for the problem
    for (const auto& p : freq) {
        res += p.second;
    }

    cout << res << '\n';
}

int main() {
    int T = 1;
    while (T--) solve();
    return 0;
}