#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n;
vector<int> data;

int main() {
    cin >> n;
    data.resize(n);
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    rep(i, n - 1) { // Iterate up to n-1 to avoid out-of-bounds access
        if ((data[i] + data[i + 1]) % 2 == 0) {
            sum += max(data[i], data[i + 1]);
        } else {
            sum += min(data[i], data[i + 1]);
        }
    }

    if (n > 0) { // Check if there is at least one element left after the loop
        sum += data[n - 1]; // Add the last element since it's not included in the loop
    }

    cout << sum << endl;
    return 0;
}