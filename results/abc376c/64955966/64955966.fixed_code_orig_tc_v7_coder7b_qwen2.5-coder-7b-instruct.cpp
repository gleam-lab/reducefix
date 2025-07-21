#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define sp ' ';
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N - 1; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a[0] > b.back()) {
        cout << "-1\n";
        return;
    }

    ll i = 0, j = 0;
    while (i < N && j < N - 1) {
        if (a[i] <= b[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (i == N) {
        cout << b[j] << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}