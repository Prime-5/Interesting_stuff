#include<iostream>
#include<stdio.h>
using namespace std;
// i j x y m n 
int m=0,n=0,w;
int stack[100];
//int mazeSol[100][100];
int top=-1;
//stackfunctions

void push(int);
void pop();
void display();
bool isEmpty();
//mazefunctions

void createMaze(int,int);
void checkMaze(int[][100],int,int,int);
bool isSafe(int,int);

//stackfunctions
void push(int item)
{
	top++;
	stack[top]=item;
}
void pop()
{
	if(isEmpty())
	{
		cout<<"STACK EMPTY\n";
	}
	else
	{
		w=stack[top];
		top--;
		//cout<<"\n";
		//cout<<w;
		//cout<<"\n";
	}	
}
bool isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void display()
{
	cout<<"*** PATH TRACED ***\n";
	for(int i=0;i<=top;i++)
	{
		
		cout<<stack[i];
		if(i%2!=0)
		cout<<"\n";
	}
}
//mazefunctions
void createMaze(int x1,int y1)
{
	m=x1;
	n=y1;
	push(0);
	push(0);
}

bool isSafe(int x2,int y2)
{
	if(x2>=0&&x2<m&&y2>=0&&y2<n)
	return 1;
	else
	return 0;
}

void checkMaze(int a[][5],int i,int j,int dir)
{
	
	if(i==m-1&&j==n-1)
	{
		cout<<"*** PATH FOUND ***\n";
		display();
	}
	
	else{
	if(dir==0)
	{
		if(a[i][j+1]==0)
		{
			if(isSafe(i,j+1)){
			a[i][j+1]=-1;
			push(i);
			push(j+1);
			checkMaze(a,i,j+1,0);
		}
		else
		{
			checkMaze(a,i,j,1);
		}
		}
		else
		{
			checkMaze(a,i,j,1);
		}
	}
	
	else if(dir==1)
	{
		
		if(a[i+1][j+1]==0)
		{
			if(isSafe(i+1,j+1)){
			a[i+1][j+1]=-1;
			push(i+1);
			push(j+1);
			checkMaze(a,i+1,j+1,0);
		}
		else
		{
			checkMaze(a,i,j,2);
		}
		}
		else
		{
			checkMaze(a,i,j,2);
		}
		
	}
	
	else if(dir==2)
	{
		
		if(a[i+1][j]==0)
		{
			if(isSafe(i+1,j)){
			a[i+1][j]=-1;
			push(i+1);
			push(j);
			checkMaze(a,i+1,j,0);
		}
		else
		{
			checkMaze(a,i,j,3);
		}
	    }
		else
		{
			checkMaze(a,i,j,3);
		}
	}
	
	else if(dir==3)
	{
		
		if(a[i+1][j-1]==0)
		{
			if(isSafe(i+1,j-1)){
			a[i+1][j-1]=-1;
			push(i+1);
			push(j-1);
			checkMaze(a,i+1,j-1,0);
		}
		else
		{
			checkMaze(a,i,j,4);
		}}
		else
		{
			checkMaze(a,i,j,4);
		}
	}
	
	else if(dir==4)
	{
		
		if(a[i][j-1]==0)
		{
			if(isSafe(i,j-1)){
			a[i][j-1]=-1;
			push(i);
			push(j-1);
			checkMaze(a,i,j-1,0);
		}
		else
		{
			checkMaze(a,i,j,5);
		}}
		else
		{
			checkMaze(a,i,j,5);
		}
	}
	
	else if(dir==5)
	{
		
		if(a[i-1][j-1]==0)
		{
			if(isSafe(i-1,j-1)){
			a[i-1][j-1]=-1;
			push(i-1);
			push(j-1);
			checkMaze(a,i-1,j-1,0);
		}
		else
		{
			checkMaze(a,i,j,6);
		}}
		else
		{
			checkMaze(a,i,j,6);
		}
	}
	
	else if(dir==6)
	{
		
		if(a[i-1][j]==0)
		{
			if(isSafe(i-1,j)){
			a[i-1][j]=-1;
			push(i-1);
			push(j);
			checkMaze(a,i-1,j,0);
		}
		else
		{
			checkMaze(a,i,j,7);
		}}
		else
		{
			checkMaze(a,i,j,7);
		}
	}
	
	else if(dir==7)
	{
		if(a[i-1][j+1]==0)
		{
			if(isSafe(i,j)){
			a[i-1][j+1]=-1;
			push(i-1);
			push(j+1);
			checkMaze(a,i-1,j+1,0);
		}}
		else
		{
			if(isEmpty())
			{
				cout<<"Path not found\n";
			}
			else{
			a[stack[top-1]][stack[top]]=1;
			pop();
			pop();
			//cout<<top<<"\n";
			checkMaze(a,stack[top-1],stack[top],0);
		}}
	}
    }
}


int main()
{
	int c,b;
	cout<<"ENTER NUMBER OF ROWS \n";
    cin>>c;
	createMaze(c,5);
	cout<<"ENTER MAZE IN 0 AND 1 FORM. 1 REPRESENTS BLOCKED PATH AND 0 REPRESENTS OPEN PATH\n";
	int maze[c][5];
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>maze[i][j];
		}
	}
	maze[0][0]=-1;
	checkMaze(maze,0,0,0);
	return 0;
}
