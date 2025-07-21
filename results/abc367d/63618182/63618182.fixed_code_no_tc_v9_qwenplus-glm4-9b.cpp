#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5+10, mod = 1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+10);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> s(n+10);
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
    }
    map<int, int> mp;
    ll ans = 0, L = s[n];
    for(int i = 1; i <= n; i++){
        int mod_s = (s[i] - L + M) % M;
        ans += mp[mod_s]++;
        int norm_s = s[i] % M;
        if (norm_s == 0) mp[norm_s]++;
        else mp[norm_s]--;
    }
    for (auto& p : mp) ans += p.second;
    cout << (ans - 1) << "\n"; // Subtract 1 to avoid double counting the element
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}