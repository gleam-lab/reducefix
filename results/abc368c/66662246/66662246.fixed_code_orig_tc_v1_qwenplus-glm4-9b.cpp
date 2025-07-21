#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int &h : H) cin >> h;

    long long T = 0; // Total number of attacks
    long long current_health = 0; // Sum of current healths of all enemies
    long long health_dealt = 0; // Total health dealt by the last attack

    for (int i = 0; i < N; ++i) {
        current_health += H[i];
        // Calculate the number of attacks needed to bring the current health to zero or less
        while (current_health > 0) {
            if (T % 3 == 0) {
                // If T is a multiple of 3, deal 3 health points
                health_dealt = 3;
            } else {
                // Otherwise, deal 1 health point
                health_dealt = 1;
            }
            current_health -= health_dealt;
            T++; // Increment the total number of attacks
        }
    }

    cout << T << endl;
    return 0;
}