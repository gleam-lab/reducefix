#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    for(int i=0;i<n;i++) {
        ll h;
        cin>>h;
        // Calculate the number of attacks needed without considering the modulo operation
        ans += (h + 2) / 3;
        // Adjust the result based on the remainder after division by 3
        if ((h % 3) == 1) ans -= 1;
        else if ((h % 3) == 2) ans -= 2;
    }
    cout<<ans;
}