#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Sort toy sizes and box sizes
    sort(a, a + n);
    sort(b, b + n - 1);

    // We need to find the maximum sum of sizes of toys that can fit into a box
    // Let's find the maximum size of the box that can contain the largest toy
    ll max_box_size = 0;
    ll required_sum = 0;
    ll i = n - 1;
    ll j = n - 2;

    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            required_sum += a[i];
            i--;
        } else {
            max_box_size = max(max_box_size, required_sum);
            required_sum += a[i];
            i--;
        }
        j--;
    }

    // If there are toys left unaccounted for, add their size to max_box_size
    while (i >= 0) {
        max_box_size = max(max_box_size, required_sum + a[i]);
        i--;
    }

    // If the last box size in the list is the maximum we found, we can use it directly
    max_box_size = max(max_box_size, b[n-2]);

    // Output the result
    if (max_box_size > 0 && max_box_size <= 1e9) {
        cout << max_box_size << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    solve();
    return 0;
}