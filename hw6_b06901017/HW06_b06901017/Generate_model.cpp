#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
	ofstream file("model.txt");
	int hidden_node_amount=17;
	for(int i=0;i<hidden_node_amount;i++){
		file<<i+36<<" ";
	}
	file<<endl;
	for(int i=0;i<27;i++){
		file<<i<<" ";
		file<<i/3+36<<" ";
		if(i%3==0){
			file<<-pow(10,100);
		}
		if(i%3==1){
			file<<pow(10,100);
		}
		if(i%3==2){
			file<<log(3);
		}
		file<<endl;
	}
	
	for(int i=0;i<9;i++){
		file<<i+36<<" ";
		file<<i/3+45<<" ";
		file<<1<<endl;
	}
	for(int i=0;i<3;i++){
		file<<36+i<<" "<<48+i<<" "<<1<<endl;
		file<<39+i<<" "<<48+i<<" "<<1<<endl;
		file<<42+i<<" "<<48+i<<" "<<1<<endl;
	}
	for(int i=0;i<2;i++){
		file<<36+2*i<<" "<<51+i<<" "<<1<<endl;
		file<<40<<" "<<51+i<<" "<<1<<endl;
		file<<44-2*i<<" "<<51+i<<" "<<1<<endl; 
	}
	
	file<<45<<" "<<27<<" "<<1<<endl;
	file<<48<<" "<<27<<" "<<1<<endl;
	file<<51<<" "<<27<<" "<<1<<endl;
	
	file<<45<<" "<<28<<" "<<1<<endl;
	file<<49<<" "<<28<<" "<<1<<endl;
	
	file<<45<<" "<<29<<" "<<1<<endl;
	file<<50<<" "<<29<<" "<<1<<endl;
	file<<52<<" "<<29<<" "<<1<<endl;
	
	file<<46<<" "<<30<<" "<<1<<endl;
	file<<48<<" "<<30<<" "<<1<<endl;
	
	file<<46<<" "<<31<<" "<<1<<endl;
	file<<49<<" "<<31<<" "<<1<<endl;
	file<<51<<" "<<31<<" "<<1<<endl;
	file<<52<<" "<<31<<" "<<1<<endl;
	
	file<<46<<" "<<32<<" "<<1<<endl;
	file<<50<<" "<<32<<" "<<1<<endl;
	
	file<<47<<" "<<33<<" "<<1<<endl;
	file<<48<<" "<<33<<" "<<1<<endl;
	file<<52<<" "<<33<<" "<<1<<endl;
	
	file<<47<<" "<<34<<" "<<1<<endl;
	file<<49<<" "<<34<<" "<<1<<endl;
	
	file<<47<<" "<<35<<" "<<1<<endl;
	file<<50<<" "<<35<<" "<<1<<endl;
	file<<51<<" "<<35<<" "<<1<<endl;
	
	file.close();
	return 0;
} 
