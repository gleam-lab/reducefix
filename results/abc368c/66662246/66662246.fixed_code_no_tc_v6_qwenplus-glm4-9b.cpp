#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> healths(n);
    for (int i = 0; i < n; ++i) {
        cin >> healths[i];
    }

    long long T = 0;
    for (int i = 0; i < n; ++i) {
        while (healths[i] > 0) {
            if (T % 3 == 0 && healths[i] >= 3) {
                // If T is a multiple of 3 and enemy health is at least 3, attack with 3
                healths[i] -= 3;
            } else {
                // Otherwise, attack with 1
                healths[i]--;
            }
            T++;
        }
    }
    cout << T << endl;
}