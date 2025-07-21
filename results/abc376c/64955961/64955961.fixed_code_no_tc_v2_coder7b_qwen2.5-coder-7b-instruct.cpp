#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
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
    
    // Initialize variables to track the number of boxes needed
    ll maxBoxSize = 0, count = 0;
    
    // Iterate through the sorted arrays to determine the maximum box size required
    for (ll i = n - 1, j = n - 2; i >= 0 && j >= 0;) {
        if (a[i] <= b[j]) {
            i--;
        } else {
            count++;
            maxBoxSize = max(maxBoxSize, a[i]);
            i--;
        }
    }
    
    // If we need more than one additional box, output -1
    if (count > 1) {
        cout << -1 << endl;
    } else {
        // Otherwise, output the size of the largest box needed
        cout << maxBoxSize << endl;
    }
}

int main() {
    solve();
    return 0;
}