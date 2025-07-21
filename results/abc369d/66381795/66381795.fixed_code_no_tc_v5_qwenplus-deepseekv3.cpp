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
    int cnt = 0;
    rep(i, n) {
        if (i + 1 < n) {  // Check to avoid out-of-bounds access
            if (data[i+1] * 2 > data[i] + data[i+1] && cnt % 2 == 0) {
                sum += data[i+1] * 2;
                i++;  // Skip next element
                cnt++;
            } else if (cnt % 2 == 0) {
                sum += data[i] * 2;
            } else {
                sum += data[i];
            }
        } else {
            // Handle last element when n is odd
            sum += data[i];
        }
        cnt++;
    }
    
    cout << sum << endl;
    return 0;
}