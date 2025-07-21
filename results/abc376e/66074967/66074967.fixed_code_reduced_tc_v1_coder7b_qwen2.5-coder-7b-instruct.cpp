#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int INF = 1e9;

int solve(int n, int k, vector<pair<int, int>>& a, vector<int>& b) {
    // Sort pairs based on A_i in descending order
    sort(a.begin(), a.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    });

    // Initialize variables
    int ans = INF;
    long long sum = 0;
    priority_queue<int> pq;

    // Iterate through the sorted pairs
    for (int i = 0; i < n; ++i) {
        int ai = a[i].first;
        int bi = b[a[i].second];

        // Add B_i to the sum and push it into the priority queue
        sum += bi;
        pq.push(bi);

        // If the size of the priority queue exceeds k, remove the largest element
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }

        // Calculate the current expression value
        if (pq.size() == k) {
            ans = min(ans, sum * ai);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int result = solve(n, k, a, b);
        cout << result << endl;
    }

    return 0;
}