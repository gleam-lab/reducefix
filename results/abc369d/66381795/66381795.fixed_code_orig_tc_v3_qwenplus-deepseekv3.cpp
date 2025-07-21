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
        if (i + 1 < n && data[i] + data[i+1] < 2 * data[i+1]) {
            sum += 2 * data[i+1];
            i += 2;
        } else {
            sum += data[i];
            i += 1;
        }
    }
    
    cout << sum << endl;
    return 0;
}