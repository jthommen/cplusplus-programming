#include "../std_lib_facilities.h"

int main() 
{
    cout << "Please enter an integer value: ";
    int n;
    cin >> n;
    cout<< "n == " << n
        << "\nn+1 == " << n+1
        << "\nthree times n == " << n*3
        << "\ntwice n == " << n+n
        << "\nn squared == " << n*n
        << "\nn half of n == " << n/2
        << "\nn divided by n/2 == " << n/(n/2)
        << "\nreminder of n divided by n/2 == " << n%(n/2);
    double f = n;
    cout<< "\nsquare root of n == " << sqrt(f)
        << '\n';
}
