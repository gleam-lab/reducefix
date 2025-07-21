#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];
int main(){
    ll n, min_x = LLONG_MAX;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n - 1; i++){
        cin >> b[i];
    }

    // Sort the toy sizes and box sizes
    sort(a, a + n);
    sort(b, b + n - 1);

    // Start with the largest box size which can fit the smallest toy
    ll box_size = a[0];
    bool can_fit_all = true;
    ll last_box_size = 0;

    // Iterate over the toy sizes
    for(ll i = 0; i < n; i++){
        // If the current toy can't fit in the current box size
        if(a[i] > box_size){
            // Check if the next box size can fit the toy
            if(i < n - 1 && b[i] >= a[i] && b[i] > last_box_size){
                last_box_size = b[i];
                box_size = b[i];
            } else {
                // If there's no suitable box size, print -1
                can_fit_all = false;
                break;
            }
        }
    }

    // If all toys can be placed in boxes, print the minimum box size
    if(can_fit_all){
        cout << box_size;
    } else {
        cout << -1;
    }

    return 0;
}