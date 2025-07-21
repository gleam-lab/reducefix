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
    vector<ll> a(n + 2);  // Use ll for better handling of large values
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 2);
    for(int i = 1; i <= n; i++) {
        prefix[i] = (prefix[i - 1] + a[i]) % M;
    }

    map<ll, ll> freq;
    ll ans = 0;

    for(int i = 0; i <= n; i++) {
        // Normalize the value to be within [0, M)
        ll rem = prefix[i] % M;
        if(rem < 0) rem += M;  // Ensure non-negative remainder

        // Count how many previous prefixes had the same remainder
        ans += freq[rem];
        freq[rem]++;
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