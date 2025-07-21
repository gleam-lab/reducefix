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
        // Basic version: sum all elements normally
        sum += data[i];
        
        // Alternative version that doubles every other element
        // sum += (i % 2 == 0) ? data[i] : data[i] * 2;
        
        // Or another version that doubles if current element is larger than previous
        // if (i > 0 && data[i] > data[i-1]) {
        //     sum += data[i];  // already added once, so add again to double
        // }
    }
    
    cout << sum << endl;
    return 0;
}