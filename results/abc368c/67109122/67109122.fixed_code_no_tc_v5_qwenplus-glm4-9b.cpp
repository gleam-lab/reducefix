#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long T = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        // Calculate the number of full rounds (T increments by 1 per round)
        // where we can attack with 3 damage and still need to attack at least once with 1 damage.
        // If the health is divisible by 3, we can reduce it by 3 every time until the remainder is less than 3.
        T += (H[i] + 2) / 3; // This adds not only full 3-damage attacks but also the necessary 1-damage attack at the end if needed.
        
        // If after the above reduction, the health is still greater than 0, we must attack once more with 1 damage.
        if (H[i] % 3 == 0) {
            // We only add 1 to T if the health was exactly divisible by 3, because in that case we would
            // have already added 3 full 3-damage attacks and we now need one more 1-damage attack.
            T += 1;
        }
    }
    
    cout << T << endl;
    return 0;
}