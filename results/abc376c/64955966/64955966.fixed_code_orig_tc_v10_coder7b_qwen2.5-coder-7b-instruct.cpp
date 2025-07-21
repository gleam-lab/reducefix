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
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> b[i];
    }

    // Sort toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize pointer for boxes
    int box_ptr = 0;

    // Iterate through each toy
    for (int i = 0; i < N; ++i) {
        // Find a suitable box for the current toy
        while (box_ptr < N - 1 && a[i] > b[box_ptr]) {
            ++box_ptr;
        }

        // If no suitable box is found
        if (box_ptr == N - 1 && a[i] > b[box_ptr]) {
            cout << -1 << endl;
            return;
        }

        // Move to the next box
        ++box_ptr;
    }

    // If all toys fit, print the smallest box size needed
    cout << b[N - 2] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}