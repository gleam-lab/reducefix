#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long

int t, n, k;
int A[200001], B[200001];

// ç¨äºç»´æ¤ä¸ä¸ªååºéåï¼åæ¶æ ¹æ®è¦æ±æå°åéåä¸­çå
auto min_queue = [](priority_queue<int, vector<int>, greater<int>>& q, vector<long long>& sum) {
    if (!q.empty()) {
        auto front = q.top();
        q.pop();
        if (sum[front] > 0) {
            sum[front]--;
            q.push(front);
        }
    }
};

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long sumB[200001] = {0}; // å­å¨æ¯ä¸ª B_i åºç°çæ¬¡æ°
        priority_queue<int, vector<int>, greater<int>> q;
        long long ans = LLONG_MAX;
        
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            cin >> B[i];
            sumB[B[i]]++;
        }

        for (int i = 1; i <= k; i++) {
            q.push(B[i]);
        }

        // é¦è®¡ç®åå§çç­æ¡
        long long sum = 0;
        for (int i = k; i <= n; i++) {
            sum += q.top();
            q.pop();
            sumB[B[i]]--;
            q.push(B[i]);
            ans = min(ans, sum * A[i]);
        }

        cout << ans << endl;
    }
    return 0;
}