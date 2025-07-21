#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(h[i]%3==0) ans+=(h[i]/3);
        else ans+=(h[i]/3+1);
    }
    
    cout<<ans<<endl;
    return 0;
}