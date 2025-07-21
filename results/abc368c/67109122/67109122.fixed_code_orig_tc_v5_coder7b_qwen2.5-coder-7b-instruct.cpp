#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    vector<ll> h(n+1);
    for(ll i=1;i<=n;i++)
        cin>>h[i];

    ll t=0;
    while(true){
        bool flag=true;
        for(ll i=1;i<=n;i++){
            if(h[i]>0){
                flag=false;
                if(t%3==0)
                    h[i]-=3;
                else
                    h[i]-=1;
                t++;
            }
        }
        if(flag)
            break;
    }

    cout<<t<<endl;
    return 0;
}