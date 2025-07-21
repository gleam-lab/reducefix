#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n; cin>>n;
    vector<ll> h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    
    ll t = 0;
    while(true){
        bool done = true;
        for(int i=1;i<=n;i++){
            if(h[i]>0){
                done = false;
                if((t+1)%3==0){
                    h[i]-=3;
                } else{
                    h[i]--;
                }
                t++;
            }
        }
        if(done) break;
    }

    cout<<t<<endl;
    return 0;
}