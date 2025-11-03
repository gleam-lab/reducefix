#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // Handle edge case: if n == 1, no valid (s,t) pairs with s != t
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Compute prefix sums modulo m
    vector<long long> prefixsum(n+1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i+1] = (prefixsum[i] + nums[i]) % m;
    }

    // For circular distance: step from s to t is:
    // if s < t: sum[s..t-1] = prefix[t] - prefix[s]
    // if s > t: sum[s..end] + sum[0..t-1] = (prefix[n]-prefix[s]) + prefix[t]
    // We want (step % m == 0), i.e., step ≡ 0 (mod m)

    // Instead of O(N^2), use frequency map to count valid pairs efficiently.
    // But note: the condition is not just on prefix differences directly due to circularity.

    // However, let's re-analyze:
    // Step count from index s to t (1-indexed positions):
    // In 0-indexed: starting at s-1, ending before t.
    // Total steps mod m should be 0.

    // Let’s define contribution:
    // If s <= t: total = prefixsum[t] - prefixsum[s]
    // If s > t: total = prefixsum[n] - prefixsum[s] + prefixsum[t]

    // We want total ≡ 0 (mod m)
    // Case 1: s <= t → (prefixsum[t] - prefixsum[s]) % m == 0 → prefixsum[t] ≡ prefixsum[s] (mod m)
    // Case 2: s > t → (prefixsum[n] - prefixsum[s] + prefixsum[t]) % m == 0 
    //         → (prefixsum[t] - prefixsum[s] + prefixsum[n]) % m == 0
    //         → (prefixsum[t] - prefixsum[s]) % m == (-prefixsum[n]) % m
    //         → (prefixsum[t] - prefixsum[s]) % m == (m - prefixsum[n]%m) % m

    // So we can do:
    // Count frequency of prefixsum[i] for i in [0, n] (each prefix corresponds to a position)
    // Then for every pair (s, t) with s != t:
    //   if s < t: check if prefixsum[s] ≡ prefixsum[t]
    //   if s > t: check if (prefixsum[t] - prefixsum[s]) % m == (-prefixsum[n]) % m

    // But doing this naively is O(N^2). We need to optimize.

    // Alternative idea: iterate over all unordered pairs? Not helpful.

    // Actually constraints might allow O(N^2) if N is small? But problem doesn't specify.

    // Since original code uses O(N^2), and failing case passes, maybe logic is correct but off-by-one?

    // Wait: in the failing case: n=1, m=1, nums=[136872]
    // Our loop: s from 1 to n (i.e. 1), t from 1 to n (1)
    // only pair: s=1,t=1 → skipped by 'if(s==t)continue'
    // so count=0 → output 0 → matches expected.

    // So why did it fail? The error analysis says "Outputs appear identical"

    // Possibly the real issue is elsewhere.

    // But wait — indexing: our prefixsum[i] = sum of nums[0] to nums[i-1]
    // So segment from s to t (1-indexed): 
    //   if s < t: elements from index s-1 to t-2 → sum = prefixsum[t-1] - prefixsum[s-1]? 
    // But in code: 
    //   s and t are 1-indexed positions.
    //   step = prefixsum[t] - prefixsum[s] when s < t → that would be sum from index s to t-1 → correct if s and t are indices into prefix array.

    // But note: prefixsum[i] corresponds to first i elements.
    // So from position s (element index s-1) to position t (element index t-1), going forward:
    //   if s < t: we take elements from index s-1 to t-2 → that's (t-s) elements → sum = prefixsum[t-1] - prefixsum[s-1]
    // But in code: uses prefixsum[t] - prefixsum[s] → which is sum from index s to t-1 → off by one.

    // Example: n=2, m=1, nums=[1,2]
    // prefixsum = [0,1,3]
    // Consider s=1, t=2: should be sum of element at index 0 → 1
    // Code does: prefixsum[2]-prefixsum[1] = 3-1 = 2 → wrong.

    // Correction: the sum from position s to t (exclusive of t, inclusive of s) in 1-indexed:
    //   corresponds to subarray [s-1, t-2] when s < t → sum = prefixsum[t-1] - prefixsum[s-1]
    // But our prefixsum[i] includes first i elements, so:
    //   sum from index L to R inclusive = prefixsum[R+1] - prefixsum[L]

    // From s to t (forward): indices from s-1 to t-2 → sum = prefixsum[t-1] - prefixsum[s-1]

    // Similarly, backward: from s to t (s>t): go from s-1 to end, then 0 to t-2
    //   part1: s-1 to n-1 → sum = prefixsum[n] - prefixsum[s-1]
    //   part2: 0 to t-2 → sum = prefixsum[t-1]
    //   total = prefixsum[n] - prefixsum[s-1] + prefixsum[t-1]

    // So in code, we should use:
    //   if (s < t): step = prefixsum[t-1] - prefixsum[s-1]
    //   else:      step = prefixsum[n] - prefixsum[s-1] + prefixsum[t-1]

    // But currently using s and t as direct indices into prefixsum without subtracting 1.

    // Fix: change indexing in loops or adjust usage.

    // Let’s redefine: let s_idx = s-1, t_idx = t-1
    // Then:
    //   if s < t: step = prefixsum[t] - prefixsum[s] → wait, no.

    // Actually, let's reframe: remove 1-indexing confusion.

    // Use 0-indexed positions for start and end.
    // Let i and j be 0-indexed positions (start and end), i != j.
    // We want the sum along the path from i to j in clockwise direction.

    // Clockwise from i to j:
    //   if i < j: elements from i to j-1 → sum = prefixsum[j] - prefixsum[i]
    //   if i > j: elements from i to n-1 and 0 to j-1 → sum = (prefixsum[n]-prefixsum[i]) + prefixsum[j]

    // So total step count = 
    //   (i < j) ? (prefixsum[j] - prefixsum[i]) : (prefixsum[n] - prefixsum[i] + prefixsum[j])

    // And we want this sum % m == 0.

    // Now, the number of such pairs (i,j) with i != j.

    // So we can do:

    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            long long step;
            if (i < j) {
                step = prefixsum[j] - prefixsum[i];
            } else {
                step = prefixsum[n] - prefixsum[i] + prefixsum[j];
            }
            if (step % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}