#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int a[9]={};

void add(int n){
	if(a[n]>2){
		a[n]=0;
		a[n-1]++;
		add(n-1);
	}
	else{
		return ;
	}
}

bool gameover(){//死局，已經有人贏了 
	for(int i=0;i<3;i++){
		if(a[0+i*3]==a[1+i*3]&&a[1+i*3]==a[2+i*3]&&a[0+i*3]<2){
			return true;
		}
		else if(a[i]==a[i+3]&&a[i+3]==a[i+6]&&a[i]<2){
			return true;
		}
	}
	if(a[0]==a[4]&&a[4]==a[8]&&a[0]<2){
		return true;
	}
	else if(a[2]==a[4]&&a[4]==a[6]&&a[2]<2){
		return true;
	}
	return false;
}

bool opponent_gonna_win(){//圈圈雙二以上但叉叉沒二 
	int circle=0,x=0;
	int row_circle,column_circle,diagonal1_circle=0,diagonal2_circle=0;
	int row_x,column_x,diagonal1_x=0,diagonal2_x=0;
	for(int i=0;i<3;i++){
		row_circle=0;
		column_circle=0;
		row_x=0;
		column_x=0;
		for(int j=0;j<3;j++){
			if(a[j+3*i]==0){
				row_circle++;
			}
			if(a[j+3*i]==1){
				row_x++;
			}
		}
		for(int j=0;j<3;j++){
			if(a[i+3*j]==0){
				column_circle++;
			}
			if(a[i+3*j]==1){
				column_x++;
			}
		}
		if(row_circle==2){
			for(int j=0;j<3;j++){
				if(a[j+3*i]==2){
					circle++;
				}
			}
		}
		if(column_circle==2){
			for(int j=0;j<3;j++){
				if(a[i+3*j]==2){
					circle++;
				}
			}
		}
		if(row_x==2){
			for(int j=0;j<3;j++){
				if(a[j+3*i]==2){
					x++;
				}
			}
		}
		if(column_x==2){
			for(int j=0;j<3;j++){
				if(a[i+3*j]==2){
					x++;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		if(a[4*i]==0){
			diagonal1_circle++;
		}
		if(a[2*(i+1)]==0){
			diagonal2_circle++;
		}
		if(a[4*i]==1){
			diagonal1_x++;
		}
		if(a[2*(i+1)]==1){
			diagonal2_x++;
		}
	}
	if(diagonal1_circle==2){
		for(int i=0;i<3;i++){
			if(a[4*i]==2){
				circle++;
			}
		}
	}
	if(diagonal2_circle==2){
		for(int i=0;i<3;i++){
			if(a[2*(i+1)]==2){
				circle++;
			}
		}
	}
	if(diagonal1_x==2){
		for(int i=0;i<3;i++){
			if(a[4*i]==2){
				x++;
			}
		}
	}
	if(diagonal2_x==2){
		for(int i=0;i<3;i++){
			if(a[2*(i+1)]==2){
				x++;
			}
		}
	}
	if(circle>=2&&x==0){
		return true;
	}
	else{
		return false;
	}
}

void print_board(){
	for(int i=0;i<9;i++){
		if(a[i]==0){
			cout<<'o';
		}
		else if(a[i]==1){
			cout<<'x'; 
		}
		else{
			cout<<'-';
		}
		if(i%3==2){
			cout<<endl;
		}
	}
	system("pause");
}

//empty=100=2(-)
//player(AI)=010=1(x)
//opponent=001=0(o)
 
int main(){
	ofstream file("input_x.txt");
	int sum=0;
	for(int i=0;i<pow(3,9);i++){
		int sum0=0,sum1=0,sum2=0;
		for(int j=0;j<9;j++){
			if(a[j]==0){
				sum0++;
			}
			else if(a[j]==1){
				sum1++;
			}
			else{
				sum2++;
			}
		}
		if(sum1!=sum0){//玩家先手 
			//print_board();
		}
		else if(sum2<=1){//棋盤只剩一個空格 
			//print_board();
		}
		else if(gameover()){//死局 
			//print_board();
		}
		else if(opponent_gonna_win()){//不給將要輸了的trainning data
			//print_board();
		}
		else{
			sum++;
			for(int j=0;j<9;j++){
				if(a[j]==0){
					file<<"0 0 1 ";
				}
				if(a[j]==1){
					file<<"0 1 0 ";
				}
				if(a[j]==2){
					file<<"1 0 0 ";
				}
			}
			file<<endl;
		}
		a[8]++;
		add(8);
	}
	file.close();
	cout<<"total possible:"<<sum<<endl;
	return 0;
} 
