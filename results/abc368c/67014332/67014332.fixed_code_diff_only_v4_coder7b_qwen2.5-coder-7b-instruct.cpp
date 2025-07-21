#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    for(int i=0;i<n;i++) {
        ll h;
        cin>>h;
        // Each time we encounter an enemy, we need to subtract its health
        // Since the health can be large, we use modulo operation
        while(h > 0){
            if(tri == 3){
                tri = 1;
                ans += (h >= 3)? 3 : h; // Subtract minimum of 3 or remaining health
                h -= (h >= 3)? 3 : h; 
            } else {
                tri++;
                ans++; // Increment the counter
                h--; // Decrease the health
            }
        }
    }
    cout<<ans;
}