#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<long long> toys(N), boxes(N - 1);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> toys[i];
    for (int i = 0; i < N - 1; i++) cin >> boxes[i];

    // Sort both arrays in descending order to find the minimum possible `x`
    sort(toys.begin(), toys.end(), greater<long long>());
    sort(boxes.begin(), boxes.end(), greater<long long>());

    long long smallest_x = 0;
    for (int i = 0; i < N - 1; i++) {
        // If the current box cannot contain all remaining toys, increment `x`
        if (boxes[i] < toys[i + 1]) {
            smallest_x = toys[i + 1];
            break;
        }
    }

    cout << smallest_x << endl;
    return 0;
}