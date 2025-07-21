// ... (previous code remains unchanged)

int main() {
    // ... (previous code for input and initialization remains unchanged)
    
    while(m--){
        int l,r;
        cin >> l >> r;
        auto l_it = lower_bound(a.begin()+1, a.end(), l); // Find position of 'l' in 'a' (inclusive)
        auto r_it = upper_bound(a.begin()+1, a.end(), r); // Find position one after 'r' in 'a' (exclusive)
        
        // Check if 'l' or 'r' are not found in 'a' or if they are out of bounds
        if (l_it == a.end() || r_it == a.begin()) {
            cout << -1 << endl; // Set output to -1 if no valid range or out of bounds
            continue; // Skip to next query without further processing
        }
        
        // Calculate the difference in prefix sums based on 'l_it' and 'r_it' positions
        int diff = c[r_it - a.begin() - 1] - c[l_it - a.begin() - 1]; // Subtract prefix sum at 'l' from prefix sum at 'r' (exclusive)
        cout << diff << endl; // Output the calculated difference for this query
    }
    return 0;
}