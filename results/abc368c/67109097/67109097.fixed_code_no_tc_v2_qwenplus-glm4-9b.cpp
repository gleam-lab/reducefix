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
        // Calculate the number of full attacks with T % 3 that we need to make the health a multiple of 3
        int full_attacks = H[i] / 3;
        int remainder = H[i] % 3;
        
        // Add full attacks to T
        T += full_attacks * 3;
        
        // If there is a remainder, we need to attack additional times
        if (remainder > 0) {
            // Check if the remainder is a multiple of 3 or not
            if (remainder == 1) {
                // If remainder is 1, we need two more attacks to make it multiple of 3
                T += 2;
            } else { // remainder == 2
                // If remainder is 2, we can finish it with one more attack
                T++;
            }
        }
    }

    cout << T << endl;
    return 0;
}