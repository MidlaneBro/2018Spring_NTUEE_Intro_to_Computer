#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/************************************
*  Note that in general using global
*  variables is a bad habit.
*  I use globals here because I don't 
*  want to scare you with "double***"
*************************************/

int m;
int n;
double **v;  // n*(m+1) 2D-array
double **h;  // (n+1)*m 2D-array

// For internal use only. Do not really use them directly
double *real_v;
double *real_h;

double total_cost;
vector<char> path;

void readParameters()
{
    ifstream ifs("input3", ifstream::binary);

    ifs.read((char*)&m, sizeof(int));
    ifs.read((char*)&n, sizeof(int));
	
	
    real_v = new double[n*(m+1)];
    real_h = new double[(n+1)*m];

    ifs.read((char*)real_v, sizeof(double)*n*(m+1));
    ifs.read((char*)real_h, sizeof(double)*(n+1)*m);

    v = new double*[n];
    for (int i=0; i<n; ++i){
        v[i] = &(real_v[i*(m+1)]);
		
	}
    h = new double*[n+1];
    for (int i=0; i<n+1; ++i){
        h[i] = &(real_h[i*m]);
	}

    ifs.close();
	
	
}

void release()
{

    delete []v;
    delete []h;

    delete []real_v;
    delete []real_h;
}

void print(){
	cout<<"grid size:"<<m<<"x"<<n<<endl;
    cout<<"vertical side"<<endl;
    for(int i=0;i<n;i++){
    	for(int j=0;j<=m;j++){
    		cout<<v[i][j]<<" "; 
		}
		cout<<endl;
	}
	cout<<"horizontal size"<<endl;
	for(int i=0;i<=n;i++){
    	for(int j=0;j<m;j++){
    		cout<<h[i][j]<<" "; 
		}
		cout<<endl;
	}
}

void dynamic_programming(){
	int x=0,y=0;//initial node(x is veritcal and y is horizontal)
	bool map[n+1][m+1];//node that hasn't be walked
	char route[n+1][m+1];//how to walk to this node from the last one
	double value[n+1][m+1];//the minimum cost from initial node to this node
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			map[i][j]=0;
			route[i][j]='o';
			value[i][j]=0;
		}
	}
	while(x!=n||y!=m){//reach final node
		bool direction[4]={1,1,1,1};//which path is available(up,down,left,right)
		if(map[x-1][y]==1){//up path is unavailable
			direction[0]=0;
		}
		if(map[x+1][y]==1){//down path is unavailable
			direction[1]=0;
		}
		if(map[x][y-1]==1){//left path is unavailable
			direction[2]=0;
		}
		if(map[x][y+1]==1){//right path is unavailable
			direction[3]=0;
		}
		if(x==0){//upmost edge
			direction[0]=0;
			if(y==0){//leftmost edge
				direction[2]=0;
			}
			if(y==m){//rightmost edge
				direction[3]=0;
			}
		}
		if(x==n){//downmost dege
			direction[1]=0;
			if(y==0){//leftmost edge
				direction[2]=0;
			}
			if(y==m){//rightmost edge
				direction[3]=0;
			}
		}
		if(x!=0&&x!=n){
			if(y==0){//leftmost edge
				direction[2]=0;
			}
			if(y==m){//rightmost edge
				direction[3]=0;
			}
		} 
		if(direction[0]){//up path is available
			if(value[x-1][y]==0||value[x-1][y]>value[x][y]+v[x-1][y]){
				route[x-1][y]='u';
				value[x-1][y]=value[x][y]+v[x-1][y];
			}
		}
		if(direction[1]){//down path is available
			if(value[x+1][y]==0||value[x+1][y]>value[x][y]+v[x][y]){
				route[x+1][y]='d';
				value[x+1][y]=value[x][y]+v[x][y];
			}
		}
		if(direction[2]){//left path is available
			if(value[x][y-1]==0||value[x][y-1]>value[x][y]+h[x][y-1]){
				route[x][y-1]='l';
				value[x][y-1]=value[x][y]+h[x][y-1];
			}
		}
		if(direction[3]){//right path is available
			if(value[x][y+1]==0||value[x][y+1]>value[x][y]+h[x][y]){
				route[x][y+1]='r';
				value[x][y+1]=value[x][y]+h[x][y];
			}
		}
		map[x][y]=1;//delete this point
		double shortest;
		bool flag=true;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(map[i][j]==0&&value[i][j]!=0){
					if(flag==true){
						shortest=value[i][j];
						x=i;
						y=j;
						flag=false;
					}
					else{
						if(value[i][j]<shortest){
							shortest=value[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}//find the minimum value of all availabe node in order to decide the next node to consider	
	}
	total_cost=value[x][y];//get the total cost of the shortest path
	while(x!=0||y!=0){
		path.insert(path.begin(),route[x][y]);
		if(route[x][y]=='u'){
			x++;
		}
		else if(route[x][y]=='d'){
			x--;
		}
		else if(route[x][y]=='l'){
			y++;
		}
		else if(route[x][y]=='r'){
			y--;
		}
	}//trace back from final node in order to find the route
}

void output(){
	ofstream file("result.txt");
	file<<total_cost<<endl;
	for(int i=0;i<path.size();i++){
		file<<path[i];
	}
	file.close();
}

int main()
{
    readParameters();
    dynamic_programming();
    release();
    output();
    return 0;
}

