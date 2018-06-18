#include "../std_lib_facilities.h"

int main()
{
    cout<< "Enter the name of the person you want to write to (followed by 'enter'):\n";
    string first_name;
    cin >> first_name;
    
    cout<< "Enter the age of the person you want to write to:\n";
    int age;
    cin >> age;

    cout<< "Enter the name of a friend (followed by 'enter'):\n";
    string friend_name;
    cin >> friend_name;

    cout<< "What sex is the friend? (type f for female or m for male):\n";
    char friend_sex;
    cin >> friend_sex;
    
    cout<< "Dear, " << first_name << "!\n";
    cout<< "How are you? I am fine. "
        << "I miss you.\n"
        << "Have you seen " << friend_name << " lately?\n";
    if(friend_sex == 'm')
        cout<< "If you see " << friend_name << " please ask him to call me.\n";
    if(friend_sex == 'f')
        cout << "If you see " << friend_name << " please ask her to call me\n.";
    cout<< "I hear you just had a birthday and you are " << age << " years old.\n";
    if(age < -1 || age > 110)
        simple_error("you're kidding!");
    if(age < 12)
        cout<< "Next year you will be " << age+1 << '\n';
    if(age == 17)
        cout<< "Next year you will be able to vote.\n";
    if(age > 70)
        cout<< "I hope you are enjoying retirement.\n";
    cout<< "Yours sincerely,\n\n\nJuri\n";
}