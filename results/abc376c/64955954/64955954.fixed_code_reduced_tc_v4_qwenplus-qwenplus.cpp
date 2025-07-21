#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N), B(N - 1);
    
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // We need to assign each toy to a box such that:
    // - Each box can contain at most one toy.
    // - Toy i fits in box j if box[j] >= toy[i]
    
    // Try greedy matching:
    // Match smallest toy to smallest possible box that fits it
    
    multiset<long long> boxes;
    for (long long b : B) boxes.insert(b);
    
    int matched = 0;
    for (long long a : A) {
        auto it = boxes.lower_bound(a);
        if (it != boxes.end()) {
            matched++;
            boxes.erase(it);
        }
    }
    
    if (matched == N) {
        cout << "-1" << endl;
    } else {
        // We need to find the minimum x such that we can place the unmatched toy
        // The new box x must be >= the unmatched toy, and all other toys must still fit
        // Let's try with each toy being the unmatched one (in worst case)
        
        // Sort both in increasing order
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        // Try to match A[i] with B[i], for i = 0 to N-2
        // If A[N-1] is left out, then x needs to be >= A[N-1]
        // But also check whether A[0..N-2] can be matched with B[0..N-2]
        
        // Try greedy matching between sorted A and B
        int i = 0, j = 0;
        int matched2 = 0;
        while (i < N && j < N - 1) {
            if (A[i] <= B[j]) {
                matched2++;
                i++;
                j++;
            } else {
                i++;
            }
        }
        
        // If matched2 >= N-1, only one toy cannot be placed, buy a box for it
        if (matched2 == N - 1) {
            cout << A[N - 1] << endl;
        } else {
            // Even with extra box, cannot place all toys
            cout << "-1" << endl;
        }
    }
    
    return 0;
}