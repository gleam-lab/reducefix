#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    long long T = 0;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // Calculate the number of full 3-hit cycles needed
        T += H[i] / 3;
        // Calculate the remaining health after full 3-hit cycles
        H[i] %= 3;

        // Now, H[i] is either 0, 1, or 2. We need to handle these cases:
        // If H[i] is 0, no additional hits are needed.
        // If H[i] is 1, we need one more hit.
        // If H[i] is 2, we need two more hits, which can be covered by one additional cycle.
        if (H[i] == 1) {
            T += 1; // Need one more hit.
        } else if (H[i] == 2) {
            T += 1; // Need one more hit to bring it to 1.
            T += 1; // Now it's 1, so we need one more hit to bring it to 0.
        }
    }

    cout << T << endl;

    return 0;
}