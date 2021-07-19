#include <iostream>
#include <fstream>

using namespace std;

//0:opponent(o)
//1:player(AI)(x)
//2:empty(-)

int a[27];//input
int b[9];//transform from a
int c[9];//output

bool win(){//x有活二
	int row,column,diagonal1=0,diagonal2=0;
	for(int i=0;i<3;i++){
		row=0;
		column=0;
		for(int j=0;j<3;j++){
			if(b[j+3*i]==1){
				row++;
			}
		}
		for(int j=0;j<3;j++){
			if(b[i+3*j]==1){
				column++;
			}
		}
		if(row==2){
			for(int j=0;j<3;j++){
				if(b[j+3*i]==2){
					c[j+3*i]=1;
					return true;
				}
			}
		}
		if(column==2){
			for(int j=0;j<3;j++){
				if(b[i+3*j]==2){
					c[i+3*j]=1;
					return true;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		if(b[4*i]==1){
			diagonal1++;
		}
		if(b[2*(i+1)]==1){
			diagonal2++;
		}
	}
	if(diagonal1==2){
		for(int i=0;i<3;i++){
			if(b[4*i]==2){
				c[4*i]=1;
				return true;
			}
		}
	}
	if(diagonal2==2){
		for(int i=0;i<3;i++){
			if(b[2*(i+1)]==2){
				c[2*(i+1)]=1;
				return true;
			}
		}
	}
	return false;
}

bool gonna_lose(){//o有一個活二
	int row,column,diagonal1=0,diagonal2=0;
	for(int i=0;i<3;i++){
		row=0;
		column=0;
		for(int j=0;j<3;j++){
			if(b[j+3*i]==0){
				row++;
			}
		}
		for(int j=0;j<3;j++){
			if(b[i+3*j]==0){
				column++;
			}
		}
		if(row==2){
			for(int j=0;j<3;j++){
				if(b[j+3*i]==2){
					c[j+3*i]=1;
					return true;
				}
			}
		}
		if(column==2){
			for(int j=0;j<3;j++){
				if(b[i+3*j]==2){
					c[i+3*j]=1;
					return true;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		if(b[4*i]==0){
			diagonal1++;
		}
		if(b[2*(i+1)]==0){
			diagonal2++;
		}
	}
	if(diagonal1==2){
		for(int i=0;i<3;i++){
			if(b[4*i]==2){
				c[4*i]=1;
				return true;
			}
		}
	}
	if(diagonal2==2){
		for(int i=0;i<3;i++){
			if(b[2*(i+1)]==2){
				c[2*(i+1)]=1;
				return true;
			}
		}
	}
	return false;
}

void print_input_board(){
	cout<<"input:"<<endl;
	for(int j=0;j<9;j++){
		if(b[j]==0){
			cout<<'o';
		}
		if(b[j]==1){
			cout<<'x';
		}
		if(b[j]==2){
			cout<<'-';
		}
		if(j%3==2){
			cout<<endl;
		}
	}
	cout<<endl;
	system("pause");
}

void print_output_board(){
	cout<<"output:"<<endl;
	for(int j=0;j<9;j++){
		if(c[j]==0){
			cout<<'o';
		}
		if(c[j]==1){
			cout<<'x';
		}
		if(c[j]==2){
			cout<<'-';
		}
		if(j%3==2){
			cout<<endl;
		}
	}
	cout<<endl;
	system("pause");
}

int main(){
	ifstream input("input_x.txt");
	ofstream output("input_y.txt");
	int finished=0,not_finished=0;
	for(int i=0;i<2102;i++){
		for(int j=0;j<27;j++){
			input>>a[j];
		}
		for(int j=0;j<9;j++){
			b[j]=a[3*j]*2+a[3*j+1]*1+a[3*j+2]*0;//transform of input_x
		}
		int sum2=0;//count how many empty remain in b
		for(int j=0;j<9;j++){
			if(b[j]==2){
				sum2++;
			}
		}
		for(int j=0;j<9;j++){//just initialize c
			c[j]=2;
		}
		if(win()){//win immediately
			//print_input_board();
			//print_output_board();
		}
		else if(gonna_lose()){//block the enemy
			//print_input_board();
			//print_output_board();
		}
		else{
			if(sum2==9){//一開始下中間
				c[4]=1;
			}
			else if(sum2==8){
				if(b[4]==2){
					c[4]=1;
				}
				else{
					c[0]=1;
				}
			}
			else if(sum2==7){
				//print_input_board();
				if(b[4]==1){//中間x 
					if(b[0]==0) c[8]=1;
					if(b[2]==0) c[6]=1;
					if(b[6]==0) c[2]=1;
					if(b[8]==0) c[0]=1;
					if(b[1]==0) c[0]=1;
					if(b[3]==0) c[0]=1;
					if(b[5]==0) c[8]=1;
					if(b[7]==0) c[8]=1;
				}
				else{//中間o 
					
				}
				//print_output_board();
			}
		}
		int undone=0;//to check the situations which hasn't been handle
		for(int j=0;j<9;j++){
			if(c[j]==2){
				undone++;
			}
		}
		if(undone==9){
			output<<"undone"<<endl;
			//print_input_board();
			not_finished++;
		}
		else{
			//print_input_board();
			//print_output_board();
			for(int j=0;j<9;j++){
				if(c[j]==0){
					output<<"0 0 1 ";
				}
				if(c[j]==1){
					output<<"0 1 0 ";
				}
				if(c[j]==2){
					output<<"1 0 0 ";
				}
			}
			output<<endl;
			finished++;
		}
	}
	input.close();
	output.close();
	cout<<"finished:"<<finished<<endl;
	cout<<"not_finished:"<<not_finished<<endl;
	return 0;
} 
