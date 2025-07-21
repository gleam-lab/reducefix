// Assuming `i` is the current year's sea level
while (!pq.empty() && pq.top()[0] == i) {
    auto a = pq.top(); pq.pop(); 
    // ... handle the sinking of section `a` ...
    // Check vertical neighbors
    if (a[1] > 0 && A[a[1]-1][a[2]] <= i) {
        if (chmax(used[a[1]-1][a[2]], 1)) { pq.push({A[a[1]-1][a[2]], a[1]-1, a[2]}); }
    }
    if (a[1] < H-1 && A[a[1]+1][a[2]] <= i) {
        if (chmax(used[a[1]+1][a[2]], 1)) { pq.push({A[a[1]+1][a[2]], a[1]+1, a[2]}); }
    }
    // Check horizontal neighbors
    if (a[2] > 0 && A[a[1]][a[2]-1] <= i) {
        if (chmax(used[a[1]][a[2]-1], 1)) { pq.push({A[a[1]][a[2]-1], a[1], a[2]-1}); }
    }
    if (a[2] < W-1 && A[a[1]][a[2]+1] <= i) {
        if (chmax(used[a[1]][a[2]+1], 1)) { pq.push({A[a[1]][a[2]+1], a[1], a[2]+1}); }
    }
}

// After processing, `ans` should be updated with the remaining area above sea level