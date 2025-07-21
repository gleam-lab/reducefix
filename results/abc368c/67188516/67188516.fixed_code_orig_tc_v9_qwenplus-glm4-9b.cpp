#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long H[N];
    long long T = 0;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // For each enemy, calculate the full attacks of 3 damage
        T += H[i] / 3;
        // If there is any remaining health after these full attacks, we need additional 1 damage attacks
        T += H[i] % 3;
    }

    cout << T << endl;
    return 0;
}