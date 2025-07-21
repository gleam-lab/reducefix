#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
// #define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long


// ll inf=(1ll<<62);

// ll rui(ll a,ll b){
//     if(b==0)return 1;
//     if(b%2==1) return a*rui(a*a,b/2);
//     return rui(a*a,b/2);
// }





int big=100000004;
int get(map<int,int> &mp,int m){
    if(mp.find(m)!=mp.end())return mp[m];
    return (--mp.lower_bound(m))->second;
}

int main(){
    int n,q,b,k;cin >> n >> q;
    map<int,int> mp;
    vi a(n);
    rep(i,n){
        cin >> a[i];
    } 
    
    rep(i,n){
        mp[a[i]]++;
    }
    mp[-big*2]=0;
    int now=0;
    for(auto &p:mp){
        p.second+=now;
        now=p.second;
    }
    // for(auto &p:mp){
    //     cout << p.first << ":" << p.second << endl;
    // }
    // for(int i=-10;i<=10;i++){
    //     printf("%d:%d\n",i,get(mp,i));
    // }
    rep(i,q){
        cin >> b >> k;
        int l=-1,r=big*1.5;
        while(r-l>1){
            int m=(r+l)/2;
            if(get(mp,b+m)-get(mp,b-m-1)<k)l=m;
            else r=m;
        }
        cout << r << endl;
    }
    // rep(i,10000){
    //     int a;cin >> a;
    //     cout << get(mp,a) << endl;
    // }
}