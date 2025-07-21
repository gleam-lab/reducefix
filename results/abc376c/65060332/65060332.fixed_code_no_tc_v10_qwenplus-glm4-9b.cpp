#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n-1;i++) cin>>b[i];
    
    // Initialize both pointers at the end of the arrays
    ll l = n-1, r = n-1;
    ll min_size = LLONG_MAX; // To store the minimum possible box size
    
    // Iterate from the end of the arrays
    while(l >= 0 && r >= 0){
        // If the current toy cannot be placed in the current box
        // Check if we can place it in the next box
        if(a[l] < b[r] && r > 0){
            r--; // If the previous box can hold the toy, use it
        }
        // If the toy can be placed in the current box
        else{
            min_size = min(min_size, b[r]); // Update the minimum box size
            break; // Toy is placed, no need to continue
        }
        l--; // Move to the next toy
    }
    
    // After the loop, check if we have placed all toys
    if(l < 0){
        // If we have not placed all toys, check if there's any box that can hold the largest toy
        if(min_size > a[0]) cout << -1;
        else cout << min_size;
    } else {
        // If there's still remaining toys, it's impossible to place them
        cout << -1;
    }
    
    return 0;
}