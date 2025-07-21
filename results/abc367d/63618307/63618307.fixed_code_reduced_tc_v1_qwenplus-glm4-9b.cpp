#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int>a(n+10);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Calculate prefix sums modulo M
    vector<int> S(n+1);
    for(int i = 0; i < n; i++){
        S[i+1] = (S[i] + a[i]) % M;
    }

    // Map to count frequency of each remainder
    map<int, int> mp;
    ll ans = 0;

    // Iterate over all possible remainders
    for(int rem = 0; rem < M; rem++){
        // Calculate the number of pairs with the current remainder
        mp[rem] = upper_bound(S.begin(), S.end(), (rem + M) % M) - upper_bound(S.begin(), S.end(), rem);
        ans += mp[rem] * (mp[rem] - 1) / 2; // Combination formula for choosing 2 out of mp[rem]
    }

    cout << ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}