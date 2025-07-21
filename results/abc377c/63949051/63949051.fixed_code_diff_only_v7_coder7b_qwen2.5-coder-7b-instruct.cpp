#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define F first
#define S second
#define MOD 1000000007
#define MAXN 1000000000

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    ll n,m;
    cin >> n >> m;
    unordered_set<pii> pieces;
    for(ll i=0;i<m;++i){
        ll x,y;
        cin >> x >> y;
        pieces.insert({x-1,y-1});
    }
    
    ll ans=n*n-pieces.size();
    cout << ans << '\n';
    
    return 0;
}