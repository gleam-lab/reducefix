#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n - 1);

    // We need to assign toys to boxes such that each toy fits in its box
    // One of the boxes can be replaced with our chosen box
    // We want to minimize the size of this extra box

    // We try to match largest toys with largest available boxes first
    // If we cannot fit a toy in a box without our custom box, we must use it

    int j = n - 2; // pointer to the largest unused box
    int required = 0;
    ll needed_size = 0;

    // Try to place toys from largest to smallest
    for (int i = n - 1; i >= 0; --i) {
        if (j >= 0 && b[j] >= a[i]) {
            // We can use one of the given boxes
            j--;
        } else {
            // We need to use our purchased box for this toy
            required++;
            needed_size = max(needed_size, a[i]);
        }
    }

    // We can only use one purchased box
    if (required > 1) {
        cout << -1 << '\n';
    } else {
        cout << needed_size << '\n';
    }

    return 0;
}