#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int MAXN = 2e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;

struct Item {
    int value, index;
};

bool cmp(const Item &a, const Item &b) {
    return a.value > b.value;
}

void solve(int n, int k, vector<int> &A, vector<int> &B) {
    vector<Item> items(n);
    
    // Create an array of items where each item contains A[i] and its index
    for (int i = 0; i < n; ++i) {
        items[i] = {A[i], i};
    }
    
    // Sort items based on A[i] in descending order
    sort(items.begin(), items.end(), cmp);
    
    // Create a prefix sum array for B[i]
    vector<long long> prefixSum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + B[items[i].index];
    }
    
    long long ans = INF;
    
    // Iterate through the sorted items to find the minimum value of the expression
    for (int i = 0; i <= n - k; ++i) {
        int maxValue = items[i].value;
        long long sum = prefixSum[i + k] - prefixSum[i];
        ans = min(ans, (long long)maxValue * sum);
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        solve(n, k, A, B);
    }
    
    return 0;
}