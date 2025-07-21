#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canFit(ll mid, vector<ll>& toys, vector<ll>& boxes) {
    int n = toys.size();
    int b = 0; // Index for boxes array
    for(int i = 0; i < n; ++i) {
        while(b < n - 1 && boxes[b] < toys[i]) {
            ++b;
        }
        if(b >= n - 1) return false;
        if(boxes[b] < toys[i]) return false;
        ++b;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> toys(n), boxes(n - 1);
    for(ll i = 0; i < n; ++i) cin >> toys[i];
    for(ll i = 0; i < n - 1; ++i) cin >> boxes[i];

    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    ll low = 0, high = 1e9 + 7, ans = -1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(canFit(mid, toys, boxes)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}