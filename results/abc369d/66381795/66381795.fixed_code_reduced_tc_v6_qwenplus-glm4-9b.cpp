#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
int main() {
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    int cnt = 0;
    long long sum = 0;
    rep(i, n) {
        cnt++;
        if (i + 1 < n && data[i + 1] * 2 > data[i] + data[i + 1] && cnt % 2 == 0) {
            sum += data[i + 1] * 2;
            i++; // Skip the next index as it's already considered
        } else if (cnt % 2 == 0) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }
    cout << sum << endl;
    return 0;
}