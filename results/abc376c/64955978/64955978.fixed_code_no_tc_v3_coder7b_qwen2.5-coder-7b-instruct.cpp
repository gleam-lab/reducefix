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

    // Check if the largest toy can fit in the largest available box
    if (a[N - 1] > b[N - 2]) {
        cout << -1 << endl;
        return;
    }

    // Find the minimum size of the box needed to store the largest toy
    for (ll x = a[N - 1]; x <= b[N - 2]; x++) {
        bool valid = true;
        int j = 0;
        for (int i = 0; i < N && valid; i++) {
            while (j < N - 1 && b[j] < a[i]) {
                j++;
            }
            if (j >= N - 1 || b[j] < a[i]) {
                valid = false;
            } else {
                j++;
            }
        }
        if (valid) {
            cout << x << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}