#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll T = 0;
    ll tri = 0; // count of attacks since last triple attack
    
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        
        while(h > 0) {
            T++;
            tri++;
            
            if(tri == 3) {
                h -= 3;
                tri = 0;
            } else {
                h -= 1;
            }
        }
    }
    
    cout << T;
    return 0;
}