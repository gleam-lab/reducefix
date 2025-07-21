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

    bool canStore = true;
    ll minBoxSize = -1;

    for (int i = 0; i < N - 1; i++) {
        if (a[i] <= b[i]) {
            continue;
        } else {
            canStore = false;
            break;
        }
    }

    if (!canStore) {
        cout << -1 << endl;
        return;
    }

    // The minimum box size required should be at least the largest toy size
    minBoxSize = *max_element(a.begin(), a.end());

    cout << minBoxSize << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}