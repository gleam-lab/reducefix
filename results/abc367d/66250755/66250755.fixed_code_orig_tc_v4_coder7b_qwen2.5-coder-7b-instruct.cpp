#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a.push_back(a[i]); // Duplicate the array to handle circular nature
    }

    unordered_map<long long, int> prefix_count;
    prefix_count[0]++;
    long long current_sum = 0;
    long long result = 0;

    for (int i = 0; i < 2 * n; ++i) {
        current_sum = (current_sum + a[i]) % m;
        result = (result + prefix_count[(current_sum - m + m) % m]) % MOD;
        prefix_count[current_sum]++;
    }

    cout << result << endl;
    return 0;
}