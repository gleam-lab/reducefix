#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Calculate the maximum possible value for x
    ll max_possible_x = *max_element(a.begin(), a.end()); // Largest toy size
    ll min_needed_x = *max_element(b.begin(), b.end()); // Largest box size we have

    // Check if any toy cannot fit in any box
    for (ll i = 0; i < n; i++) {
        bool can_place = false;
        for (ll j = 0; j < n - 1; j++) {
            if (b[j] >= a[i]) {
                can_place = true;
                break;
            }
        }
        if (!can_place) {
            cout << -1;
            return 0;
        }
    }

    // If all toys can fit in the given boxes, the minimum x needed is the largest box size we have
    cout << min_needed_x;
    return 0;
}