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
    rep(i, n) {
        if (i + 1 < n && data[i + 1] > data[i]) {
            sum += data[i + 1] * 2;
            i++;
        } else {
            sum += data[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}