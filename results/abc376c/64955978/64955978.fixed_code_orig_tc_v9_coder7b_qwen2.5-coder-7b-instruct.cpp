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

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Check if we can place all toys in the available boxes
    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (j >= N - 1 || a[i] > b[j]) {
            cout << "-1\n";
            return;
        }
        while (j < N - 1 && a[i] <= b[j]) {
            ++j;
        }
    }

    // Find the smallest box size needed
    ll minBoxSize = *max_element(a.begin(), a.end());
    for (; j < N - 1; ++j) {
        if (b[j] >= minBoxSize) {
            break;
        }
        minBoxSize = b[j];
    }

    cout << minBoxSize << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}