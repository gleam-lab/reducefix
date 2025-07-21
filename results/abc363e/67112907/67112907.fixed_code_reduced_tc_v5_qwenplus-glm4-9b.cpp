for each year from 1 to Y:
    queue cells_to_flood = get_cells_to_flood(year)
    flood cells in cells_to_flood
    increment year

    remaining_area = count_remaining_cells(year)
    print remaining_area