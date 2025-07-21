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
        // Basic alternating sum pattern (adjust as needed for actual problem)
        if (i % 2 == 0) {
            sum += data[i];
        } else {
            sum += data[i] * 2;
        }
    }
    
    cout << sum << endl;
    return 0;
}