#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        int health = H[i];
        // Calculate the number of full attacks (T increments) needed to bring the enemy's health to 0 or less
        T += (health + 2) / 3; // Each full set of 3 attacks reduces the enemy's health by 3
        // If there's a remainder of 1 or 2 health after the full attacks, we need additional attacks
        if (health % 3 == 2) {
            T++; // One more attack needed if there's a remainder of 2
        }
        // If the health can exactly be reduced to zero with one strike, we increment T by 1
    }
    cout << T << endl;
    return 0;
}