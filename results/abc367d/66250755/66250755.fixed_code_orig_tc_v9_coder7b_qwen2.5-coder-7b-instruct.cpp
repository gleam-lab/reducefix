#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), prefix_sum(n * 2 + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[n + i] = a[i];
    }
    
    vector<int> count(m);
    long long result = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i - 1]) % m;
        if (i > n) {
            result += count[(prefix_sum[i - n] - prefix_sum[i - n - 1] + m) % m];
            result %= MOD;
        }
        count[prefix_sum[i]]++;
    }
    
    cout << result << '\n';
    return 0;
}