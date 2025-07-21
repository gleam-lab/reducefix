#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n;
int main() {
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }
    ll sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i += 2) {
        sum += data[i + 1] * 2;
        sum += data[i];  // Since cnt%2 == 0, add data[i] as well
    }
    cout << sum << endl;
    return 0;
}