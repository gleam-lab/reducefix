#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200100;
int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    // We need to find the smallest box size x such that we can fit all toys in boxes of size x or greater.
    // We will check from the largest possible toy size which is a[n] and go downwards.
    int x = a[n];
    while (x > 0) {
        bool valid = true;
        for (int i = 1; i < n; ++i) {
            if (b[i] < x) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << x;
            return 0;
        }
        x--;
    }

    cout << -1;
    return 0;
}