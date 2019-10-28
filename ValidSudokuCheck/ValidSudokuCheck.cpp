//This program checks wether the sudoku entered is a valid sudoku(solvable) or not.
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<char>> board){
	//printing the sudoku
	for(auto it=board.begin();it!=board.end();it++){
		for(auto ij=(*it).begin();ij!=(*it).end();ij++){
			printf("%c ",*ij);
		}
		printf("\n");	
	}
}

bool isValidSudoku(vector<vector<char>>& board) {
	//checking for row
	//check for unique numbers 
	for(auto it=board.begin();it!=board.end();it++){
		set<char> s;
		for(auto ij=(*it).begin();ij!=(*it).end();ij++){
			if(*ij!='.'){
				//finding unique numbers(represented as characters here) 
				if(s.find(*ij)==s.end()){
				s.insert(*ij);
			}
			else
				return false;
			}
		}
	}
	//checking for column
	//check for unique numbers
	for(int i=0;i<9;i++){//9X9 dimension
		set<char> s;
		for(int j=0;j<9;j++){
			if(board[j][i]!='.'){
				//finding unique numbers(represented as characters here)
				if(s.find(board[j][i])==s.end()){
					s.insert(board[j][i]);
				}
				else
					return false;
			}
		}
	}
	//checking for sub-boxes
	//check for unique numbers
	for(int x=0;x<9;x=x+3){
		for(int i=0;i<9;i=i+3){
			set<char> s;
			for(int j=x;j<x+3;j++){
				for(int k=i;k<i+3;k++){
					//finding unique numbers(represented as characters here)
					if(board[j][k]!='.'){
						if(s.find(board[j][k])==s.end()){
							s.insert(board[j][k]);
						}
						else
							return false;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	cout<<"black spaces represented as '.'\n";
	vector<vector<char>> a{
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}};
	
	print(a);
	
	if(isValidSudoku(a))
		cout<<"It's a valid one"<<endl;
	else
		cout<<"It's a invalid sudoku\n";
	
	vector<vector<char>> b{
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','9','9'}};
	
	print(b);
	
	if(isValidSudoku(b))
		cout<<"It's a valid one"<<endl;
	else
		cout<<"It's an invalid sudoku\n";

	return 0;
}
