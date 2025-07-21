#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    long long bonus3 = 0, bonus2 = 0;

    for (long long h : H) {
        long long total = h;
        long long t = T;

        // Attacks cycle: every 3rd attack deals 3 damage, others deal 1 damage
        // We need to calculate how many attacks are needed to reduce health to 0 or less

        // First handle the bonus attacks from previous enemies that can hit this enemy
        if (bonus3 > 0 && total > 0) {
            total -= 1; // One triple attack leftover from previous calculations
            bonus3--;
            T++;
        }
        if (bonus2 > 0 && total > 0) {
            used = min(bonus2, total);
            total -= used;
            T += used;
            bonus2 -= used;
        }

        // Now compute number of full cycles of 3 attacks and remaining attacks
        long long full_cycles = total / 5;
        long long rem = total % 5;
        T += full_cycles * 3;
        
        if (rem == 1) {
            T += 1;
            bonus2 += 2;
            bonus3 += 0;
        } else if (rem == 2) {
            T += 2;
            bonus2 += 1;
            bonus3 += 0;
        } else if (rem == 3) {
            T += 3;
            bonus2 += 0;
            bonus3 += 0;
        } else if (rem == 4) {
            T += 3;
            bonus2 += 0;
            bonus3 += 1;
        }
    }

    cout << T << endl;
    return 0;
}