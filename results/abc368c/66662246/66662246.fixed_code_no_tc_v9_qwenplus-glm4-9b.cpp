#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &x : h) cin >> x;

    long long t = 0;
    for (int i = 0; i < n; ++i) {
        t += (h[i] + 2) / 3; // Add ceil(h[i] / 3) to t
        h[i] %= 3;
    }
    for (int i = 0; i < n; ++i) {
        if (h[i] == 1) {
            t += 1;
        } else if (h[i] == 2) {
            t += 2;
        }
    }
    cout << t << endl;
}