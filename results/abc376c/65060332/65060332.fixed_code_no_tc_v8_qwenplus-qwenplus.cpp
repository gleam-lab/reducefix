#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n), b(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // We need to assign toys to boxes such that:
    // - Each toy goes into a box of size >= its size
    // - One toy can go to the new box of size x
    // - Goal: find minimum x that allows this

    // Try greedy matching and see which toy must go to the new box

    int j = 0;
    ll required_x = -1;

    for (int i = 0; i < n; ++i) {
        if (j < n - 1 && b[j] >= a[i]) {
            j++;
        } else {
            // This toy must go to the new box
            if (required_x != -1) {
                // More than one toy cannot be placed in new box => impossible
                cout << -1 << endl;
                return 0;
            }
            required_x = a[i];
        }
    }

    cout << required_x << endl;
    return 0;
}