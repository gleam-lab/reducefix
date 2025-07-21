#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    ll a[N], b[N-1];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    sort(a, a + N, greater<ll>()); // Sort the toys' sizes in descending order
    sort(b, b + N-1, greater<ll>()); // Sort the boxes' sizes in descending order

    ll min_x = LLONG_MAX; // Initialize the minimum x to a large number
    ll j = 0; // Pointer for the boxes

    // Iterate over each toy
    for (ll i = 0; i < N; i++) {
        // Move the box pointer as long as the current box can't fit the current toy
        while (j < N - 1 && a[i] > b[j]) {
            j++;
        }

        // If the current toy can't fit in any box
        if (a[i] > b[j]) {
            cout << -1 << endl;
            return;
        }

        // Update the minimum x if the current box size is less than the current minimum x
        min_x = min(min_x, b[j]);

        // Remove the used box
        j++;
    }

    cout << min_x << endl; // Output the minimum x
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}