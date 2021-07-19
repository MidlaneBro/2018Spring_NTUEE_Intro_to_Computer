#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>

using namespace std;

#define HEAPSIZE 500000

template <class K, class E>
class Node {
    public:
        K key;
        E element;
};

template <class K, class E>
class AbsHeap {

    public:
        AbsHeap() {
            ary = new Node<K,E> [HEAPSIZE];
            size = 0;
        }

        ~AbsHeap() {
            delete[] ary;
        }

        // Remember to ++size
        virtual void push(K _key, E _element) = 0;

        // return the element with the minimum key, remember to --size
        virtual E pop() = 0;

        void printArray() const {
            cout << "(Index, Key, Element)" << endl;
            for (int i=0; i<size; i++)
                cout << "(" << i << "," << ary[i].key << "," << ary[i].element << ")" << endl;
        }

        void printByPopping() {
            while (!isEmpty())
                cout << pop();
            cout << endl;
        }

        K getTopKey() const {
            return ary[0].key;
        }

        bool isEmpty() const {
            return (size == 0);
        }

        // This function is for your convenience
        void swap(int i, int j) {
            Node<K,E> temp = ary[i];
            ary[i] = ary[j];
            ary[j] = temp;
        }

    protected:
        Node<K,E> *ary;
        int size;

};


template <class K, class E>
class Heap: public AbsHeap<K,E> {

    // You need these three lines for template inheritance.
    // Otherwise, you'll have to use this->ary to access ary
    using AbsHeap<K,E>::ary;
    using AbsHeap<K,E>::size;
    using AbsHeap<K,E>::swap;

    /**************************
     * Complete your code here.
     * You need to implement all
     * pure virtual functions (push & pop).
     * ************************/
    public:
    	void push(K _key, E _element){
	    	ary[size].key=_key;
	    	ary[size].element=_element;
	    	int i=size;
	    	while((i!=0)&&(i-1)/2>=0){
	    		if(ary[i].key<ary[(i-1)/2].key){
	    			swap(i,(i-1)/2);
	    			i=(i-1)/2;
				}
				else{
					break;
				} 
			}
	    	++size;
		}
	
		E pop(){
			E root=ary[0].element;
			ary[0].element=ary[size-1].element;
			ary[0].key=ary[size-1].key;
			--size;
			int i=0;
			while((size!=1)&&(i<=(size-2)/2)){
				if((ary[2*i+1].key<=ary[2*i+2].key)&&(ary[i].key>ary[2*i+1].key)){
					swap(i,2*i+1);
					i=2*i+1;
				}
				else if((ary[2*i+1].key>ary[2*i+2].key)&&(ary[i].key>ary[2*i+2].key)){
					swap(i,2*i+2);
					i=2*i+2;
				}
				else{
					break;
				}
			}
			return root;
		}
};


#endif
