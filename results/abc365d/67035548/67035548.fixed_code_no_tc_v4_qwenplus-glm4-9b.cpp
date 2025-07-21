#include <iostream> // cin, cout
#include <string> // string
#include <vector> // vector

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> left(n), right(n);
    left[0] = 1;
    int maxLeft = 1;

    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'R' && s[i] == 'P') {
            left[i] = 1;
        } else if (s[i - 1] == 'P' && s[i] == 'R') {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 0;
        }
        maxLeft = max(maxLeft, left[i]);
    }

    right[n - 1] = 1;
    int maxRight = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (s[i + 1] == 'R' && s[i] == 'P') {
            right[i] = 1;
        } else if (s[i + 1] == 'P' && s[i] == 'R') {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 0;
        }
        maxRight = max(maxRight, right[i]);
    }

    cout << max(maxLeft, maxRight) << endl;

    return 0;
}