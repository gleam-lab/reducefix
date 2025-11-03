#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    int idx = 0; // current enemy index

    while (idx < N) {
        T++;
        // Attack the frontmost enemy with health > 0
        if (H[idx] <= 0) {
            idx++;
            continue;
        }

        if (T % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx] -= 1;
        }

        // If this enemy's health drops to 0 or below, move to next
        if (H[idx] <= 0) {
            idx++;
        }
    }

    cout << T << endl;
    return 0;
}