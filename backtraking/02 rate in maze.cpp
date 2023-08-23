#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y,vector<vector<int>> board, vector<vector<int>> visited){

    int rowSize = board.size();
    int colSize = board[0].size();


    if((x>=0 && x<rowSize) && (y>=0 && y<colSize) && (visited[x][y]==0) && (board[x][y]=='.')){
        return true;
    }
    else{
        return false;
    }

}

bool solve(int srcx, int srcy, int destx, int desty, vector<vector<int>> board,
                vector<vector<int>> visited){

        if(srcx==destx && srcy==desty){
            return true;
        }

        // down
        int newx = srcx+1;
        int newy = srcy;
        bool downAns = false;
        if(isSafe(newx, newy, board, visited)){

            visited[newx][newy] = true;
            downAns = solve(newx,newy, destx, desty, board, visited);

            // backtrack
            visited[newx][newy] = false;
        }

        // right

        int newx = srcx;
        int newy = srcy+1;
        bool rightAns = false;
        if(isSafe(newx, newy, board, visited)){

            visited[newx][newy] = true;
            rightAns = solve(newx,newy, destx, desty, board, visited);

            // backtrack
            visited[newx][newy] = false;
        }

        // left

        int newx = srcx;
        int newy = srcy-1;
        bool leftAns = false;
        if(isSafe(newx, newy, board, visited)){

            visited[newx][newy] = true;
            leftAns = solve(newx,newy, destx, desty, board, visited);

            // backtrack
            visited[newx][newy] = false;
        }

        // up
        int newx = srcx-1;
        int newy = srcy;
        bool upAns = false;
        if(isSafe(newx, newy, board, visited)){

            visited[newx][newy] = true;
            upAns = solve(newx,newy, destx, desty, board, visited);

            // backtrack
            visited[newx][newy] = false;
        }



        if(downAns || upAns || leftAns || rightAns){
            return true;
        }
        else{
            return false;
        }
}


class Solution{
    public:
    
    bool isSafe(int X, int Y, int n, vector<vector<int>> visited, vector<vector<int>> m) {
        if((X >= 0 && X < n) && (Y >= 0 && Y < n) && visited[X][Y] == 0 && m[X][Y] == 1)
            return true;
        return false;
    }
    
    
    void solve(vector<vector<int>> &m, int n, vector<string> & ans, string path, 
              vector<vector<int>> visited, int srcx, int srcy ){
        
        if(srcx == n-1 && srcy == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[srcx][srcy] = 1;
        
        // down
        
        int newx = srcx;
        int newy = srcy+1;
        
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('R');
            solve(m,n,ans,path, visited, newx, newy);
            path.pop_back();
        }
        
        newx = srcx;
        newy = srcy-1;
        
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('L');
            solve(m,n,ans,path, visited, newx, newy);
            path.pop_back();
        }
        
        newx = srcx+1;
        newy = srcy;
        
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('D');
            solve(m,n,ans,path, visited, newx, newy);
            path.pop_back();
        }
        
        newx = srcx-1;
        newy = srcy;
        
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('U');
            solve(m,n,ans,path, visited, newx, newy);
            path.pop_back();
        }
        
        visited[srcx][srcy] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0]==0){
            return ans;
        }
        
        int srcx = 0;
        int srcy = 0;
        
        vector<vector<int>> visited = m;
        
        // make false everything
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        
        string path = "";
        
        
        solve(m,n,ans,path,visited,srcx,srcy);
        sort(ans.begin(), ans.end());
        
        return ans;
        
        
    }
};