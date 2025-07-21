#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q;cin >> n >> q;
    vector<ll> a(n), distances(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    for(int i=0; i<q; i++){
        ll b, k; cin >> b >> k;
        for(int j=0; j<n; j++) distances[j] = abs(a[j] - b);
        sort(distances.begin(), distances.end());
        cout << distances[k-1] << '\n';
    }
    
    return 0;
}