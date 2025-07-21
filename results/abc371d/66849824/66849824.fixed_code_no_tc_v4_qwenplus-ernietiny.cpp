#include <bits/stdc++.h>

using namespace std;

// Fixed C++ code block

int main(){
    int N;
    cin >> N; // Assuming the number of elements in X is already provided in some other way.
    vector<ll> P(N+1), X(N); // Assuming X[i] represents the value at position i in P
    P[0] = 0; // Initialize P vector with the first element set to 0
    // ... Rest of the code remains the same ...

    // The corrected code starts here
    map<int, int> x_to_ptr; // Create a map to store pointers to X indices
    int Q; // Number of queries
    cin >> Q; // Read the number of queries
    // ... Rest of the code remains the same ...
}