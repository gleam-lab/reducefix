#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];

// Function to check if a given box size x can accommodate all toys
bool canFitAll(ll x, vector<ll>& toys, vector<ll>& boxes) {
    int n = toys.size();
    for(int i = 0; i < n; ++i) {
        if(toys[i] > x) return false;
        if(i == n - 1 || boxes[i] >= toys[i]) continue;
        // If the current box cannot hold the current toy, check the next box
        if(i + 1 < n && boxes[i + 1] >= toys[i]) continue;
        // If we don't have enough space in subsequent boxes, return false
        return false;
    }
    return true;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n-1; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Binary search to find the minimum box size x
    ll left = *max_element(a.begin(), a.end()), right = 1e9;
    while(left <= right) {
        ll mid = left + (right - left) / 2;
        if(canFitAll(mid, a, b)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}