#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll>& h) {
    ll t = 0;
    while(true){
        bool done = true;
        for(int i=0;i<h.size();i++){
            if(h[i]>0){
                done=false;
                if(t%3==0) h[i]-=3;
                else h[i]--;
                t++;
            }
        }
        if(done) break;
    }
    return t;
}

int main(){
    int n;
    cin>>n;
    vector<ll> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<solve(h)<<endl;
    return 0;
}