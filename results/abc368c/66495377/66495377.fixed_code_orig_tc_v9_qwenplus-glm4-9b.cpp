#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long t = 0, h;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        // Calculate full groups of 5 and the remainder
        int full_groups = h / 5;
        int remainder = h % 5;

        // Calculate the number of attacks for full groups of 5
        // If the number of full groups is divisible by 3, we can make all attacks at once
        if (full_groups % 3 == 0) {
            t += full_groups;
        } else {
            // We need to make (full_groups % 3) attacks for the first group
            // Then, we need to attack the remaining enemies one by one
            t += full_groups + full_groups % 3;

            // Now, we need to handle the remainder
            if (remainder > 0) {
                // If remainder is 1, 2, or 3, we can handle it with a single attack (T % 3)
                if (remainder <= 3) {
                    t += 1;
                } else {
                    // If remainder > 3, we need to make one attack that will reduce the health by 3
                    t += 1;
                    remainder -= 3;
                    // Now we need to make attacks to reduce the remainder to 0
                    while (remainder > 0) {
                        t++;
                        if (t % 3 == 0) {
                            remainder -= 3;
                        } else {
                            remainder--;
                        }
                    }
                }
            }
        }
    }
    cout << t << endl;
    return 0;
}