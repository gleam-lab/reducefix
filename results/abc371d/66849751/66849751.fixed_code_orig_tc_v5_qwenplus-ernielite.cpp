// ... (previous code remains the same)

    // ... (rest of the code remains the same until here)

    // Fixing the issue by checking if X_l or X_r are at the end of the map
    if (X_l == x_to_ptr.end()) {
        // If X_l is at the end, it means L is not present in X.
        // Handle this case appropriately (e.g., set l to a special value or handle the error)
        l = N; // Or any other appropriate handling
    } else {
        l = (*X_l).second;
    }
    if (X_r == x_to_ptr.end()) {
        // Similarly, handle the case when R is not present in X.
        r = N; // Or any other appropriate handling
    } else {
        r = (*X_r).second;
    }
    // ... (rest of the code remains the same)