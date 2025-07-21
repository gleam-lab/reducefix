#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    long long T = 0;
    long long totalT = 0;  // Total T needed to defeat all enemies

    for (int i = 0; i < N; ++i) {
        // Calculate how many full sets of 3 can be used on this enemy
        long long fullSets = H[i] / 3;
        // Calculate the leftover health after full sets of 3 are used
        long long leftover = H[i] % 3;

        // Add the number of attacks needed for full sets of 3
        T += fullSets;
        // Add one additional attack for the leftover health
        T++;

        // Add the minimum number of attacks to the totalT
        totalT += T;
    }

    // Since we might have overcounted in T and we need the minimum attacks,
    // we subtract 1 if the totalT is odd, because we want the smallest even T
    if (totalT % 2 != 0) totalT -= 1;

    cout << totalT << endl;

    return 0;
}