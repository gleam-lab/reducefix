#include <iostream>
#include <vector>
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
        if (i < n - 1) {  // Ensure the next element exists
            if (data[i + 1] * 2 > data[i] + data[i + 1] && (i + 1) % 2 == 0) {
                sum += data[i + 1] * 2;
                i++;  // Increment i to skip the next element as it's already considered
            } else if ((i + 1) % 2 == 0) {
                sum += data[i] * 2;
            } else {
                sum += data[i];
            }
        } else if (!((i + 1) % 2 == 0)) {
            sum += data[i];
        }
    }
    cout << sum << endl;
    return 0;
}