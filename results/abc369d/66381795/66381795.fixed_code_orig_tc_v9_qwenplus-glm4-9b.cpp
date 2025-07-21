#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n, a;
    cin >> n;
    vector<int> data(n);
    rep(i, n) cin >> data[i];

    ll sum = 0;
    rep(i, n) {
        // Check if the current index is even and there is a next element
        if (i % 2 == 0 && i + 1 < n) {
            if (data[i + 1] * 2 > data[i] + data[i + 1]) {
                sum += data[i + 1] * 2;
                i++; // Skip the next element as it's already processed
            } else {
                sum += data[i];
            }
        } else if (i % 2 == 1 || i + 1 >= n) {
            sum += data[i];
        }
    }
    cout << sum << endl;
    return 0;
}