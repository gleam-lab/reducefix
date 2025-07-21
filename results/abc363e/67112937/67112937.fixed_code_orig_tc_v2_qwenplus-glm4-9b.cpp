int H, W, Y;
int A[H][W];

// Read input

bool sinkable[H][W];

// Initialize sinkable array
for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
        sinkable[i][j] = false;
    }
}

// Mark the sections that are on the edge and will sink in the first year
for (int j = 0; j < W; j++) {
    if (i == 0 || i == H-1 || j == 0 || j == W-1) {
        sinkable[i][j] = true;
    }
}

while (true) {
    int sinkCount = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Check if the section will sink
            if (sinkable[i][j] && (i > 0 && sinkable[i-1][j] || i < H-1 && sinkable[i+1][j] || j > 0 && sinkable[i][j-1] || j < W-1 && sinkable[i][j+1])) {
                sinkable[i][j] = true;
                sinkCount++;
            }
        }
    }

    if (sinkCount == 0) {
        break;
    }

    // Calculate remaining area
    int remainingArea = H * W - sinkCount;
    // Print the result for the current year
    // ...
}