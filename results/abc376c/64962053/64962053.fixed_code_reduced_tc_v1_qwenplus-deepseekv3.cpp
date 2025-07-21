#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    multiset<int> boxes(B.begin(), B.end());
    vector<int> unmatched_toys;
    
    for (int a : A) {
        auto it = boxes.lower_bound(a);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            unmatched_toys.push_back(a);
        }
    }
    
    if (unmatched_toys.size() != 1) {
        cout << -1 << endl;
    } else {
        cout << unmatched_toys[0] << endl;
    }
    
    return 0;
}