#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    // Sort both arrays to facilitate pairing
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Initialize variables
    ll max_b = *max_element(b.begin(), b.end()); // Find the maximum box size
    ll min_a = *min_element(a.begin(), a.end()); // Find the minimum toy size
    
    // If the largest box is smaller than the smallest toy, it's impossible to fit any toy
    if (max_b < min_a) {
        cout << -1 << endl;
        return;
    }
    
    // The answer will be the size of the smallest box that can hold the largest toy
    ll ans = ceil((double)a.back() / b.size()); // Calculate the minimum box size needed
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}