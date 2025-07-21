#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],prefix[N],cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] %= m;
        if(a[i] < 0) a[i] += m; // handle negative numbers
    }
    
    // Non-circular case (standard divisible subarrays count)
    long long total = 0;
    cnt[0] = 1; // empty prefix has sum 0
    for(int i=1; i<=n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        if(prefix[i] < 0) prefix[i] += m;
        total += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    
    // Now handle the circular case by considering arrays that wrap around
    // We need to find pairs i < j where (prefix[j] - prefix[i]) % m == 0 and j-i < n
    // This is equivalent to the standard count plus the wrapped-around segments
    
    // To count wrapped-around segments, we can look for (prefix[n] - (prefix[j] - prefix[i])) % m == 0
    // But a better approach is to concatenate the array and use sliding window
    
    // Alternative approach: concatenate array and use sliding window of size <=n
    // But must be careful not to double-count
    
    // For circular array, total count is the same as standard count plus count of
    // segments that wrap around, which can be calculated by looking at the frequency
    // of (prefix[i] + total_sum % m) % m
    
    int total_sum = prefix[n];
    if(total_sum < 0) total_sum += m;
    
    // Reset cnt array
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    long long wrap_count = 0;
    
    // We need to count all i<j where (prefix[j] - prefix[i] + total_sum) % m == 0
    // Which is equivalent to (prefix[j] + total_sum) % m == prefix[i] % m
    for(int i=1; i<=n; i++) {
        int target = (prefix[i] + total_sum) % m;
        wrap_count += cnt[target];
        cnt[prefix[i]]++;
    }
    
    // The total is the previous count plus the wrapped count minus the cases we double counted
    // But since the standard count already includes all segments within single array,
    // the wrap_count includes all segments that wrap around plus some single array segments
    // The correct formula is more complex
    
    // Alternatively, a better approach is to just concatenate the array and count
    // all subarrays of length <=n with sum % m == 0
    
    // Here's the correct implementation using concatenated array:
    for(int i=1; i<=n; i++) {
        a[i+n] = a[i];
    }
    
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    long long circular_total = 0;
    prefix[0] = 0;
    
    for(int i=1; i<=2*n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        if(prefix[i] < 0) prefix[i] += m;
        
        if(i > n) {
            cnt[prefix[i-n] % m]--;
        }
        
        circular_total += cnt[prefix[i]];
        
        if(i < n) {
            cnt[prefix[i]]++;
        }
    }
    
    cout << circular_total << endl;
    return 0;
}