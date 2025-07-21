#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll ans = 0;
    vector<ll> attacks_needed(n);
    
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        // Each cycle of 3 attacks deals 5 damage (1+1+3)
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        ll additional_attacks = 0;
        
        if (remaining > 0) {
            if (remaining <= 2) {
                additional_attacks = remaining; // 1 damage per attack
            } else {
                additional_attacks = 3; // 1+1+3, but remaining is 3, 4
                // For 3: 3 attacks (1+1+3) but the third attack deals 3, so total is 5 > 3
                // Wait, for remaining 3: 1 (T=1), 1 (T=2), 3 (T=3) -> total 5, but remaining is 3.
                // Wait, that's full_cycles*5 + 3, but remaining is 3.
                // So for remaining 3: 2 attacks (1 +3) not possible, since T=3 is the third attack.
                // So it's 3 attacks (1,1,3) which sums to 5, but 5 > 3.
                // So to get exact remaining, adjust.
                if (remaining == 3) {
                    additional_attacks = 3;
                } else if (remaining == 4) {
                    additional_attacks = 4; // 1+1+1+3 (T=4 is not a multiple of 3)
                    // Wait, no. Let's see: T starts from ans+1.
                    // For remaining 3: attack sequence would be ans+1 (1), ans+2 (1), ans+3 (3) → total 5 >3.
                    // So for remaining 3, need 3 attacks.
                    // For remaining 4: ans+1 (1), ans+2 (1), ans+3 (3) → total 5; but remaining is 4.
                    // So one more attack: ans+4 (1) → total 6 >4.
                    // So actually, we need to see how many attacks to cover remaining.
                    // Let's model the attacks:
                    // For each attack, the damage is 1 or 3 based on T.
                    // So for remaining 3: requires 3 attacks (1+1+3) =5, which covers 3.
                    // For remaining 4: requires 4 attacks (1+1+3+1) =6 which covers 4.
                    // So additional_attacks = remaining + (remaining / 3) if remaining %3 != 0?
                    // No. For remaining 3: 3 attacks (5 damage). For remaining 4: 4 attacks (6 damage).
                    // So additional_attacks is remaining if remaining <=2, else remaining +1.
                    // But for remaining 3: 3 attacks (5 damage).
                    // So it's remaining + (remaining +2)/3 -1? No.
                    // Alternatively, for remaining r:
                    // The minimal k such that sum_{i=1 to k} (if i mod 3 ==0 then 3 else 1) >= r.
                    // For example:
                    // r=1: 1 attack (1) → k=1.
                    // r=2: 2 attacks (1,1) → k=2.
                    // r=3: 3 attacks (1,1,3) → sum 5 (but k=3).
                    // r=4: 4 attacks (1,1,3,1) → sum 6 (k=4).
                    // r=5: 3 attacks (1,1,3) → sum 5 (k=3).
                    // r=6: 5 attacks (1,1,3,1,1) → sum 7 (but wait, no. 3 attacks (1,1,3) sum 5. 4 attacks sum 6. 5 attacks sum 7. 6 attacks sum 10 (1,1,3,1,1,3). So r=6 requires 4 attacks (sum 6).
                    // So the minimal k is the smallest k where the sum S(k) >= r.
                    // S(k) = floor((k-1)/3)*5 + (k%3 ==1?1:0) + (k%3 ==2?2:0) + (k%3 ==0?5:0)
                    // No, S(k) = floor((k+2)/3)*3 - floor((k)/3)*2? Not sure.
                    // Alternatively, S(k) can be calculated as:
                    // S(k) = k + 2*(k/3) because every third attack gives an extra +2 damage (since it's 3 instead of 1).
                    // So S(k) = k + 2*(k/3).
                    // We need to find the smallest k such that S(k) >= r.
                    // For example:
                    // k=1: S(1)=1.
                    // k=2: S(2)=2.
                    // k=3: S(3)=3+2=5.
                    // k=4: S(4)=4+2=6.
                    // k=5: S(5)=5+2*1=7.
                    // k=6: S(6)=6+2*2=10.
                    // So for r=3: k=3 (5>=3).
                    // r=4: k=4 (6>=4).
                    // r=5: k=3 (5>=5).
                    // r=6: k=4 (6>=6), k=5 (7>=6), but minimal is 4.
                    // So the minimal k is the smallest k where k + 2*(k/3) >= r.
                    // We can binary search k for this.
                    ll low = 1, high = remaining * 2;
                    while (low < high) {
                        ll mid = (low + high) / 2;
                        if (mid + 2 * (mid / 3) >= remaining) {
                            high = mid;
                        } else {
                            low = mid + 1;
                        }
                    }
                    additional_attacks = low;
                }
            }
        }
        attacks_needed[i] = full_cycles * 3 + additional_attacks;
    }
    
    ll max_before = 0;
    for (int i = 0; i < n; ++i) {
        // The start time for enemy i is max_before + 1.
        // The attacks for enemy i are from max_before +1 to max_before + attacks_needed[i].
        // The total T after processing enemy i is max_before + attacks_needed[i].
        // The enemy must be processed in order.
        max_before += attacks_needed[i];
    }
    
    cout << max_before << endl;
    return 0;
}