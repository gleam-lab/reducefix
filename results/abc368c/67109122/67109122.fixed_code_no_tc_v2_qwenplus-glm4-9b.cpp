#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long T = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
        } else if (H[i] % 3 == 1) {
            T += H[i] / 3 + 2; // Since we can't use T % 3 == 0 on this health, we need to increase T by 2 steps
        } else { // H[i] % 3 == 2
            T += H[i] / 3 + 1; // We can use T % 3 == 0 on this health, so increase T by 1 step
        }
        H[i] = 0; // Set health to 0 as the enemy is defeated
    }

    cout << T << endl;
    return 0;
}