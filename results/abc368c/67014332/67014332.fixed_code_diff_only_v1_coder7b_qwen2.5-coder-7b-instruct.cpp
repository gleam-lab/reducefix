#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans=0;
    cin>>n;
    vector<ll> h(n);
    for(int i=0;i<n;i++)
        cin>>h[i];
    
    for(auto &x: h){
        // Calculate full attacks that can be done
        ans += x / 3;
        x %= 3;
        
        // Handle remaining health
        if(x > 0)
            ++ans;
    }
    
    cout << ans << endl;
    return 0;
}