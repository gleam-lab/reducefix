#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, cnt = 0, min_possible_size = LLONG_MAX, last_a = -1;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (last_a == -1 || a[i] < last_a) {
            last_a = a[i];
            min_possible_size = min(min_possible_size, last_a);
        }
    }

    for (ll i = 1; i < n; i++) {
        cin >> b[i];
        if (min_possible_size > b[i]) {
            min_possible_size = b[i];
        }
    }

    if (min_possible_size == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_possible_size << endl;
    }

    return 0;
}