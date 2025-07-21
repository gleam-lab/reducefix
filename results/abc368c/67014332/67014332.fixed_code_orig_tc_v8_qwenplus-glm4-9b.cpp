#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long health;
        cin >> health;
        ans += (health / 3);  // Add the number of full attacks of 3 damage each.
        health %= 3;          // Update the remaining health.
        if (health > 0) {     // If there's remaining health, calculate the extra damage needed.
            long long extraAttacks = health;
            if (ans % 3 == 0) {
                extraAttacks = (ans / 3) + 1;  // If ans is a multiple of 3, use an additional attack.
            } else if (extraAttacks % 3 == 0) {
                extraAttacks -= (ans % 3);  // If extraAttacks is a multiple of 3, adjust it to be a multiple of 3.
            }
            ans += extraAttacks;  // Add the extra attacks to the total.
        }
    }
    cout << ans << endl;
}