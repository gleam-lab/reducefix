#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int ans = 0;
    bool first_attack = true;

    for (int health : H) {
        if (health > 0) {
            // Calculate the number of full groups of 3 and the remainder
            int full_groups = health / 3;
            int remainder = health % 3;

            // Add the number of full groups times 3 to total attacks
            ans += full_groups * 3;

            // If there's a remainder, calculate additional attacks needed
            if (remainder > 0) {
                if (remainder == 1 || (first_attack && remainder == 2)) {
                    ans++;  // One additional attack for the first enemy with remainder 2
                } else if (remainder == 2) {
                    ans += 2;  // Two additional attacks for the second enemy with remainder 2
                }
                first_attack = false;  // Mark that we have attacked at least once
            }
        }
    }

    cout << ans << endl;
    return 0;
}