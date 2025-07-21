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

    // The largest toy should fit in the largest available box
    if (a.back() > b.back()) {
        cout << -1 << endl;
        return;
    }

    // We need to check if we can place all toys using the existing boxes and one additional box of size a[N-1]
    int i = 0, j = 0;
    while (i < N && j < N - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }

    if (i == N) { // If all toys are placed
        cout << a[N - 1] << endl;
    } else { // If some toys cannot be placed with existing boxes, use an additional box of size a[N-1]
        cout << a[N - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}