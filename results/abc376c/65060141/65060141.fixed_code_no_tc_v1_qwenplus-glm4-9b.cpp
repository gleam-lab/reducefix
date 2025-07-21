#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];

    // Sort the toy sizes and box sizes
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    // Variables to track the number of toys that need a new box
    ll cnt = 0;

    // Iterate from the largest toy size to the smallest
    for (ll i = n; i >= 1; --i) {
        if (b[i - 1] >= a[i]) {
            // If the current box can accommodate the current toy, continue
            continue;
        } else {
            // If the current box cannot accommodate the current toy, increment the count
            cnt++;
        }
    }

    // If there are more than one toy that needs a new box, output -1
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        // If there is exactly one toy that needs a new box, the size of the new box is the size of that toy
        if (cnt == 1) {
            cout << a[n] << endl;
        } else {
            // If no toy needs a new box, find the smallest box size that can accommodate the largest toy
            for (ll i = 0; i < n - 1; ++i) {
                if (a[n] <= b[i]) {
                    cout << b[i] << endl;
                    break;
                }
            }
        }
    }

    return 0;
}