#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    int x[200005], sum[200005];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    sum[0] = 0;  // Initialize the sum array with zeros
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + x[i-1];  // Compute cumulative sum
    }
    
    cin >> q;
    while(q--){
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - (x + 1);  // Use x + 1 to get zero-based index
        int d = upper_bound(x + 1, x + n + 1, R) - (x + 1);  // Use x + 1 to get zero-based index
        
        cout << sum[d] - sum[c] << endl;  // Correct the indices for sum array
    }
    
    return 0;
}