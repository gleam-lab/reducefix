#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>prefixsum(n+1,0);
    for(int i=0;i<n;i++){//求前缀和
        prefixsum[i+1]=prefixsum[i]+nums[i];
    }
    long long count=0;
    // 使用map统计每个余数出现的次数
    map<int,int> remainder_count;
    
    // 初始化：前缀和为0的情况（即从位置0开始）
    remainder_count[0] = 1;
    
    // 遍历所有位置，计算当前前缀和模m的余数
    for(int i=1; i<=n; i++){
        int r = prefixsum[i] % m;
        if(r < 0) r += m; // 处理负数取模
        
        // 如果之前有相同余数的前缀和，则它们之间的子数组和能被m整除
        if(remainder_count.find(r) != remainder_count.end()){
            count += remainder_count[r];
        }
        remainder_count[r]++;
    }
    
    // 在环形数组中，还需要考虑跨越末尾的情况
    // 对于s > t的情况，我们可以通过total_sum - (sum from t to s-1)来计算
    // 但更简单的方法是：对于任意两个位置i<j，如果(prefix[j]-prefix[i])%m==0，则满足条件
    // 上面的代码已经处理了所有i<j的情况（包括非环形）
    // 现在我们需要额外处理环形情况：即从后面到前面的部分
    
    // 实际上，上面的方法只处理了普通子数组，没有处理环形数组中s>t的情况
    // 我们需要重新思考：在环形数组中，从s到t的步数等于(total_sum - sum(s to t))当s>t时
    // 所以我们需要分别处理两种情况
    
    // 清空计数器，重新计算
    count = 0;
    remainder_count.clear();
    
    // total sum of the array
    int total_sum = prefixsum[n];
    
    // Case 1: s <= t (normal case)
    remainder_count[0] = 1;
    for(int i=1; i<=n; i++){
        int r = prefixsum[i] % m;
        if(r < 0) r += m;
        
        if(remainder_count.find(r) != remainder_count.end()){
            count += remainder_count[r];
        }
        remainder_count[r]++;
    }
    
    // Case 2: s > t (circular case)
    // In this case, steps = total_sum - (prefixsum[s] - prefixsum[t])
    // We want (total_sum - (prefixsum[s] - prefixsum[t])) % m == 0
    // => (prefixsum[s] - prefixsum[t] - total_sum) % m == 0
    // => (prefixsum[s] - prefixsum[t]) % m == total_sum % m
    // => (prefixsum[s] - total_sum) % m == prefixsum[t] % m
    
    remainder_count.clear();
    remainder_count[0] = 1; // prefixsum[0] = 0
    
    int target = total_sum % m;
    if(target < 0) target += m;
    
    for(int i=1; i<=n; i++){
        // We are looking for prefixsum[t] such that:
        // (prefixsum[s] - total_sum) % m == prefixsum[t] % m
        // So we store prefixsum[t] % m in the map
        int r_t = prefixsum[i] % m;
        if(r_t < 0) r_t += m;
        
        // For future positions s > i, we will check if 
        // (prefixsum[s] - total_sum) % m equals r_t
        remainder_count[r_t]++;
    }
    
    // Now traverse again to count valid pairs where s > t
    remainder_count.clear();
    // Start with no prefix sums in the map initially
    for(int s=1; s<=n; s++){
        // Remove prefixsum[s] from consideration as t (since t must be < s in circular case)
        // But we need to process in reverse order or differently
        
        // Let's change approach: for each t, find s > t such that 
        // (prefixsum[s] - total_sum) % m == prefixsum[t] % m
        // We can do this by iterating t from 0 to n-1 and maintaining a map of 
        // (prefixsum[s] - total_sum) % m for s > t
    }
    
    // Alternative simpler approach:
    // Instead of separating cases, consider all pairs (s,t) with s != t
    // For any pair (s,t):
    // if s <= t: steps = prefixsum[t] - prefixsum[s]
    // if s > t: steps = total_sum - (prefixsum[s] - prefixsum[t]) = total_sum - prefixsum[s] + prefixsum[t]
    //
    // We want steps % m == 0
    //
    // Case 1: s <= t
    // (prefixsum[t] - prefixsum[s]) % m == 0
    // => prefixsum[t] % m == prefixsum[s] % m
    //
    // Case 2: s > t  
    // (total_sum - prefixsum[s] + prefixsum[t]) % m == 0
    // => (prefixsum[t] - prefixsum[s] + total_sum) % m == 0
    // => (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    
    count = 0;
    
    // Count frequencies of prefixsum[i] % m for i = 0..n
    map<int, int> freq1, freq2; // freq1: prefixsum[i] % m, freq2: (prefixsum[i] + total_sum) % m
    
    for(int i=0; i<=n; i++){
        int r1 = prefixsum[i] % m;
        if(r1 < 0) r1 += m;
        freq1[r1]++;
        
        int r2 = (prefixsum[i] + total_sum) % m;
        if(r2 < 0) r2 += m;
        freq2[r2]++;
    }
    
    // For case 1: s <= t, but s != t
    // For each remainder r, if there are k positions with that remainder,
    // then number of ordered pairs (s,t) with s < t is k*(k-1)
    // But note: our condition is for s <= t, but we exclude s == t
    // Actually, we want s != t, and in case 1: s < t (since s<=t and s!=t)
    for(auto& [r, cnt] : freq1){
        if(cnt >= 2){
            count += (long long)cnt * (cnt - 1);
        }
    }
    
    // For case 2: s > t
    // We want (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    // For each position s and t with s > t satisfying the above
    // This is equivalent to: for each remainder r, 
    // count the number of t with (prefixsum[t] + total_sum) % m == r
    // and number of s with prefixsum[s] % m == r, and s > t
    // But since we don't care about the ordering in the frequency count,
    // and every pair (s,t) with s != t will be counted once in either case1 or case2,
    // we can simply multiply frequencies.
    
    // However, note that in case 2, s and t are independent except for the modulo condition
    // But we must ensure we don't double count or miss constraints
    
    // Actually, let's reconsider: the two cases are mutually exclusive:
    // case 1: s < t
    // case 2: s > t
    // And we've already counted case 1 above.
    
    // For case 2: we want to count pairs (s,t) with s > t such that
    // (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    
    // We can do this by iterating through all possible remainders
    for(int i=0; i<=n; i++){
        int r_target = prefixsum[i] % m;
        if(r_target < 0) r_target += m;
        
        // Find how many t < i such that (prefixsum[t] + total_sum) % m == r_target
        // But instead, let's use the frequency map
        
        // Actually, we can just multiply frequencies, but subtract diagonal terms
    }
    
    // Simpler approach: iterate over all pairs (s,t) with s != t using the conditions
    // But that would be O(n^2) which is too slow for large n
    
    // Let's go back to an efficient method:
    
    // Case 1: s < t: count pairs where prefixsum[s] % m == prefixsum[t] % m
    // Case 2: s > t: count pairs where (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    
    count = 0;
    
    // Build frequency map for prefixsum[i] % m for i = 0 to n
    map<int, int> freq;
    for(int i=0; i<=n; i++){
        int r = prefixsum[i] % m;
        if(r < 0) r += m;
        freq[r]++;
    }
    
    // Case 1: s < t with same remainder
    for(auto& [r, cnt] : freq){
        if(cnt >= 2){
            count += (long long)cnt * (cnt - 1);
        }
    }
    
    // Case 2: s > t with (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    // For each remainder r, let A[r] = frequency of prefixsum[i] % m == r
    // Let B[r] = frequency of (prefixsum[i] + total_sum) % m == r
    // But note: B[r] = A[(r - total_sum % m + m) % m]
    
    int total_mod = total_sum % m;
    if(total_mod < 0) total_mod += m;
    
    for(auto& [r, cnt] : freq){
        int target = (r - total_mod + m) % m;
        if(freq.find(target) != freq.end()){
            count += (long long)cnt * freq[target];
        }
    }
    
    // But wait, in case 2 we have s > t, but our multiplication counts all pairs (s,t)
    // regardless of whether s > t or not. We need to ensure the indices satisfy s > t.
    
    // Actually, no: in case 2, we're counting pairs where s can be any index and t can be any index,
    // but we want only s > t. The frequency method counts all combinations.
    
    // We need a different approach. Let's use the fact that:
    // For case 2: we want to count pairs (s,t) with s > t such that
    // (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    
    // We can do this by processing indices in order and maintaining a frequency map
    
    count = 0;
    freq.clear();
    
    // First, count case 1: s < t with prefixsum[s] % m == prefixsum[t] % m
    // Process from left to right
    freq[prefixsum[0] % m]++; // i = 0
    for(int i=1; i<=n; i++){
        int r = prefixsum[i] % m;
        if(r < 0) r += m;
        
        // Count how many previous positions have the same remainder
        if(freq.find(r) != freq.end()){
            count += freq[r];
        }
        
        freq[r]++;
    }
    
    // Now count case 2: s > t with (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    // This means: for a fixed s, we want t < s such that
    // (prefixsum[t] + total_sum) % m == prefixsum[s] % m
    // => prefixsum[t] % m == (prefixsum[s] - total_sum) % m
    
    freq.clear();
    freq[prefixsum[0] % m]++; // i = 0
    
    for(int s=1; s<=n; s++){
        int required_r = (prefixsum[s] - total_sum) % m;
        if(required_r < 0) required_r += m;
        
        if(freq.find(required_r) != freq.end()){
            count += freq[required_r];
        }
        
        // Add current prefixsum[s] to the map for future t's
        int curr_r = prefixsum[s] % m;
        if(curr_r < 0) curr_r += m;
        freq[curr_r]++;
    }
    
    cout<<count<<endl;
    return 0;
}