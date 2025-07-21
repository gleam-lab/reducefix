// Assume BFS is a function that will process the queue and sinks adjacent cells
for (int year = 1; year <= Y; year++) {
    // Initialize a new queue with the cells that sank in the previous year
    queue<pair<int, int>> new_queue;
    for (auto p : q[year - 1]) {
        new_queue.push(p);
    }

    // Perform BFS for the current year
    while (!new_queue.empty()) {
        auto [x, y] = new_queue.front();
        new_queue.pop();

        // Check all 4 directions and sink adjacent cells if they have the same elevation
        // ... (BFS logic)
    }

    // Update the queue for the next year
    for (auto p : q[year]) {
        new_queue.push(p);
    }

    // Calculate and print the remaining area
    ans = H * W; // Reset the area to the total size of the island
    // Subtract the number of cells that have sunk this year
    // ... (Calculate number of cells that sank)

    cout << ans << endl;
}