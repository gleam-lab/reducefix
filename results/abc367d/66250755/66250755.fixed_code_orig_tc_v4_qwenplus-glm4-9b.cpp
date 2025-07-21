#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[2 * n + 1]; // Array size should be 2n+1 to handle a[n] without index out of bounds
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i]; // Copy values to the next n elements
    }

    // Initialize t array to count occurrences
    int t[m + 1] = {0};
    int an = 0;

    // Calculate the number of times each element appears
    for (int i = 1; i <= 2 * n; i++) {
        t[a[i]]++;
    }

    // Calculate the result based on the pattern of counts
    for (int i = 1; i <= m; i++) {
        an += t[i] * t[i] - t[i] * (i % m); // This might be the intended formula to calculate 'an'
    }

    cout << an << endl;
    return 0;
}