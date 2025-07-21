#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, smallest_box = LLONG_MAX, found = 0;

    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // First, attempt to fit all toys into existing boxes
    for (ll i = 0; i < n; i++) {
        bool can_fit = false;
        for (ll j = 0; j < n - 1; j++) {
            if (a[i] <= b[j]) {
                can_fit = true;
                break;
            }
        }
        // If a toy cannot fit into any existing box, it will need a new box
        if (!can_fit) {
            smallest_box = min(smallest_box, a[i]);
            found = 1;
        }
    }

    // If at least one toy needs a new box, we need to find the smallest box that can contain all toys
    if (found) {
        for (ll i = 0; i < n - 1; i++) {
            if (smallest_box <= b[i] && b[i] < smallest_box) {
                smallest_box = b[i];
            }
        }
        // If the smallest_box still equals the initial value, it means there's no smaller box that can fit all toys
        if (smallest_box == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << smallest_box << endl;
        }
    } else {
        // If no toy needs a new box, the smallest box we need is the size of the largest toy
        cout << a[n - 1] << endl;
    }

    return 0;
}