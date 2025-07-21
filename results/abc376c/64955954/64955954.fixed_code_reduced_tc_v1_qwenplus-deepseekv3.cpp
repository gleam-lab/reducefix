#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<long long> possible_x;
    
    // Check if we can match all toys except one to existing boxes
    // The remaining toy will be placed in the new box x
    // We need to try all possible positions where the remaining toy could be
    for (int skip = 0; skip < N; ++skip) {
        bool possible = true;
        int b_idx = 0;
        long long x = -1;
        
        for (int a_idx = 0; a_idx < N; ++a_idx) {
            if (a_idx == skip) continue;
            if (b_idx < N - 1 && B[b_idx] >= A[a_idx]) {
                b_idx++;
            } else {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            x = A[skip];
            possible_x.push_back(x);
        }
    }
    
    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        long long min_x = *min_element(possible_x.begin(), possible_x.end());
        cout << min_x << endl;
    }
    
    return 0;
}