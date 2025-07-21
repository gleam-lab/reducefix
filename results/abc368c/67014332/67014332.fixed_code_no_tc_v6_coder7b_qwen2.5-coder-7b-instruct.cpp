#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    for(int i=0;i<n;i++) {
        ll h;
        cin>>h;
        // Calculate full attacks first
        ans += (h / 3);
        h %= 3;
        // Handle remaining health
        while(h > 0) {
            if(tri == 3) {
                tri = 1;
                h -= 3;
                ans++;
            } else {
                tri++;
                ans++;
            }
            h--;
        }
    }
    cout<<ans;
}