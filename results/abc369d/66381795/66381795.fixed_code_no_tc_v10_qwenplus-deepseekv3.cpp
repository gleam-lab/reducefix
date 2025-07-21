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
        if (i % 2 == 1) {  // Every second element (0-based indexing)
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}