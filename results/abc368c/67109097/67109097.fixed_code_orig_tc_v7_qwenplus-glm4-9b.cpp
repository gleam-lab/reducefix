#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long totalDamage = 0;

    // Calculate the total damage needed
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        totalDamage += (H[i] + 2) / 3; // Add ceil(H[i] / 3) to totalDamage
    }

    // Find the minimum number of complete cycles of 3 attacks
    long long T = totalDamage / 3;
    if (totalDamage % 3 != 0) T++; // If there's a remainder, we need one more cycle

    cout << T * 3 << endl; // Each cycle of 3 attacks increases T by 3
    return 0;
}