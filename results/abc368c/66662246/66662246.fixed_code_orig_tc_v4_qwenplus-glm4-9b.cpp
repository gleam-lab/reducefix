#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }

    long long T = 0;
    int i = 0;

    // Process each enemy
    while (i < n) {
        int current = health[i];
        if (current % 3 == 0) {
            // If health is a multiple of 3, calculate how many full attacks can be made
            T += (current / 3) * 3;
            health[i] = current - (current / 3) * 3;
        }
        // Increase T for the attack, if health > 0
        T++;
        health[i] -= 1;
        if (health[i] <= 0) {
            // Move to the next enemy if current one is dead
            i++;
        }
    }

    cout << T << endl;
    return 0;
}