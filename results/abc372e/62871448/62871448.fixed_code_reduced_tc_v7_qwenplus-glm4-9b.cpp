#include<bits/stdc++.h>
using namespace std;

// Define union-find structure and top k data structure here

int main() {
    cin >> n >> q;
    // Initialize union-find and top k data structures here

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            // Add edge case: Union the sets and update top k structures
        } else if (op == 2) {
            // Query k-th largest case: Find root and retrieve from top k structure
        }
    }

    return 0;
}