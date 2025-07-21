// ... (rest of the code remains the same)

// After reading all X values, sort them to maintain correct order in the map
sort(X.begin(), X.end()); // Sorting the X array to maintain order in the map's key
// Then proceed with creating the map as before using X values as keys and their indices as values
map<int, int> x_to_ptr; // Declare the map to store X values as keys and their corresponding indices in X array
rep(i, N){ // Populate the map with X values and their indices
    x_to_ptr.emplace(X[i], i); // Store X values and their indices in the map, maintaining order based on sorting of X array
}
// ... (rest of the code remains the same)