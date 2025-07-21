#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll T = 0;
    for (ll hi : h) {
        // Number of full 3-attack cycles (each cycle deals 5 damage)
        ll cycles = hi / 5;
        ll remaining = hi % 5;
        
        // Each cycle contributes 3 to T (since each cycle is 3 attacks)
        T += cycles * 3;
        
        if (remaining > 0) {
            // The remaining health requires 1 or 2 more attacks
            if (remaining <= 2) {
                T += remaining;
            } else {
                // The remaining 3 or 4 requires 2 attacks (1+3 or 1+1+3?)
                // Wait, no. For remaining 3: 1 attack (since T+1 is mod 3, if T mod 3 is 0, then attack 3)
                // So, for remaining 3: 1 attack (3 damage)
                // For remaining 4: 2 attacks (1 + 3)
                if (remaining == 3) {
                    T += 1;
                } else if (remaining == 4) {
                    T += 2;
                }
            }
        }
    }
    
    // Need to ensure that during the process, the attacks are in sequence.
    // The above assumes independent calculation for each enemy, but in reality, the T is cumulative across all enemies.
    // Thus, the above approach is incorrect. We need to simulate the attacks in order.

    // Therefore, the correct approach is to simulate each attack in sequence, but for large N and H, this is O(sum H_i), which is not feasible.

    // We need a better approach. Let's think about the total attacks needed.

    // The problem is similar to scheduling attacks where every 3rd attack deals 3 damage, others 1.
    // For each enemy, the number of attacks required is ceil(hi / 3) if T is aligned such that every attack on it is a 3-damage.
    // But since T is global, we need to find a way to compute the minimal T where sum of damages to each enemy >= H_i.
    // This requires a binary search approach.

    // Binary search the minimal T where the total damage to each enemy is >= H_i.
    // For a given T, the damage to an enemy is:
    // (T + 2) / 3 * 3 (number of 3-damage attacks) + T - (T + 2) / 3 (number of 1 damage attacks)
    // Wait, no. The total damage is (T // 3) * 3 + (T % 3)? Or actually:
    // The number of 3-damage attacks is T // 3, and the number of 1-damage attacks is T - T // 3.
    // So the total damage is 3*(T//3) + 1*(T - T//3) = T//3 *3 + T - T//3 = T + 2*(T//3).
    // But that's not correct. Wait, the total damage is:
    // For each attack t (1..T), damage is 3 if t mod 3 == 0 else 1.
    // So total damage = number of multiples of 3 up to T *3 + others *1 = (T//3)*3 + (T - T//3) = T//3 * 3 + T - T//3 = T + 2*(T//3).
    // So total damage for T attacks is T + 2*(T//3).

    // But we need to find for each enemy, the minimal T such that the damage is >= H_i, considering that the attacks are cumulative across all enemies.

    // Oh, but the attacks are sequential per enemy. So the first attacks are on enemy 1 until its health drops to <=0, then move to enemy 2, etc.

    // So the problem requires simulating the process, but with O(N) enemies and O(1) per enemy via mathematical calculation.

    // Let's think differently: for each enemy, the sequence of attacks it receives is the same as the global T sequence.

    // For the i-th enemy, the damage it receives is:
    // Let T_i be the total attacks up to before the i-th enemy is attacked.
    // Then the attacks on the i-th enemy are from T_i +1 to T_i + k_i, where k_i is the number of attacks needed to reduce H_i to <=0.

    // The damage to the i-th enemy is sum_{t = T_i+1 to T_i + k_i} (t %3 ==0 ? 3 : 1).

    // This sum can be computed as:
    // (number of multiples of 3 in [T_i+1, T_i + k_i]) *3 + (number of non-multiples) *1.

    // The number of multiples of 3 in [a, b] is floor(b/3) - floor((a-1)/3).

    // For the i-th enemy:
    // a = T_i +1, b = T_i + k_i.
    // So the number of multiples is floor((T_i + k_i)/3) - floor((T_i)/3).

    // The damage then is 3*(floor((T_i + k_i)/3) - floor((T_i)/3)) + (k_i - (floor((T_i + k_i)/3) - floor((T_i)/3))) *1
    // = 3*(A) + (k_i -A)*1 = 2*A + k_i, where A is the number of multiples of 3 in the interval.
    // We want this to be >= H_i.

    // So, 2*(floor((T_i + k_i)/3) - floor(T_i/3)) + k_i >= H_i.

    // But solving this equation for k_i is non-trivial. 

    // Alternative approach: for each enemy, given T_i, find the minimal k_i such that the damage conditions are met.

    // Then, T_{i+1} =T_i + k_i.

    // However, this requires, for each enemy, to compute k_i based on T_i and H_i.

    // The damage for k_i attacks starting after T_i is D = (number of multiples of 3 in (T_i+1, T_i +k_i)) *3 + (k_i - number of multiples)*1.

    // The number of multiples is floor((T_i +k_i)/3) - floor(T_i/3).

    // So D = 3*(floor((T_i +k_i)/3) - floor(T_i/3)) + (k_i - (floor((T_i +k_i)/3) - floor(T_i/3))) = 2*(floor((T_i +k_i)/3) - floor(T_i/3)) + k_i.

    // We need D >= H_i. Find the minimal k_i.

    // This can be done via binary search for k_i.

    // So for each enemy, perform a binary search to find the minimal k_i such that D >= H_i, then add k_i to T.

    // This approach is O(N log H_i), which is feasible for N=2e5 and H_i=1e9.

    // Implementing this approach.

    T = 0;
    for (ll hi : h) {
        ll low = 0, high = 3 * hi; // Upper bound: if all attacks are 1-damage, need hi attacks. So 3*hi is more than enough.
        ll k_i = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll multiples = (T + mid) / 3 - T / 3;
            ll damage = 2 * multiples + mid;
            if (damage >= hi) {
                k_i = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        T += k_i;
    }
    cout << T << endl;
}