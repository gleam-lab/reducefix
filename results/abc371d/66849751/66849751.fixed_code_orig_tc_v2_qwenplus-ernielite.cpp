int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        if (X_l != x_to_ptr.end()) { // Check if X_l is not at the end of the map
            l = X_l->second; // Use -> instead of (*X_l).second to access the value of the iterator
        } else {
            l = N; // If X_l is at the end, set l to N as a default value or handle it appropriately
        }
        if (X_r != x_to_ptr.end()) { // Check if X_r is not at the end of the map
            r = X_r->second; // Same here, use -> instead of (*X_r).second
        } else {
            r = N; // Set r to N if X_r is at the end of the map
        }
        // The rest of your code...
    }