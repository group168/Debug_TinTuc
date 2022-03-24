/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) {
    
    return min(min(x, y), z); 
 
}

int editDist(string str1, string str2, int m, int n){
	// d(0,j)
	if (m == 0)
		return n;

	// d(i,0)
	if (n == 0)
		return m;

	// d(i,j)
	if (str1[m - 1] == str2[n - 1])
		return editDist(str1, str2, m - 1, n - 1);

	
	return 1+ min ( editDist(str1, str2, m, n - 1), // chèn thêm
				editDist(str1, str2, m - 1, n), // Xoá
				editDist(str1, str2, m - 1,
						n - 1) // Thay thế
			);
}


int main(){
    string X, Y;
    cout <<"Nhap vao chuoi X: ";
    cin >> X;
    cout <<"Nhap vao chuoi Y: ";
    cin >> Y;
    int n = X.length(), m = Y.length();
	cout << "Tong cac phep bien doi :" << editDist( X, Y, n, m );

	return 0;
}

