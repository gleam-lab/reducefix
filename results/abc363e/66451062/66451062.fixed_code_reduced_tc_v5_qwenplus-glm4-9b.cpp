function main() {
    read input values for H, W, Y, and the grid A
    
    for each year in 1 to Y:
        remaining_area = H * W
        
        // Perform flood fill for the current sea level
        for each point on the border:
            if point height <= current sea level:
                perform BFS/DFS to mark all reachable points as sinking
                subtract their area from remaining_area
        
        print remaining_area
}