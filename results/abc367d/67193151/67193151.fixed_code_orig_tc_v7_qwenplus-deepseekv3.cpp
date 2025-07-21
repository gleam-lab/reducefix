#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, a[N * 2], prefix[N * 2];
unordered_map<int, int> freq;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }
    
    long long ans = 0;
    freq[0] = 1;
    
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            int mod = prefix[i - n] % m;
            freq[mod]--;
        }
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
    }
    
    cout << ans << endl;
    return 0;
}