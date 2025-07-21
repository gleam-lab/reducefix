#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    
    // Read health values of enemies
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int attacks = 0;
    while (any_of(H.begin(), H.end(), [](int health) { return health > 0; })) {
        for (int &health : H) {
            if (health > 0) {
                if (attacks % 3 == 0) {
                    health--; // If attacks is a multiple of 3, decrease by 3
                } else {
                    health -= 3; // Otherwise, decrease by 1
                }
            }
        }
        attacks++;
    }

    cout << attacks << endl;
    return 0;
}