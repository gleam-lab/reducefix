#include <bits/stdc++.h>

using namespace std;

struct Point {
    int value;
    int index;
};

bool compare(const Point& p1, const Point& p2) {
    return p1.value < p2.value;
}

vector<int> solve(vector<int>& A, vector<pair<int, int>>& queries) {
    int n = A.size();
    sort(A.begin(), A.end());
    
    vector<int> results(queries.size());
    
    for (int i = 0; i < queries.size(); ++i) {
        int target = queries[i].first;
        int k = queries[i].second - 1;
        
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                results[i] = 0;
                break;
            } else if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (results[i] != 0) {
            int dist = abs(target - A[left]);
            if (left > 0 && abs(target - A[left - 1]) < dist) {
                dist = abs(target - A[left - 1]);
            }
            if (left < n - 1 && abs(target - A[left + 1]) < dist) {
                dist = abs(target - A[left + 1]);
            }
            
            results[i] = dist;
        }
    }
    
    return results;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    vector<int> results = solve(A, queries);
    
    for (int result : results) {
        cout << result << '\n';
    }
    
    return 0;
}