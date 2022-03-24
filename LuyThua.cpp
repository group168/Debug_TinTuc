
#include <iostream>

using namespace std;

int pow(int x,int n){
    if(n == 0)
        return 1;
    if(n % 2 != 0)
        return x * pow(x,n - 1);
        
    int st = pow(x, n/2);
    return st * st;
}

int main()
{
    int n,x;
    cout <<"Nhap vao so x : ";
    cin >> x;
    cout <<"Nhap vao so mu n: ";
    cin >> n;
    int kq = pow(x,n);
    //cout <<"Ket qua x^n = " << kq;
    cout <<"Ket qua " << x <<"^" << n <<" = " <<kq;

    return 0;
}