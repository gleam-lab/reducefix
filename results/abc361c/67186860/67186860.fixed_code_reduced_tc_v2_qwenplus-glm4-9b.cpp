#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    // Extract largest K elements
    vector<int> largest_k;
    extract_largest_k(A, k, largest_k);
    
    sort(A.begin(), A.end());
    
    // Remove elements from A
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        if (A[low] < largest_k.front() || high < k - 1) {
            low++;
            continue;
        }
        if (A[high] > largest_k.back() || high >= k - 1) {
            high--;
            continue;
        }
        A.erase(A.begin() + low);
        A.erase(A.end() - 1);
        k -= 2;
        if (k == 0) break;
    }
    if (k > 0) {
        int toRemove = min(k, n - (A.size() + k));
        A.erase(A.begin() + A.size() - toRemove, A.end());
    }
    
    // Compute the answer
    int min_val = *min_element(A.begin(), A.end());
    int max_val = *max_element(A.begin(), A.end());
    cout << max_val - min_val << endl;
    
    return 0;
}

void extract_largest_k(const vector<int>& A, int k, vector<int>& largest_k) {
    priority_queue<int> pq;
    for (int a : A) {
        pq.push(a);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        largest_k.push_back(pq.top());
        pq.pop();
    }
    sort(largest_k.begin(), largest_k.end(), greater<int>());
}