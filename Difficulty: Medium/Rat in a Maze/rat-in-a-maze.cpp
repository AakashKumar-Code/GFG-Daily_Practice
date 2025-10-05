#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>

class Solution {
  public:
  
    vs ans;
    string path;
    int n;
    
    vvi dirs={
        {-1,0},
        {0,1},
        {1,0},
        {0,-1}
    };
    
    string direction="URDL";
    
    void dfs(int row,int col,vvi &maze){
        if(row==n-1 && col==n-1){
            ans.push_back(path);
            return ;
        }
        
        if(!maze[row][col]) return ;
        
        maze[row][col]=0;
        
        for(int dir=0;dir<4;dir++){
            int nr=row+dirs[dir][0],nc=col+dirs[dir][1];
            
            if(nr>=0 && nr<n && nc>=0 && nc<n && maze[nr][nc]!=0){
                path.push_back(direction[dir]);
                dfs(nr,nc,maze);
                path.pop_back();
            }
        }
        
        maze[row][col]=1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n=maze.size();
        ans.clear();
        path="";
        dfs(0,0,maze);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};