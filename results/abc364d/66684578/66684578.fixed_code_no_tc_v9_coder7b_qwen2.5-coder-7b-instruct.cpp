#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main(){
    int n,q,b,k;cin >> n >> q;
    vi a(n), dist(n);
    
    rep(i,n){
        cin >> a[i];
    } 
    
    rep(i,q){
        cin >> b >> k;
        rep(j,n){
            dist[j] = abs(a[j] - b);
        }
        sort(dist.begin(), dist.end());
        cout << dist[k-1] << endl;
    }
}