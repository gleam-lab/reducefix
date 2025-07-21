#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    for(ll i=1; i<n; i++){
        cin >> b[i];
    }
    // First, sort the toy sizes and the box sizes
    sort(a+1, a+n+1);
    sort(b+1, b+n);
    
    // We use a two-pointer technique to find the minimum x
    ll l = 1, r = n;
    while(l < r){
        // If the current toy and box sizes do not match, we need to adjust the pointers
        if(a[l] < b[r] || a[r] > b[l]){
            if(a[l] < b[r]){
                // If the current toy is too small for the box, move the box pointer to the left
                r--;
            } else {
                // If the current toy is too large for the box, move the toy pointer to the right
                l++;
            }
        } else {
            // If the current toy and box sizes match, check the adjacent sizes
            if(l + 1 < n && r - 1 >= 0 && a[l + 1] <= b[r - 1] && a[r] >= b[l + 1]){
                // If the next box is not larger than the next toy, we can use this box size
                break;
            }
            // Otherwise, adjust the pointers
            if(a[l] < b[r - 1] || a[r] > b[l + 1]){
                if(a[l] < b[r - 1]){
                    r--;
                } else {
                    l++;
                }
            } else {
                // If the current toy and box sizes are in a valid range but next ones are not, we can use the current size
                break;
            }
        }
    }
    
    // If we find a valid size, we increment it to get the minimum x we can use
    if(l < r){
        cout << a[l] + 1;
    } else {
        // If no valid size is found, we output -1
        cout << -1;
    }
    return 0;
}