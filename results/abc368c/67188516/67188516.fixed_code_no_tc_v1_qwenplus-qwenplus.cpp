#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    long long T = 0;
    // We simulate the process using a queue to manage attacks
    // For each enemy, we will track how many times we've attacked it

    // We can use a queue to track which attacks land on multiples of 3
    // Each time T increases by 1, we attack the first enemy with health > 0
    // If T is a multiple of 3, deal 3 damage, else deal 1 damage

    // To optimize, we maintain a queue of enemies with their current health
    // and simulate until all are dead

    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}