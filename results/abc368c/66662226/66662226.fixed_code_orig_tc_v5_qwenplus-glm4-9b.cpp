#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }

    long long T = 0;
    for (int i = 0; i < n; i++) {
        // Calculate the minimum moves needed to defeat the current enemy
        if (health[i] % 3 == 0) {
            // If health is a multiple of 3, we need health/3 moves each of which is a multiple of 3
            T += health[i] / 3;
        } else {
            // If health is not a multiple of 3, we need extra moves to make it a multiple of 3
            T += (health[i] / 3) + 1;
        }
    }

    cout << T << endl;
    return 0;
}