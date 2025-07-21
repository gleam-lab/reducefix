#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && data[i + 1] * 2 > data[i] + data[i + 1]) {
            sum += data[i + 1] * 2;
            i++;  // Skip the next element as it's already added in the sum
        } else if (i % 2 == 0) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}