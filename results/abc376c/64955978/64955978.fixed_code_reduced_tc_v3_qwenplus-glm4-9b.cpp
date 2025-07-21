#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> toys(N), boxes(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> toys[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> boxes[i];
    }

    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // Iterate from the largest toy to the smallest
    for (int i = N - 1; i >= 0; i--) {
        bool fits = false;
        // Check if current toy fits in any box from the largest to the smallest
        for (int j = N - 2; j >= 0; j--) {
            if (toys[i] <= boxes[j]) {
                fits = true;
                break;
            }
        }
        // If the toy doesn't fit, it's impossible to fit all toys
        if (!fits) {
            cout << -1 << endl;
            return 0;
        }
    }

    // If all toys fit, the size of the last box used will be the minimum required box size
    cout << boxes[0] << endl;

    return 0;
}