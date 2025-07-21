#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// ... (other definitions remain the same) ...

int main() {
    // ... (input and initialization remain the same) ...
    map<int, int> x_to_ptr; // Initialize the map to store X values and their indices
    for (int i = 0; i < N; i++) { // Iterate over X vector to populate the map
        x_to_ptr[X[i]] = i; // Store X[i] and its index i in the map
    }
    // Now you can use x_to_ptr as before to find l and r based on X values.
    // ... (rest of the code remains the same) ...
}