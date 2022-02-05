class Solution {
    public:        
    bool isvalid(int i, int j, int X, int Y){
        return (i >= 0 && j >= 0 && i < X && j < Y);
    } 
    
    struct ele {
        int x, y;
    };

    bool isdelim(ele temp){
        return (temp.x == -1 && temp.y == -1);
    } 

    bool checkall(vector<vector<int>> arr, int R, int C){
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++)
                if (arr[i][j] == 1)     
                    return true;    
        return false;
    }   

    int orangesRotting(vector<vector<int>>& arr) {
        int R = arr.size();  
        int C = arr[0].size();        
        
        queue<ele> Q;    
        ele temp;    
        int ans = 0;         
              
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (arr[i][j] == 2) {
                    temp.x = i;
                    temp.y = j;
                    Q.push(temp);    
                }
            }    
        }
      
        temp.x = -1;    
        temp.y = -1;   
        Q.push(temp);         
        while (!Q.empty()) {
            bool flag = false; 
            while (!isdelim(Q.front())){
                temp = Q.front();
                if (isvalid(temp.x+1, temp.y,  R, C) && arr[temp.x+1][temp.y] == 1) {
                    if (!flag) ans++, flag = true; 
                    arr[temp.x+1][temp.y] = 2; 
                    temp.x++;
                    Q.push(temp); 
                    temp.x--;   
                }
                if (isvalid(temp.x-1, temp.y, R, C) && arr[temp.x-1][temp.y] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.x-1][temp.y] = 2;
                    temp.x--;
                    Q.push(temp);
                    temp.x++;    
                }
                if (isvalid(temp.x, temp.y+1, R, C) && arr[temp.x][temp.y+1] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.x][temp.y+1] = 2;
                    temp.y++;
                    Q.push(temp); 
                    temp.y--;    
                }
                
                if (isvalid(temp.x, temp.y-1, R, C) && arr[temp.x][temp.y-1] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.x][temp.y-1] = 2;
                    temp.y--;
                    Q.push(temp);     
                }
                
                Q.pop();
            } 
            Q.pop(); 
            if (!Q.empty()) {
                temp.x = -1;
                temp.y = -1;
                Q.push(temp);
            }     
        }
        return (checkall(arr, R, C))? -1: ans;
    }
};
