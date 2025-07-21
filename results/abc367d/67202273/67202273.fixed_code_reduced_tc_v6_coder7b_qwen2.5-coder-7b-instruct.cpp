#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 4e5 + 10;
long long a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, ans = 0;
    cin >> n >> m;
    
    // Read the array twice to simulate circular nature
    for(long long i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n+i] = a[i];
    }

    // Calculate prefix sums modulo m
    for(long long i = 1; i <= 2 * n; ++i) {
        sum[i] = (sum[i-1] + a[i]) % m;
    }

    // Count occurrences of each prefix sum
    unordered_map<long long, int> freq;
    for(long long i = 1; i <= 2 * n; ++i) {
        freq[sum[i]]++;
    }

    // Calculate the number of valid subarrays
    for(long long i = n + 1; i <= 2 * n; ++i) {
        long long target = (sum[i] - sum[i - n] + m) % m;
        ans += freq[target];
    }

    cout << ans << endl;
    return 0;
}