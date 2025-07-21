#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> b[i];
    }

    // Sort the toy sizes in descending order
    sort(a.begin(), a.end(), greater<int>());

    // Iterate over the box sizes from the end to the start
    for (int i = N - 1; i >= 0; --i) {
        // If the current box size can accommodate the largest toy, then this is the minimum x
        if (a[0] <= b[i]) {
            cout << b[i] << endl;
            return 0;
        }
    }

    // If no box can fit the largest toy, then it's impossible to store all toys
    cout << -1 << endl;

    return 0;
}