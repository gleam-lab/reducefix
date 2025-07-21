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
    int even_cnt = 0, odd_cnt = 0;
    rep(i, n) {
        if (i == n - 1 || data[i + 1] * 2 <= data[i] + data[i + 1]) {
            // If it's the last element or the condition is not met, add the current element once
            sum += data[i];
            if (i % 2 == 0) {
                even_cnt++;
            } else {
                odd_cnt++;
            }
        } else {
            // If the condition is met, double the current element
            sum += 2 * data[i];
            if (i % 2 == 0) {
                even_cnt++;
            } else {
                odd_cnt++;
            }
        }
    }
    
    // Add the sum of doubled elements only if the count of doubled elements is even
    sum += even_cnt / 2;
    
    cout << sum << endl;
    return 0;
}