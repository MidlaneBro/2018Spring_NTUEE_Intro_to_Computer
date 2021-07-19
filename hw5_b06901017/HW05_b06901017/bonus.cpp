#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Heap{
	public:
		Heap(){
			ary=new double [1166750];
			size=0;
		}
		~Heap(){
			delete[] ary;
		}
		void push(double key){
			ary[size]=key;
	    	int i=size;
	    	while((i!=0)&&(i-1)/2>=0){
	    		if(ary[i]<ary[(i-1)/2]){
	    			swap(i,(i-1)/2);
	    			i=(i-1)/2;
				}
				else{
					break;
				} 
			}
	    	++size;
		}
		double pop(){
			double root=ary[0];
			ary[0]=ary[size-1];
			--size;
			int i=0;
			while((size!=1)&&(i<=(size-2)/2)){
				if((ary[2*i+1]<=ary[2*i+2])&&(ary[i]>ary[2*i+1])){
					swap(i,2*i+1);
					i=2*i+1;
				}
				else if((ary[2*i+1]>ary[2*i+2])&&(ary[i]>ary[2*i+2])){
					swap(i,2*i+2);
					i=2*i+2;
				}
				else{
					break;
				}
			}
			return root;
		}
		void printArray() const {
            cout << "(Index, Key)" << endl;
            for (int i=0; i<size; i++)
                cout << "(" << i << "," << ary[i] <<  ")" << endl;
        }
        void getByPopping(double* p) {
        	int i=0;
            while (size!=0){
            	p[i]=pop();
                i++;
			}
        }
        void swap(int i, int j) {
            double temp = ary[i];
            ary[i] = ary[j];
            ary[j] = temp;
        }
	private:
		double *ary;
		int size;
};

int main()
{

    Heap heapA,heapB;

    ifstream file("bonus.txt");

    int n;
    file >> n;
    double *key = new double [n];

    for (int i=0; i<n; ++i) {
        file >> key[i];
        heapA.push(key[i]);
    }
    for (int i=0; i<n; ++i) {
        file >> key[i];
        heapB.push(key[i]);
    }

    file.close();
    
    delete [] key;
    
	double *a = new double [n];
	double *b = new double [n];
	
    heapA.getByPopping(a);
    heapB.getByPopping(b);
    
    Heap heapC;
    vector<double> c;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n/(i+1);j++){
			c.push_back(a[i]+b[j]);
		}
	}
	
	delete[] a;
	delete[] b;
	
	for(int i=0;i<c.size();i++){
		heapC.push(c[i]);
	}
	
	double *answer = new double [c.size()];
	
	heapC.getByPopping(answer);
	
	ofstream output("bouns_out");
	for(int i=0;i<n;i++){
		output << answer[i] <<" ";
	}
	
	delete[] answer;

    return 0;
}


