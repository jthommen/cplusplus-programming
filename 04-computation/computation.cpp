#include "../std_lib_facilities.h"

int main() 
{
    // constants for unit conversion
    constexpr double cm_in_m = 0.01;
    constexpr double in_in_cm = 2.54;
    constexpr double ft_in_in = 12;

    // variables are initialized
    double number = 0;
    string unit = "";
    double largest = 0;
    double smallest = 0;
    double sum = 0;
    int input = 0;
    Vector<double> input_numbers;

    // welcome message
    cout << "Write a number followed by a unit.\n";
    cout << "Separate the number and the unit with a space.\n";
    cout << "Valid units are: cm, m, in, ft.\n";

    // Loop stays alive as long as there is input
    while(cin>>number>>unit)
    {
        cout << endl;
        //cout << "Number: " << number << " Unit: " << unit << endl;

        if(unit == "cm" || unit == "m" || unit == "in" || unit == "ft") {

            if(unit == "cm") number *= cm_in_m;
            if(unit == "in") number = number * in_in_cm * cm_in_m;
            if(unit == "ft") number = number * ft_in_in * in_in_cm * cm_in_m;

            if(input == 0) 
            {
                largest = number;
                smallest = number;
            }
            else if(largest < number) largest = number;
            if(smallest > number) smallest = number;

            ++input;
            sum += number;
            input_numbers.push_back(number);

            cout << "The number is: " << number << "m\n";
            cout << "The largest number is: " << largest << "m\n";
            cout << "The smallest number is: " << smallest << "m\n";
            cout << "Number of values: " << input << endl;
            cout << "Sum of values: " << sum << "m\n\n";

            sort(input_numbers);
            cout << "Sorted values: \n";
            for(double number: input_numbers) cout << number << "m\n";
            cout << "------------------\n";
            cout << endl;

        } else {
            cout << "Valid units are cm, m, in or ft only!\n";
        }
        
    }
}
