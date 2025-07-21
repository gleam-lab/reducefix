#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
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

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool found = false;
    ll x = -1;
    for (ll i = 0; i <= N - 2; i++) {
        if (a[i] > b[i]) {
            continue;
        } else {
            found = true;
            x = max(x, a[i]);
            break;
        }
    }

    if (!found && a[N - 1] > b[N - 2]) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}