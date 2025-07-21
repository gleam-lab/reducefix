#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long healths[N];
    long long T = 0;

    // Read in health values
    for (int i = 0; i < N; ++i) {
        cin >> healths[i];
    }

    // Process each enemy
    for (int i = 0; i < N; ++i) {
        if (healths[i] > 0) {
            // Calculate the minimum number of attacks needed
            long long attacks = (healths[i] + 2) / 3; // ceil(healths[i] / 3)
            T += attacks;
        }
    }

    cout << T << endl;
    return 0;
}