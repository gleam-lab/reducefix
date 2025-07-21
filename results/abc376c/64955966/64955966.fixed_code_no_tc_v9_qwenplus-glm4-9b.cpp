#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    ll a[N], b[N-1];
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    // Sort toy sizes in descending order
    sort(a, a + N, greater<ll>());
    // Sort box sizes in descending order
    sort(b, b + N - 1, greater<ll>());

    // Initialize variables to find the minimum box size x
    ll min_x = LLONG_MAX;
    bool is_possible = true;

    // Iterate over each toy and try to fit it into a box
    for(ll i = 0; i < N; i++) {
        // If current toy cannot fit into any box, then it's not possible to fit all toys
        if(a[i] > b[i]) {
            is_possible = false;
            break;
        }
        // Otherwise, continue to the next toy
    }

    // If it's possible to fit all toys into the given boxes, no new box size is needed
    if(is_possible) {
        cout << 0 << endl;
    } else {
        // If not possible, find the smallest box size x that can be added
        for(ll i = 0; i < N - 1; i++) {
            if(a[i] > b[i]) {
                min_x = min(min_x, b[i] + 1);
                break;
            }
        }
        // If all toys can be placed in the existing boxes, no new box is needed
        if(min_x == LLONG_MAX) {
            cout << 0 << endl;
        } else {
            cout << min_x << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}