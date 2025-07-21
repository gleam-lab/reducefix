#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x %= m;
    }

    // Prefix sum mod m
    vector<int> prefix_mod(n + 1);
    for (int i = 0; i < n; ++i)
        prefix_mod[i + 1] = (prefix_mod[i] + a[i]) % m;

    // Count of each mod value in prefix sums
    map<int, int> cnt;
    LL res = 0;

    // We'll use two maps to handle even and odd groupings based on the parity of occurrences
    map<int, int> freq[2];
    freq[0][0] = 1;  // Initialize base case

    int total_sum_mod = prefix_mod[n];

    int parity = 0;
    for (int i = 1; i <= n; ++i) {
        int curr = prefix_mod[i];
        int target = (curr - total_sum_mod + m) % m;

        res += freq[parity].count(curr);  // same prefix mod value => subarray sum divisible by m
        res += freq[1 - parity].count(target);  // adjusted target for full sum condition

        freq[parity][curr]++;
        parity = 1 - parity;  // alternate between maps
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    static ifstream in("in.txt");
    static ofstream out("out.txt");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
#endif

    int T = 1;
    // Uncomment below if multiple test cases are needed
    // cin >> T;
    while (T--) solve();

    return 0;
}