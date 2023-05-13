class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int X=grid.size();
        int Y = grid[0].size();
        for(int i=0;i<X;i++){
            for(int j=0;j<Y;j++){
                if(grid[i][j]!='0'){
                    dfs(grid, i, j, X, Y);
                    c++;
                }
            }
        }
        return c;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j, int X, int Y){
        if(!isSafe(i,j,X,Y)){
            return;
        } 
        if(grid[i][j]=='0'){
             return;
         }
        
        grid[i][j] = '0';
        dfs(grid, i+1, j, X, Y);
        dfs(grid, i, j+1, X, Y);
        
        dfs(grid, i-1, j, X, Y);
        dfs(grid, i, j-1, X, Y);
    }
    
    bool isSafe(int i, int j, int X, int Y){
        if(0<=i and i<X and 0<=j and j<Y){
            return true;
        }
        return false;
    }
};