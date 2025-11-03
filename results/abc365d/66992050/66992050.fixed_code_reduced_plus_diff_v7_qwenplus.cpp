#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We want to minimize the number of hand changes
    // Each time we need to use a different hand than the previous move, we must change
    // The optimal strategy is to simulate all possible starting hands and choose the minimal changes
    
    // dp[i][hand] = minimum changes needed up to i-th move ending with 'hand'
    // hand: 0 for left (R), 1 for right (P), 2 for both (S)
    // But note: S requires both hands, so after S we can start with either
    // R -> must use left hand
    // P -> must use right hand
    // S -> must use both hands
    
    // Actually, simpler approach:
    // We can use greedy with state machine
    // State: which hand was used last (0=left/R, 1=right/P, 2=both/S)
    // But after S, we can choose optimal next hand
    
    // Alternative insight:
    // We need to count transitions between incompatible hands
    // Let's think differently: we want to assign hands optimally to minimize switches
    
    // For each move:
    // - If move is 'R': must use left hand
    // - If move is 'P': must use right hand  
    // - If move is 'S': must use both hands (so effectively forces a "change" unless coming from both)
    
    // After using both hands (S), we can choose which hand to keep active for next move
    
    // So we can use DP:
    // dp[i][h] = min changes up to position i, where h is the hand we end with (0=left, 1=right)
    // But when we do 'S', we must use both hands, so we have to switch to both, then choose next hand
    
    // Actually, we don't need to track "both" as a state since it's transient
    // When we encounter 'S', we must pay a change if previous hand wasn't both (but we don't track both)
    
    // Better approach:
    // We know that:
    // - Consecutive same type doesn't require change
    // - Change only when switching between R and P
    // - S always requires both hands, so:
    //   * If previous was R or P, we need a change to use both hands
    //   * After S, we can choose optimal hand for next move
    
    // Therefore, after an 'S', we have freedom to choose the best hand for the next non-S sequence
    
    // Algorithm:
    // Break string into segments separated by 'S'
    // Each segment is a sequence of R and P only
    // Within a segment, we need at least (number of RP or PR transitions) changes
    // But we can choose starting hand for each segment
    
    // However, after an 'S', we must pay one change to get to either R or P (since S uses both hands)
    // Except if the segment is empty
    
    // Also, before first move, no hand is active, so first move always costs 1 change
    // But problem doesn't specify initial state - let's assume we start with no hand active
    // So first move always requires a change
    
    // Revised plan:
    // Use DP where:
    // dp[i][0] = min changes for prefix [0:i] ending with left hand active
    // dp[i][1] = min changes for prefix [0:i] ending with right hand active
    // For 'S' at position i: we must use both hands, so:
    //   cost = 1 + min(dp[i-1][0], dp[i-1][1])  [the 1 is for switching to both]
    //   but after S, we don't have a single hand active, so we need to handle next differently
    
    // Actually, after S, for the next non-S character, we will need an additional change
    // So better to process in groups
    
    // Even simpler:
    // Total changes = 1 (for first move) + sum over transitions
    // But we can optimize around S
    
    // Insight from known similar problems:
    // Answer = 1 (initial change) + count of adjacent different moves that are not separated by S
    // But after S, we can avoid a change
    
    // Correct solution:
    // We must use a hand for each move.
    // - First move: cost 1 (to bring hand into position)
    // - For subsequent moves:
    //   * If same hand needed: cost 0
    //   * If different hand needed: cost 1
    //   * If S is needed: cost 1 (because both hands must be used, so even if one was already active, other must move in)
    // But wait: if previous was S, then both hands are already active, so current S needs 0 additional change?
    
    // Let me reconsider:
    // The problem is about changing hands. When we do S, we must use both hands.
    // So:
    // - From R to S: need to bring right hand in -> cost 1
    // - From P to S: need to bring left hand in -> cost 1  
    // - From S to R: can keep left hand, retire right -> cost 0? or do we count retiring?
    // - From S to P: keep right hand -> cost 0
    // - From S to S: both hands already active -> cost 0
    
    // But the problem likely counts any hand movement as a change.
    // However, the sample: "PPR" -> expected 2
    // P->P: 0
    // P->R: 1 (change from right to left hand)
    // Plus first move cost 1? That would be 2 total.
    
    // So perhaps:
    // - First move: cost 1
    // - Move i (i>=1): cost 1 if different hand is required than move i-1, except when move i-1 was S
    
    // But what defines "different hand"?
    // Each move requires specific hand(s):
    // - R: left hand
    // - P: right hand  
    // - S: both hands
    
    // Transition costs:
    // prev \ curr | R     | P     | S
    // ------------|-------|-------|------
    // R           | 0     | 1     | 1
    // P           | 1     | 0     | 1
    // S           | 0*    | 0*    | 0
    //
    // *After S, both hands are active, so moving to R or P doesn't require bringing new hand in?
    // But actually, to do R after S, you might need to "focus" on left hand, but the right hand is still there.
    // The problem likely considers that once both hands are active, you can do R or P without additional change.
    
    // Let's test with "PPR":
    // Start: no hands active
    // P1: activate right hand -> cost 1
    // P2: right hand already active -> cost 0
    // R3: need left hand, right is active -> cost 1
    // Total: 2 ✓
    
    // Test with "PS":
    // P: cost 1 (activate right)
    // S: need both hands, left not active -> cost 1
    // Total: 2
    
    // Test with "SP":
    // S: cost 1 (activate both hands)
    // P: right hand already active -> cost 0
    // Total: 1
    
    // Test with "SS":
    // S: cost 1
    // S: both already active -> cost 0
    // Total: 1
    
    // This seems consistent.
    
    // Therefore:
    // cost = 0
    // for i in range(n):
    //   if i == 0:
    //       cost += 1  # first move always costs 1
    //   else:
    //       if current move is S:
    //           if previous move was S: cost += 0
    //           else: cost += 1  # need to activate second hand
    //       elif current move is R or P:
    //           if previous move was S: cost += 0  # both hands active, can use appropriate one
    //           elif previous move is same as current: cost += 0
    //           else: cost += 1  # switch hands
    
    // But we need to track what hands are active after each move:
    // - After R: only left active
    // - After P: only right active  
    // - After S: both active
    
    // So state is the set of active hands after each move.
    
    int ans = 0;
    int active = 0; // bit mask: 1 for left (R), 2 for right (P), 3 for both (S)
    
    for (char c : S) {
        if (active == 0) {
            // no hands active - first move
            ans++;
            if (c == 'R') active = 1;
            else if (c == 'P') active = 2;
            else if (c == 'S') active = 3;
        } else {
            int required = 0;
            if (c == 'R') required = 1;
            else if (c == 'P') required = 2;
            else if (c == 'S') required = 3;
            
            // Check if current active hands cover required hands
            if ((active & required) == required) {
                // No change needed - required hands are already active
                // But update active hands to exactly the required ones?
                // Actually, after R or P, only that hand remains active?
                // The problem doesn't specify, but logically:
                // After doing R (with both hands active), do we keep both active?
                // Probably not - we only need one hand, so other rests.
                // So after R: only left active
                // After P: only right active
                // After S: both active
                active = required;
            } else {
                ans++;
                active = required;
            }
        }
    }
    
    cout << ans;
    return 0;
}