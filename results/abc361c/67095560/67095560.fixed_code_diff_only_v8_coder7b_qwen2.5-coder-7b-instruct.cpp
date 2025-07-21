#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
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

typedef long long ll;
typedef long double ld;

void solve(){
    int k,n;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    
    // Sort the array to easily find the minimum and maximum values
    sort(all(a));
    
    // The optimal way to minimize the difference between max and min of B
    // is to remove the smallest K elements or the largest K elements
    // because removing elements from both ends would not help in minimizing the difference
    
    // Calculate the difference after removing the smallest K elements
    ll mini1 = a[n-k-1] - a[0];
    
    // Calculate the difference after removing the largest K elements
    ll mini2 = a[n-1] - a[k];
    
    // Print the minimum of the two differences
    cout << min(mini1, mini2);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}