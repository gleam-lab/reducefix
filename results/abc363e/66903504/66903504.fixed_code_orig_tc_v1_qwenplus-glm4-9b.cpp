# Pseudocode for the improved approach

# Read input
H, W, Y = read dimensions and years
A = read elevation matrix

# Initialize structures
queue = new PriorityQueue()
processed = new HxW matrix of booleans
neighbors = initialize adjacency lists for each cell

# Initialize queue with border cells and cells at sea level
for each cell on the border or at sea level
    queue.add(cell.elevation with coordinates)

total_area = H * W

# Process each year
for year from 1 to Y
    while queue is not empty
        elevation, (i, j) = queue.pop()
        if processed[i][j] == false
            processed[i][j] = true
            total_area -= 1
            for neighbor in neighbors[i][j]
                if neighbor.elevation > current sea level and not processed[neighbor]
                    queue.add(neighbor.elevation with coordinates)
    
    current sea level += 1
    print remaining area (total_area)