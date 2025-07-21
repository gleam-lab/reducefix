#include<bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 1);
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % M;
    }

    map<ll, ll> freq;
    freq[0] = 1; // Initial prefix sum is zero
    ll ans = 0;
    
    for(int i = 1; i <= n; i++) {
        // We want to find number of previous prefix sums equal to current prefix
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
    }
    
    cout << ans << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}