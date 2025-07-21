#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        if (cnt % 2 == 0) {  // Use cnt to determine if we're at an even index
            sum += data[i] * 2;
        } else {  // cnt % 2 == 1
            sum += data[i];
        }
    }
    cout << sum << endl;
    return 0;
}