#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct Node {
    ll val, idx;
};

// Comparator function to sort nodes based on their value
bool compare(Node a, Node b) {
    return a.val > b.val;
}

ll solve(int n, int k, vector<ll>& a, vector<ll>& b) {
    vector<Node> arr(n);
    
    // Create an array of nodes where each node contains a value and its index
    for(int i = 0; i < n; ++i) {
        arr[i] = {a[i], i};
    }
    
    // Sort the array of nodes in descending order based on their value
    sort(arr.begin(), arr.end(), compare);
    
    ll sum_b = 0;
    priority_queue<ll> pq;
    
    // Iterate through the sorted array
    for(int i = 0; i < n; ++i) {
        sum_b += b[arr[i].idx]; // Add the corresponding value from B to the sum
        pq.push(b[arr[i].idx]); // Push the value into the priority queue
        
        // If the size of the priority queue exceeds k, remove the largest element
        if(pq.size() > k) {
            sum_b -= pq.top();
            pq.pop();
        }
        
        // If we have selected exactly k elements, calculate the product and update the answer
        if(i >= k - 1) {
            ll current_ans = (sum_b * arr[i].val);
            return current_ans;
        }
    }
    
    return 0; // This line should never be reached
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        ll result = solve(n, k, a, b);
        cout << result << "\n";
    }
    
    return 0;
}