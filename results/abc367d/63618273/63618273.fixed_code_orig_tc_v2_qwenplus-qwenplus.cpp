#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int MOD = 281;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll M;
    cin >> n >> M;
    vector<ll> prefix_sums(n + 1, 0);
    ll total = 0;

    // Read array and compute prefix sums modulo M
    for (int i = 1; i <= n; ++i) {
        ll val;
        cin >> val;
        prefix_sums[i] = (prefix_sums[i - 1] + val) % M;
        total = (total + prefix_sums[i]) % MOD;
    }

    // Count frequencies of each prefix sum mod M
    map<ll, ll> freq;
    ll result = 0;

    // We include the empty prefix (sum 0 at index 0)
    freq[0] = 1;

    for (int i = 1; i <= n; ++i) {
        ll current = prefix_sums[i];
        // Add all subarrays ending at i where (prefix[j] == current)
        result += freq[current];
        freq[current]++;
    }

    cout << result << endl;
    return 0;
}