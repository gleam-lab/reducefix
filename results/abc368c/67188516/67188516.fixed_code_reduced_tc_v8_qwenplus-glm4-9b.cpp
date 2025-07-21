#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long T = 0;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // If the health is divisible by 3, deal 3 points
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
        } else if (H[i] % 3 == 1) {
            // If health is 1 mod 3, reduce it by 1, then 2, then 3 in the next round
            T += H[i] / 3 + 3;
        } else { // H[i] % 3 == 2
            // If health is 2 mod 3, reduce it by 1, then 2 in the next round
            T += H[i] / 3 + 2;
        }
    }

    cout << T << endl;
    return 0;
}