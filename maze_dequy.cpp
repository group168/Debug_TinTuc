
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
#define Max 100

int n,m;
int maze[Max][Max];
int mark[Max][Max];
int exitRow = m-2;
int exitCol = n-2;
struct element{
	int row;
	int col;
	int dir;
};

struct stack{
	int top;
	element list[Max];
};

struct offsets{
	int x;
	int y;
};
offsets move[8];
void initMove(offsets move[]){
	move[0].x = -1;
	move[0].y = 0;
	
	move[1].x = -1;
	move[1].y = 1;
	
	move[2].x = 0;
	move[2].y = 1;
	
	move[3].x = 1;
	move[3].y = 1;
	
	move[4].x = 1;
	move[4].y = 0;
	
	move[5].x = 1;
	move[5].y = -1;
	
	move[6].x = 0;
	move[6].y = -1;
	
	move[7].x = -1;
	move[7].y = -1;
}

void initStack(stack &s){
	s.top = -1;
}

void push(stack &s,element a){
	s.top++;
	s.list[s.top] = a;
}

element pop(stack &s){
	element a = s.list[s.top];
	s.top--;
	return a;
}

void initMaze(char fileName[], int maze[][Max]){
	std:ifstream file(fileName);
	string line;
	int row = 1;
	int col = 1;
	if(!file){
		cout<<"file maze is not found!!!";
		return;
	}
	while(getline(file,line)){
		int i = 0;
		col = 1;
		while(i < line.length()){
			if(line[i]!= ' '){
				string c = "";
				c+= line[i];
				maze[row][col] = atoi(c.c_str());
				col++;
			}
			i++;
		}
		row++;
	}
	m = row + 1;
	n = col + 1;
	for(int i = 0 ; i < m ; i ++){
		for(int j = 0; j <n ; j++){
			if(i == 0 || i == m-1 || j == 0 ||j == n-1){
				maze[i][j]=1;
			}
		}
	}
	file.close();
}

void outMatrix(int maze[][Max]){
	for(int i = 0; i< m; i++){
		for(int j = 0; j < n ; j++){
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}
/*/
void path(int row, int column, int maze[][])
{
}
/*/
int path(int row, int col, int maze[][Max]){
	
	int  nextRow, nextCol;// found = false;
	element position;
	int exitRow = m-2;
	int exitCol = n-2;
	mark[row][col] = 1;
	stack s;
	element x;
	x.col = 1;
	x.row = 1;
	x.dir = 1;
	push(s,x);
    int dir;
	while(dir<8 )
	{
		nextRow = row + move[dir].x;
		nextCol = col + move[dir].y;
		if(nextRow == exitRow && nextCol == exitCol)
			{
			printf("maze[%d][%d]", row, col);
			mark[nextRow][nextCol] = 1;
			return 1;
			}
		else if(maze[nextRow][nextCol] == 0 && mark[nextRow][nextCol] == 0)
			{
			//goi ham de quy vao vi tri tiep theo
				path(nextRow, nextCol, maze);
				dir = 0;
			
			//kh dung de quy	
//			mark[nextRow][nextCol]=1;
//			path(nextRow,nextCol,maze);
//			mark[nextRow][nextCol]=0;
			}
		dir++;
	}
	return 0;
}

int main(){
	
int maze[Max][Max];
	
	
	string a = "100";
	stack s;
	initStack(s);
	offsets move[8];
	int mark[m][n];
	for(int i = 0 ; i< m ;i ++){
		for(int j = 0 ; j < n ; j++){
			mark[i][j] = 0;
		}
	}
	initMaze("maze.txt",maze);
	initMove(move);
	outMatrix(maze);
	cout<<endl;
	if (path(1,1,maze)==1) 
	{
	printf("Timf thay duong di:\n");
}
}

