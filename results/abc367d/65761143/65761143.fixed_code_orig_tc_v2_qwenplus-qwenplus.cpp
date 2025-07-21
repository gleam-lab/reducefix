#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x %= m; // Ensure all values are within modulus
    }

    map<long long, long long> prefix_counts;
    long long current_sum = 0;
    long long result = 0;
    prefix_counts[0] = 1; // To count subarrays starting from index 0

    for (int i = 0; i < n; ++i) {
        current_sum = (current_sum + a[i]) % m;
        result += prefix_counts[current_sum];
        prefix_counts[current_sum]++;
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    static ifstream in("in.txt");
    static ofstream out("out.txt");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
#endif

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}