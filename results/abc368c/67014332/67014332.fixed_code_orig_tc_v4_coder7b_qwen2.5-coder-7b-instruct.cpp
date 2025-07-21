#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for(ll i=0; i<n; i++)
        cin >> h[i];
    
    ll t=0;
    for(ll i=0; i<n; i++){
        if(h[i] > 0){
            if((t+1)%3 == 0)
                h[i] -= 3;
            else
                h[i]--;
            
            if(h[i] > 0){
                t++;
                i--;
            }
        }
    }

    cout << t;
}