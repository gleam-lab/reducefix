#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < N - 1; i++) {
        cin >> b[i];
    }

    sort(a.rbegin(), a.rend()); // Sort toy sizes in descending order
    sort(b.rbegin(), b.rend()); // Sort box sizes in descending order

    // Try to place each toy in a box
    ll x = 0; // x is the smallest box size that can store all toys
    for (ll i = 0; i < N; i++) {
        if (a[i] > b[x]) { // If the current toy cannot fit in the current box
            x++; // We need a larger box
            if (x >= N - 1) { // If there are no more boxes to try
                cout << -1 << endl; // It's impossible to place this toy
                return 0;
            }
        }
    }

    cout << a[N - 1] << endl; // The size of the smallest box that can store all toys
    return 0;
}