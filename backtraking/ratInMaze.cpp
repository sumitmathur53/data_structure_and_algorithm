#include<bits/stdc++.h>
using namespace std;

// up, douwn , left, right path to fallow in this order

void printSolution(int ** solution, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<solution[i][j]<<" ";
		}
	}
	cout<<endl;
}

void mazeHelp(int** maze, int n , int** solution, int x, int y){

	if(x==n-1 && y==n-1){
		solution[x][y] = 1;
		printSolution(solution,n);
		solution[x][y] = 0;
		return;
	}

	if(x>=n || x<0 || y>=n ||y<0 || maze[x][y]==0 || solution[x][y]==1){
		return;
	}

	solution[x][y] = 1;
	mazeHelp(maze,n,solution,x-1,y); // checking for up
	mazeHelp(maze,n,solution,x+1,y); // downward moving
	mazeHelp(maze,n,solution,x,y-1); // left
	mazeHelp(maze,n,solution,x,y+1); // right
	solution[x][y] = 0;
}

void ratInMaze(int** maze, int n){

	int** solution = new int*[n];
	for(int i=0;i<n;i++){
		solution[i] = new int[n];
	}

	mazeHelp(maze,n, solution,0,0);

}

int main(){

    int n;
    cin>>n;

    int** maze = new int*[n];
    for(int i=0;i<n;i++){
        maze[i] = new int [n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }

   ratInMaze(maze,n);

}