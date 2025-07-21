#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
ll N;
cin>>N;
vector<ll> a(N), b(N-1);
for(ll i=0;i<N;i++) cin>>a[i];
for(ll i=0;i<N-1;i++) cin>>b[i];

// Sort both arrays
sort(a.begin(), a.end());
sort(b.begin(), b.end());

// Initialize variables
ll ans = INT_MAX;
ll j = 0;

// Iterate through toys
for(ll i=0;i<N;i++){
    // Find the smallest box that can fit the current toy
    while(j < N-1 && b[j] < a[i]) j++;
    
    // If no suitable box is found, break
    if(j == N-1) {
        ans = -1;
        break;
    }
    
    // Update the answer with the maximum size encountered
    ans = min(ans, b[j]);
    
    // Move to the next box for the next toy
    j++;
}

// Output the result
if(ans != INT_MAX) cout << ans << endl;
else cout << "-1" << endl;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

solve();

return 0;
}