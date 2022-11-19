/*
author : santanukgp
problem:https://codeforces.com/problemset/problem/{ProblemSet}/{ProblemNumber}
*/
#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<char>> v){
	string endline_pattern = "\n------------\n";
	cout<< "------------\n";
	for(auto i: v){
		for(char c: i){
			cout<<" "<<c<<" |";
		}
		cout<< endline_pattern;
	}
}
bool formLogic(char c){
	if(c=='o' || c=='x')
		return true;
	
	return false;
}
bool boundaryLogic(int r,int c){
	if(r>=1 && r<=3 && c<=3 && c>=1)
		return true;
	return false;
}
bool logic(vector<vector<char>> v){

	if(v[0][0]==v[1][1] && v[1][1]==v[2][2] && formLogic(v[0][0])) 
		return true;
	if(v[0][2]==v[1][1] && v[1][1]==v[2][0])
		return true;
	for(int i=0;i<3;i++){
		if(v[i][0] == v[i][1] && v[i][1] == v[i][2] && formLogic(v[i][0]))
			return true;
		if(v[0][i] == v[1][i] && v[1][i] == v[2][i] && formLogic(v[0][i]))
			return true;
	}
	
	return false;
	
}
void game_session(){
	vector<vector<char>> game={{'.','.','.'},
								{'.','.','.'},
								{'.','.','.'}
	};
	print(game);
	for(int i=0;i<9;i++){
		
		cout<<"It's turn for player "<<(i%2+1)<<"\n";
		
		int row, col;
		
		cout<<"Place row number[1-3] and column number[1-3]: ";
		cin>> row>> col;
		cout<<"\n";
		
		if(boundaryLogic(row,col) && game[row-1][col-1]=='.' )
			game[row-1][col-1]= (i%2) ? 'x':'o';
		else{
			while(true){
				cout<<"Place row number[1-3] and column number[1-3] again: ";
				cin>> row>> col;
				cout<<"\n";
				if(boundaryLogic(row,col) && game[row-1][col-1]=='.' ){
					game[row-1][col-1]= (i%2) ? 'x':'o';
					break;
				}	
			}
		}
		
		print(game);
		
		if(logic(game)){
			cout<<"==========================\n";
			cout<<"          Result\n";
			cout<<"==========================\n";
			cout<<"Player "<<(i%2+1)<<" wins!!\n";
			cout<<"==========================\n";
			return ;
		}	
	}
	cout<<"==========================\n";
	cout<<"          Result\n";
	cout<<"==========================\n";
	cout<<"Match is draw!!\n";
	cout<<"==========================\n";
}
int main(){
	
	string confirm = "yes";
	while(confirm=="yes" || confirm=="y"){
		game_session();
		cout<<"Do you want to play again?\n";
		cin>>confirm;
	}
	return 0;
}
