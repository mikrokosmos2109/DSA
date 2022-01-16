/* Rat In A Maze Problem
Send Feedback
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.

Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1
 */


/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/

#include<bits/stdc++.h>
using namespace std;

void printMtrx(int** arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}
void ratInAMaze(int** arr, int n, int** sol, int r, int c){
    if(r == n-1 && c == n-1){
        sol[r][c] = 1;
        printMtrx(sol, n);
        sol[r][c] = 0;
        return;
    }
    if(r < 0 || r >= n || c < 0 || c >= n || sol[r][c] == 1 || arr[r][c] == 0){
        return;
    }
    sol[r][c] = 1;
    ratInAMaze(arr, n, sol, r-1, c);
    ratInAMaze(arr, n, sol, r+1, c);
    ratInAMaze(arr, n, sol, r, c-1);
    ratInAMaze(arr, n, sol, r, c+1);
    sol[r][c] = 0;
}

int main(){
    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0; i <n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    int** sol = new int*[n];
    
    for(int i=0; i<n; i++){
        sol[i] = new int[n];
        for(int j=0; j<n; j++){
            sol[i][j] = 0;
        }
    }
    
    ratInAMaze(arr, n, sol, 0, 0);
    
    for(int i=0; i<n; i++){
        delete [] arr[i];
        delete [] sol[i];
    }
    
    delete [] arr;
    delete [] sol;

    return 0;
}
