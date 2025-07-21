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

    sort(a, a + n);
    sort(b, b + n - 1);

    ll maxToyThatCouldNotFit = -1;
    for (ll i = 0, j = 0; i < n; ++i) {
        // Find the next box that can fit the current toy a[i]
        while (j < n - 1 && b[j] < a[i])
            ++j;

        // If we have run out of boxes, the current toy a[i] is the largest toy
        // that could not fit in any box, so set maxToyThatCouldNotFit to a[i]
        if (j == n - 1) {
            maxToyThatCouldNotFit = max(maxToyThatCouldNotFit, a[i]);
        }
    }

    // If there was a toy that could not fit in any box, print its size as the answer
    // Otherwise, print -1
    cout << (maxToyThatCouldNotFit == -1 ? -1 : maxToyThatCouldNotFit);
    return 0;
}