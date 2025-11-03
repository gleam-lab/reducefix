#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // Compute prefix sums: prefixsum[i] = sum of nums[0] to nums[i-1]
    vector<int> prefixsum(n+1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i+1] = (prefixsum[i] + nums[i]) % m;
    }

    long long count = 0;
    
    // Use frequency map to count how many times each modulo value has occurred
    vector<int> modCount(m, 0);
    
    // Traverse all starting positions s and ending positions t where s != t
    // We consider circular segments: from s to t (s != t)
    // The sum from index s to t-1 (circular) is equivalent to (prefixsum[t] - prefixsum[s] + m) % m
    // We want this sum ≡ 0 (mod m), so we need prefixsum[t] ≡ prefixsum[s] (mod m)
    
    // Initialize modCount with prefixsum[0]
    modCount[prefixsum[0]]++;
    
    for(int t = 1; t <= n; t++){
        // For each t, count how many previous s (s < t) such that prefixsum[s] == prefixsum[t]
        // Each such pair gives a valid segment from s to t-1 (non-empty since s != t)
        count += modCount[prefixsum[t]];
        
        // Update frequency for current prefix
        modCount[prefixsum[t]]++;
    }
    
    // But now we've included cases where the segment wraps around and might be full circle?
    // Actually our method naturally handles circularity via mod arithmetic.
    // However note: the problem considers ordered pairs (s,t) with s != t, and segment from s to t in circular fashion.
    // Our approach using prefix sums correctly captures contiguous subarrays (including wrap-around if needed).
    // But wait: does the original double loop allow any s,t in 1..n with s != t?
    // In our mapping: s corresponds to start index (0-indexed), t corresponds to end index (exclusive)
    // So every valid (s,t) pair with s != t is a non-empty proper segment.

    // However, the above algorithm counts all s < t such that prefixsum[s] == prefixsum[t].
    // This gives the number of subarrays (contiguous, non-wrap) with sum divisible by m.
    // But the problem allows wrap-around? Let's re-read the intent.

    // Looking back at original code: when s > t, it computes:
    //   step = prefixsum[n] - prefixsum[s] + prefixsum[t]
    // which is the sum from s to end plus from start to t-1 -> wrap-around segment.

    // So the problem wants all ordered pairs (s,t) with s != t, and the circular segment from s to t (not including t?)
    // Actually indexing is confusing.

    // Let's reinterpret:
    // Original code uses 1-indexed s,t meaning positions.
    // When s < t: sum from index s to t-1 (0-indexed s-1 to t-2?) — actually no.

    // Better approach: fix the logic.

    // After analysis: the intended meaning is:
    // There are n positions. A move from position s to position t (s != t) along the circle.
    // The cost is the sum of weights on the path from s to t (in forward direction, wrapping if needed).

    // Positions are 1..n, but array nums[0..n-1] corresponds to positions 1..n.
    // Path from s to t:
    //   if s < t: sum of nums[s-1] to nums[t-2] (length t-s)
    //   if s > t: sum of nums[s-1] to nums[n-1] and nums[0] to nums[t-2]

    // Total sum around circle is total = prefixsum[n].
    // The sum from s to t (s != t) in circular forward direction is:
    //   if s < t: prefixsum[t-1] - prefixsum[s-1]
    //   if s > t: (prefixsum[n] - prefixsum[s-1]) + prefixsum[t-1]
    //           = prefixsum[t-1] - prefixsum[s-1] + prefixsum[n]

    // We want this sum ≡ 0 (mod m)

    // So condition:
    //   if s < t: (prefixsum[t-1] - prefixsum[s-1]) % m == 0  => prefixsum[t-1] ≡ prefixsum[s-1] (mod m)
    //   if s > t: (prefixsum[t-1] - prefixsum[s-1] + prefixsum[n]) % m == 0 
    //            => prefixsum[t-1] - prefixsum[s-1] ≡ -prefixsum[n] (mod m)
    //            => prefixsum[s-1] - prefixsum[t-1] ≡ prefixsum[n] (mod m)

    // This is asymmetric. We cannot use simple frequency count.

    // Alternatively, note that the sum from s to t (forward circular) is:
    //   (prefixsum[t-1] - prefixsum[s-1] + prefixsum[n]) % m  ??? Not exactly.

    // Actually define:
    //   Let P[i] = prefixsum[i] = sum_{j=0}^{i-1} nums[j]
    //   Then sum from index a to b-1 (non-wrap) is P[b] - P[a]
    //   Sum from s to t in circular way (s>t): from index s-1 to n-1, then 0 to t-2 -> 
    //        = (P[n] - P[s-1]) + (P[t-1] - P[0]) = P[n] - P[s-1] + P[t-1]
    //   Since P[0]=0.

    // So total = 
    //   if s <= t: P[t] - P[s]   [but note: s and t are positions, so indices s-1 to t-1? Wait]

    // Clarify indexing:
    //   Position s corresponds to index s-1.
    //   The segment from position s to position t (not including t) goes through positions s, s+1, ..., t-1 (if s<t)
    //   So elements: nums[s-1], nums[s], ..., nums[t-2] -> sum = P[t-1] - P[s-1]

    // Similarly, if s>t: positions s to n, then 1 to t-1 -> indices s-1 to n-1, then 0 to t-2
    //   sum = (P[n]-P[s-1]) + (P[t-1]-P[0]) = P[n] - P[s-1] + P[t-1]

    // Therefore, sum ≡ 0 mod m:
    //   Case 1: s < t -> P[t-1] - P[s-1] ≡ 0 -> P[t-1] ≡ P[s-1] (mod m)
    //   Case 2: s > t -> P[n] - P[s-1] + P[t-1] ≡ 0 -> P[t-1] - P[s-1] ≡ -P[n] (mod m)

    // Now we can compute:
    //   Precompute all prefix sums P[0..n] (size n+1)
    //   Then iterate over all s,t in 1..n, s != t.

    // But O(n^2) might be acceptable? Constraints not given. But let's assume n up to 2000 -> n^2=4e6 ok.
    // But original code was O(n^2) so likely acceptable.

    // However, the original code had a bug: it used prefixsum[t] and prefixsum[s] without adjusting indices.

    // In original code:
    //   s and t from 1 to n
    //   if s < t: step = prefixsum[t] - prefixsum[s]
    //   But prefixsum[t] = sum of first t elements = P[t]
    //   We need sum from position s to t-1 -> that would be from index s-1 to t-2 -> P[t-1]-P[s-1]
    //   But they did P[t]-P[s] -> which is sum from index s to t-1 -> positions s+1 to t -> wrong.

    // So indexing is off by one.

    // Correct approach with O(n^2):
    //   For each s in 1..n, t in 1..n, s != t:
    //      if s < t: sum = P[t-1] - P[s-1]
    //      if s > t: sum = P[n] - P[s-1] + P[t-1]
    //   Check sum % m == 0

    // But note: negative modulo: use ((x % m) + m) % m

    // Alternatively, we can do:

    vector<int>& P = prefixsum; // P[i] = sum of nums[0] to nums[i-1]
    long long ans = 0;
    for(int s = 1; s <= n; s++){
        for(int t = 1; t <= n; t++){
            if(s == t) continue;
            int sum;
            if(s < t){
                sum = P[t-1] - P[s-1];
            } else {
                sum = P[n] - P[s-1] + P[t-1];
            }
            if(sum % m == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}