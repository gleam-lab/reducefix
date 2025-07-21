#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int n;
int main() {
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        // Calculate the next index, considering the possibility of doubling data[i+1]
        int nextIndex = i;
        if (cnt % 2 == 0 && data[i] % 2 == 0 && (i < n - 1)) {
            if (data[i+1] * 2 > data[i] + data[i+1]) {
                nextIndex++; // Move to the next index to double data[i+1]
            }
        }
        
        // Add data[i] to sum, doubled if conditions match
        if (cnt % 2 == 0 && data[i] % 2 == 0) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
        
        // Move to the next index
        i = nextIndex;
    }
    
    cout << sum << endl;
    return 0;
}