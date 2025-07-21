#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];

bool check(ll mid, int n){
    vector<int> box(mid + 1, 0); // Initialize a vector with size mid+1 to represent the boxes
    for(int i = 1; i <= n; ++i){
        bool placed = false;
        for(int j = mid; j >= 1; --j){
            if(j >= a[i] && box[j] == 0){ // Check if the current box size can accommodate the toy and if the box is empty
                box[j] = 1; // Place the toy in the box
                placed = true;
                break;
            }
        }
        if(!placed) return false; // If the toy cannot be placed in any box, return false
    }
    return true; // All toys can be placed successfully
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = 1e9;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid, n)){
            r = mid; // Try to minimize the box size
        } else {
            l = mid + 1; // Increase the box size
        }
    }
    if(l > 1e9) cout << -1; // If no valid box size found, output -1
    else cout << l;
    return 0;
}