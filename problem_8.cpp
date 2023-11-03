#include <iostream>
using namespace std;

void pattern( int left, int length )
{
   if ( length == 0 )  return;

   pattern( left, length / 2 );                            // "Half pattern" above

   for ( int i = 0; i < left  ; i++ ) cout << "  ";
   for ( int i = 0; i < length; i++ ) cout << "* ";        // Central string
   cout << endl;

   pattern( left + length / 2, length / 2 );               // "Half pattern" below
}

int main()
{
   int n;
   cout << "Enter n (a power of 2): ";   cin >> n;
   pattern(0,n);
}