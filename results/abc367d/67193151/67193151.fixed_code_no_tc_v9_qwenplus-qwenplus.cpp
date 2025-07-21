#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

int n, m;
ll a[N * 2], prefix[N * 2];
map<int, int> cnt;
ll ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    // Compute prefix sums
    for(int i = 1; i < 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    
    cnt[0] = 1; // For subarrays starting from index 0
    
    for(int i = 1; i < 2 * n; ++i) {
        int rem = (prefix[i] % m + m) % m;
        ans += cnt[rem];
        if (i < n) {
            cnt[rem]++;
        }
    }
    
    cout << ans;
    return 0;
}