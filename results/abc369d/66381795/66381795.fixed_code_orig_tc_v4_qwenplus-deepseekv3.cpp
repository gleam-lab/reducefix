#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }
    ll sum = 0;
    int i = 0;
    while (i < n) {
        if (i + 1 < n && data[i + 1] * 2 > data[i] + data[i + 1]) {
            sum += data[i + 1] * 2;
            i += 2;
        } else {
            sum += data[i];
            i += 1;
        }
    }
    cout << sum << endl;
    return 0;
}