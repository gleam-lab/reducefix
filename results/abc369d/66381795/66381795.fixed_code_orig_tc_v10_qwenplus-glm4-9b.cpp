#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<long long> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    long long sum = 0;
    rep(i, n - 1) {
        // Check if the sum of current and next element is less than twice the next element
        // and we are at an even index to consider doubling the next element
        if (data[i] + data[i + 1] > 2 * data[i + 1] && (i % 2) == 0) {
            sum += 2 * data[i + 1];
            i++; // Skip the next element as it will be included in the next iteration
        } else if ((i % 2) == 0) {
            sum += 2 * data[i]; // If even index, double the current element
        } else {
            sum += data[i]; // If odd index, just add the current element
        }
    }

    // If the last element is at an even index (n % 2 == 0), it should be doubled
    if (n % 2 == 0) {
        sum += 2 * data[n - 1];
    }

    cout << sum << endl;
    return 0;
}