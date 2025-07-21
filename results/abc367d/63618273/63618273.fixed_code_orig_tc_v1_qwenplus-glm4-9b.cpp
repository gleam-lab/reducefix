#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10, mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> s(n+2);
    for(int i = 1; i <= n; i++) {
        s[i+1] = s[i] + a[i];
    }
    vector<int> count_mod(n+2, 0);
    ll ans = 0, total_sum = s[n+1];
    
    for(int i = 1; i <= n; i++) {
        ll sum_mod = (s[i] % mod + mod) % mod; // Normalize the remainder to be within [0, M-1]
        sum_mod = (sum_mod + n) % M; // Adjust to account for the number of elements
        ans += count_mod[(total_sum - s[i] + M) % M];
        count_mod[sum_mod]++;
    }
    
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}