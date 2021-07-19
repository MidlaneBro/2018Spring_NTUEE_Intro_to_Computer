maxsum(L,M):-
	m(L,M,H). %need one more variable to get the answer(L is the given list, M is the maximum subarray of total list(the answer), while H records the sum of continuous positive subarray.)
m([],0,0). %base case
m([A|L1],M,H):- %[A|L1] will seperate the first element from the list
	m(L1,M1,H1), %recursive
	B is H1+A, %B represents that right side continuous positive subarray plus a left side element
	H is max(B,0), %if B goes to negative, then reset value of H. Otherwise, H becomes B. 
	M is max(M1,H). %M is albe to record when H reaches maximum value.
