#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        if ((data[i + 1] * 2 > data[i] + data[i + 1]) && (i % 2 == 0)) {
            sum += data[i + 1] * 2;
            ++i; // Skip the next element as it's already considered
        } else if (i % 2 == 0) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }

    // Add the last element if it exists and not already counted
    if (n % 2 != 0) {
        sum += data[n - 1];
    }

    cout << sum << endl;
    return 0;
}