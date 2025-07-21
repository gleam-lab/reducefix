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
        if (i + 1 < n) {  // Check if next element exists
            if (data[i+1] > data[i]) {  // Simplified condition
                sum += data[i+1];
                i++;  // Skip next element
            } else {
                sum += data[i];
            }
        } else {
            sum += data[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}