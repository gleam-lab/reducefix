#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        for(int i=0;i<n;i++) cin >> A[i];
        for(int i=0;i<n;i++) cin >> B[i];
        
        // Create pairs of A[i] and B[i]
        vector<pair<int, int>> AB(n);
        for(int i=0;i<n;i++) AB[i] = {A[i], B[i]};
        
        // Sort based on A[i] in descending order
        sort(AB.begin(), AB.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.f > b.f;
        });
        
        // Use a multiset to keep track of the smallest B[i] values
        multiset<int> st;
        long long sum_B = 0;
        for(int i=0;i<k;i++) {
            st.insert(AB[i].s);
            sum_B += AB[i].s;
        }
        
        // Initialize the answer with the current product
        long long ans = st.rbegin()->second * sum_B;
        
        // Iterate through the remaining elements to find the minimum product
        for(int i=k;i<n;i++) {
            // Remove the smallest element in the set
            sum_B -= *st.begin();
            st.erase(st.begin());
            
            // Add the new element from the sorted array
            st.insert(AB[i].s);
            sum_B += AB[i].s;
            
            // Update the answer with the new product
            ans = min(ans, *st.rbegin() * sum_B);
        }
        
        cout << ans << '\n';
    }
    return 0;
}