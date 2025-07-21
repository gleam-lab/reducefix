#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    int min_diff = INT_MAX;

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            set<int> s(A.begin(), A.end());
            set<int>::iterator it;
            
            it = s.find(A[i]);
            s.erase(it);
            int max_val = *max_element(s.begin(), s.end());
            
            it = s.find(A[j]);
            s.erase(it);
            int min_val = *min_element(s.begin(), s.end());
            
            min_diff = min(min_diff, max_val - min_val);
        }
    }

    cout << min_diff << endl;
    return 0;
}