#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long T = 0;
    bool allZero = false;
    while (!allZero) {
        allZero = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                allZero = false;
                T++;
                if (T % 3 == 0) {
                    a[i] -= 3;
                } else {
                    a[i]--;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}