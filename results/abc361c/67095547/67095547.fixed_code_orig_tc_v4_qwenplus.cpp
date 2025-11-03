#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pi 2*acos(0.0)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define ff first
#define ss second 
#define mod 1e9+7
#define inf INT_MAX
#define all(v) v.begin(), v.end()
#define revs(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define distmax(a) distance(a.begin(),max_element(all(a)))
#define distmin(a) distance(a.begin(),min_element(all(a)))
#define mem(a,b) memset(a, b, sizeof(a))
#define gcd(a,b) __gcd(a, b)
#define lcm(a, b) ((a / __gcd(a, b) ) * b)
#define sqr(x) (x*x)
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define repn(i,x) for(int i=1;i<=(int)(x);i++)
#define repo(i,x) for(int i=x-1;i>=0;i--)
#define sp(i) fixed<<setprecision(i)
#define l1s(n) __builtin_popcount(n)
#define ll1s(x) __builtin_popcountll(x)
#define permute(v) next_permutation(all(v))
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    sort(all(a));
    
    // We are removing exactly K elements
    // So we will keep (n - k) elements
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // First window: take first 'keep' elements
    
    // Try all possible windows of size 'keep'
    for(int i = 1; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        ans = min(ans, a[j] - a[i]);
    }
    
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}