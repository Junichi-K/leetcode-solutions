class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col])
                    result += cell_perimeter(grid, row, col);
            }
        }

        return result;
    }


    int cell_perimeter(vector<vector<int>> &grid, int row, int col) {
        int result = 4;
        
        if((row > 0 && grid[row - 1][col]))
            result--;

        if(row < grid.size() - 1 && grid[row + 1][col])
            result--;

        if(col > 0 && grid[row][col - 1])
            result--;

        if(col < grid[0].size() - 1 && grid[row][col + 1])
            result--;

        return result;

    }
};

//i just skipped the info that the border did contribute to the perimeter as well, so did the reverse implementation with 4	