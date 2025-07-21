#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }

    // Sort toys and boxes in descending order
    sort(a + 1, a + n + 1, greater<ll>());
    sort(b + 1, b + n, greater<ll>());

    ll required = -1;
    int j = 1;

    // Try to fit the toys into the boxes
    for (int i = 1; i <= n; ++i) {
        if (j < n && b[j] >= a[i]) {
            ++j;
        } else {
            // This toy cannot fit in any available box, needs our custom box
            if (required == -1) {
                required = a[i];
            } else {
                // If we already have one that doesn't fit, then it's impossible
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << required << '\n';
    return 0;
}