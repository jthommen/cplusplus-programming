#include "../std_lib_facilities.h"

int main()
{
    constexpr double jpy_to_usd = 0.0091;
    constexpr double sek_to_usd = 0.113;
    constexpr double chf_to_usd = 1.01;

    double amount = 1;

    string currency = " ";

    cout<< "JPY, SEK & CHF to USD converter.\n"
        << "Please enter an amount followed by a currency (JPY, SEK or CHF):\n";
    cin>> amount >> currency;

    if(currency == "JPY" || currency == "jpy")
        cout<< amount << "JPY == " << jpy_to_usd*amount << "USD\n";
    else if(currency == "SEK" || currency == "sek")
        cout<< amount << "SEK == " << sek_to_usd*amount << "USD\n";
    else if(currency == "CHF" || currency == "chf")
        cout<< amount << "CHF == " << chf_to_usd*amount << "USD\n";
    else
        cout<< "Sorry, I don't know a currency called " << currency << endl;

    return 0;
}
