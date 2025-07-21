#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int t = 0;
    for (int i = 0; i < n; ++i) {
        // Calculate the remainder of health when divided by 3
        int remainder = h[i] % 3;
        // If remainder is 0, we need to make two moves (one for 1 damage and another for 1 damage)
        if (remainder == 0) {
            t += 2;
        } else if (remainder == 1) {
            // If remainder is 1, we can either make one move for 3 damage or two moves for 1 damage
            // We prefer to make one move for 3 damage if the current move count is not a multiple of 3
            // because then we won't need to make an extra move to make the move count a multiple of 3
            if (t % 3 != 0) {
                t++;
                h[i] -= 3;
            } else {
                t += 2;
            }
        } else { // remainder == 2
            // If remainder is 2, we can make one move for 3 damage or two moves for 1 damage
            // We prefer to make one move for 3 damage if possible
            if (h[i] >= 3) {
                t++;
                h[i] -= 3;
            } else {
                t += h[i]; // If enemy's health is 2 or less, we need to make that many moves
            }
        }

        // If after the move the health of the enemy is still positive, we need to make more moves
        if (h[i] > 0) {
            t += h[i]; // h[i] will be a positive number (or 0), representing the number of 1-damage moves needed
        }
    }

    cout << t << endl;
    return 0;
}