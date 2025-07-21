#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> health(n);
    for(ll i = 0; i < n; ++i) {
        cin >> health[i];
    }
    
    ll time = 0;
    while(true) {
        bool anyAlive = false;
        for(ll i = 0; i < n; ++i) {
            if(health[i] > 0) {
                anyAlive = true;
                break;
            }
        }
        
        if(!anyAlive) break;
        
        for(ll i = 0; i < n; ++i) {
            if(health[i] > 0) {
                time++;
                if(time % 3 == 0) {
                    health[i] -= 3;
                } else {
                    health[i]--;
                }
                
                if(health[i] < 0) health[i] = 0;
                break;
            }
        }
    }
    
    cout << time << '\n';
    return 0;
}