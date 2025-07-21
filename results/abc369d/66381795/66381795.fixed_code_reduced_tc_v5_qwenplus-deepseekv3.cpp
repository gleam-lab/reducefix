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
    for (int i = 0; i < n; ) {
        if (i + 1 < n) {
            if (data[i+1] > data[i]) {
                sum += data[i+1] * 2LL;
                sum += data[i];
            } else {
                sum += data[i] * 2LL;
                sum += data[i+1];
            }
            i += 2;
        } else {
            sum += data[i];
            i += 1;
        }
    }
    
    cout << sum << endl;
    return 0;
}