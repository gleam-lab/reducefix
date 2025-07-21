#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(ll i = 1; i < n; i++){
        cin >> b[i];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n);
    ll l = n, r = n - 1;
    bool hasConflict = false;
    while(l >= 1 && r >= 1){
        // If box size is sufficient for toy size, move to next toy and box
        if(b[r] >= a[l]){
            l--;
            r--;
        } else {
            // If not, we need to buy a larger box, record the size needed and go to next toy
            if(hasConflict){
                // If we already need a box, and now we need another one, it's impossible
                cout << -1;
                return 0;
            }
            hasConflict = true;
            cout << a[l];
            return 0;
        }
    }
    // If we have a conflict with only one toy left and no boxes left to check, return -1
    if(hasConflict){
        cout << -1;
    } else {
        // If all toys fit into the existing boxes, no additional box is needed
        cout << 0;
    }
    return 0;
}