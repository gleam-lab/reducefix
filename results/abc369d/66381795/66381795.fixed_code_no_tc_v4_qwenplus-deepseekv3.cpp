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
        // If we have at least one more element and the next element is more than double the current
        if (i + 1 < n && data[i+1] > 2 * data[i]) {
            sum += data[i+1];
            i++; // skip the next element since we added it
        } else {
            sum += data[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}