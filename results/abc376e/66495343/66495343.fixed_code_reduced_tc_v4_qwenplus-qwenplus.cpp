#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int INF = 1e18;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        
        vector<PII> items(n);
        for(int i = 0; i < n; ++i)
            cin >> items[i].first;
        
        for(int i = 0; i < n; ++i)
            cin >> items[i].second;
        
        // Sort by A_i ascending
        sort(items.begin(), items.end());
        
        int res = INF;
        int sum_b = 0;
        priority_queue<int> max_heap; // To store the smallest B_i values we want to discard if needed
        
        // First, take the first k-1 elements' B values
        for(int i = 0; i < k - 1; ++i)
        {
            sum_b += items[i].se;
            max_heap.push(items[i].se);
        }
        
        // Now try each possible i from k-1 to n-1 as the maximum A value
        for(int i = k - 1; i < n; ++i)
        {
            // Add current B value
            sum_b += items[i].se;
            max_heap.push(items[i].se);
            
            // If we have more than k elements, remove the one with largest B (since we want smallest k-1 Bs)
            if(max_heap.size() > k)
            {
                int large = max_heap.top();
                max_heap.pop();
                sum_b -= large;
            }
            
            // Calculate current cost
            int current_cost = items[i].fi * sum_b;
            res = min(res, current_cost);
        }
        
        cout << res << '\n';
    }
    
    return 0;
}