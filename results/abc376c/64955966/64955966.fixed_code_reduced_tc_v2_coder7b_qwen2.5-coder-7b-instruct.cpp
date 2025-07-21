#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }

    // Sort toys and boxes in descending order
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    // Initialize the minimum box size
    ll min_box_size = 0;

    // Iterate through the toys
    for (int i = 0; i < N; i++) {
        bool found = false;
        // Try to place the current toy in the available boxes
        for (int j = 0; j < N - 1; j++) {
            if (!found && a[i] <= b[j]) {
                found = true;
                break;
            }
        }
        // If the toy cannot be placed, we need a larger box
        if (!found) {
            min_box_size = max(min_box_size, a[i]);
        }
    }

    // Check if the last toy fits into the last available box
    if (min_box_size > 0 && a[N - 1] > b[N - 2]) {
        min_box_size = max(min_box_size, a[N - 1]);
    } else if (min_box_size == 0 && a[N - 1] > b[N - 2]) {
        min_box_size = a[N - 1];
    }

    // Print the result
    if (min_box_size == 0) {
        cout << -1 << endl;
    } else {
        cout << min_box_size << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}