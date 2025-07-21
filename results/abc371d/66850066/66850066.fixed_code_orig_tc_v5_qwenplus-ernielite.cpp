// ... (previous code) ...
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) { // Use a for loop with proper index instead of rep(q, Q) for clarity.
        int L, R; // Declare L and R directly instead of using rep macro.
        cin >> L >> R; // Read L and R directly without using macros.
        auto X_l = x_to_ptr.lower_bound(L); // Same as before for lower_bound.
        auto X_r = x_to_ptr.upper_bound(R); // Same for upper_bound as well.
        int l = (X_l == x_to_ptr.end()) ? N : (*X_l).second; // Check if X_l is end() before using .second.
        int r = (X_r == x_to_ptr.end()) ? N : (*X_r).second; // Same for X_r.
        if (l > r) { // Check if l is greater than r, indicating no valid range found.
            cout << "0" << endl; // Output 0 or any other appropriate value to indicate no valid range found.
            continue; // Skip to the next query to avoid using incorrect values of l and r.
        }
        int ans = P[r] - P[l]; // Calculate ans only if a valid range is found.
        cout << ans << endl; // Output the result as before.
    }
}