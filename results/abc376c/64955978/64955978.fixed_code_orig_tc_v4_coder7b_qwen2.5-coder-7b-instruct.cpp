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
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N - 1; ++i) cin >> b[i];

    // Sort toys and boxes in descending order
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    int j = 0; // Index for boxes
    bool found = true;
    ll ans = INT_MAX;

    for (int i = 0; i < N; ++i) {
        while (j < N - 1 && a[i] > b[j]) {
            ++j; // Find a suitable box
        }

        if (j == N - 1 && a[i] > b[j]) {
            found = false;
            break;
        }

        ans = min(ans, b[j]);
        ++j; // Move to the next box
    }

    if (!found) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}