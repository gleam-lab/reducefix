#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long H[N];
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    long long health_left = 0;

    // Iterate over the enemies
    for (int i = 0; i < N; ++i) {
        // Calculate the remaining health after dealing 3 damage as many times as possible
        health_left = H[i] % 3;
        // Each time T is a multiple of 3, we deal 3 damage, so we add (H[i] / 3) to T
        T += H[i] / 3;
    }

    // For any remaining health that is not a multiple of 3, we need to deal damage without increasing T by a multiple of 3
    // Since we have already dealt as much damage as possible in multiples of 3, we just add the remaining health
    T += health_left;

    cout << T << endl;
    return 0;
}