#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        T += full_cycles * 3;
        if (remaining > 0) {
            if (remaining <= 2) {
                T += remaining;
            } else {
                T += 3;
            }
        }
    }
    // Adjust T if the last attack was a multiple of 3, but it might not be necessary
    // However, the above approach might not account for the exact T where H[i] becomes <=0
    // So, we need a better approach.
    // Let's re-approach the problem more carefully.

    // Correct approach: Binary search on T
    // The minimal T such that sum_{i=1 to N} (ceil((H_i - (T//3)) / 1) + T//3) <= T
    // But it's complex. Alternative approach: track the total attacks and the 3-attack cycles.

    // Let's think differently: For each enemy, find the minimal T_i such that the total attacks (with 3-attack cycles) reduce H_i to <=0.
    // Then, the total T is the maximum T_i, but we need to ensure that the attacks on previous enemies are accounted for.

    // Wait, no. The attacks are sequential, so previous enemies affect the T for later enemies.

    // So, we need to simulate the attacks in order, but for efficiency, we can precompute the required attacks for each enemy.
    // The problem is that the 3-attack cycles depend on the total T up to that point.

    // Alternative idea: For each enemy, the number of attacks needed is:
    // Let x be the number of 3-attacks (T mod 3 == 0) and y be the number of 1-attacks.
    // Then, 3x + y >= H_i, and x + y = T_i.

    // But this is not directly helpful. Let's use binary search on T.

    // Binary search approach:
    // For a given T, the number of 3-attacks is floor(T / 3), and the number of 1-attacks is T - floor(T / 3).
    // For each enemy, the total damage is 3 * floor(T / 3) + 1 * (T - floor(T / 3)) >= H_i?
    // No, because the 3-attacks are spread out every 3rd attack. So, the damage is more nuanced.

    // The correct way is to compute the damage for a given T:
    // Number of 3-attacks: k = T / 3.
    // Number of 1-attacks: T - k.
    // Total damage for each by enemy: if H_i <= T, then it's dead, because in the worst case, all 1-attacks (each dealing 1) would suffice.
    // But actually, the damage depends on how the 3-attacks are distributed.

    // The maximal damage for a given T is when as many 3-attacks as possible are applied.
    // So, damage = 3*k + (T - k)*1 = 2k + T.
    // But this is not precise, because the 3-attacks are periodic.

    // We need a way to compute the minimal T such that for each H_i, the sum of 1's and 3's up to T is >= H_i.

    // The correct formula is: for each H_i, the minimal T_i such that (T_i - T_i // 3) * 1 + (T_i // 3) * 3 >= H_i.
    // Simplifying: T_i + 2*(T_i // 3) >= H_i.
    // So, for each H_i, find the minimal T_i satisfying this inequality, and then the total T is the maximum of all T_i.

    // So, for each enemy, compute T_i, and then the answer is max(T_i).

    T = 0;
    for (int i = 0; i < N; i++) {
        long long low = 0, high = 2 * H[i]; // Upper bound could be large enough
        long long T_i = 2 * H[i];
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long damage = mid + 2 * (mid / 3);
            if (damage >= H[i]) {
                T_i = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // The actual T must be >= T_i, but also must account for the attacks spent on previous enemies.
        // So, the total T is the maximum between the current T and T_i plus some adjustment.
        // But since attacks are sequential, T must be at least the sum-like property.
        // For example, if T_i is the minimal for H_i, then T must be >= previous T + attacks for H_i.
        // But this is not straightforward.

        // Alternatively, the total T is the minimal time when all enemies are dead, considering the order.
        // So, the total T is the maximum T_i such that T_i is the minimal time to kill enemy i, given the attacks before it.

        T = max(T, T_i);
    }
    cout << T << endl;
    return 0;
}