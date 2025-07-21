#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> data(n);
    rep(i, n) cin >> data[i];

    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if((i + 1) % 2 == 0 && i > 0 && data[i - 1] * 2 > data[i]) {
            sum += data[i - 1] * 2;
        } else {
            sum += data[i];
        }
    }

    cout << sum << '\n';
    return 0;
}