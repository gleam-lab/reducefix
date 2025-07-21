#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

void solve() {
    ll n;
    cin >> n;
    vi a(n);
    for(ll &x: a) cin >> x;
    
    ll time = 0;
    while(1){
        bool any = false;
        for(int i=0; i<n; i++){
            if(a[i]>0){
                any = true;
                if((time+1)%3==0){
                    a[i]-=3;
                }else{
                    a[i]-=1;
                }
                if(a[i]<0) a[i]=0;
            }
        }
        if(!any) break;
        time++;
    }

    cout<<time<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}