#include <iostream>

using namespace std;

double fastPower( int x, int n, int k, int & multiplications);

int main()
{
    int base = 20 ;
    int k = 21;
    int exponent = 1023;

        int m = 0;
        cout << "fastPower( " << base << ", " << exponent << ") = "
        << fastPower(base, exponent, k, m);
        cout << " done with " << m << " multiplications";

    
    return 0;
}

double fastPower( int x, int n, int k, int & multiplications){
    
    x = x % k;
    //------ return values for special cases ----------
    if( x==0 || x==1 || n==1 ) // no calculation here
        return x;
    
    if( n==0 ) // no calculation here
        return 1;
    
    if( n < 0 ) {// negative exponent means reciproca
        multiplications++;
        return( 1 / fastPower( x, -n,x+1, multiplications));}
    
    //-------- powering done here ---------
    if ( n%2 == 0 ) // n is even
    {
        multiplications++;
        double temp = fastPower( x , n/2 ,x+1, multiplications);
        return temp * temp;
    }
    else {// n is odd
        multiplications++;
        return x * fastPower( x, n-1 ,x+1, multiplications);
    }
}
