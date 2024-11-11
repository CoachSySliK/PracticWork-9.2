#include <iostream>
#include <string>

using namespace std;

int main()
{
    string number;
    enter: //начало
    cout << "Enter the number: ";
    cin >> number;
    cin.ignore(100, '\n');

    bool point = false;

    if (!(number[0] >= 45 && number[0] != 47 && number[0] <= 57)) {
        if (number[0] == 46) point = true;
        cout << "Error 1 in 1 symbol\n";
        goto enter;
    }
    
    for (int i = 1; number.length() > i; i++) {
        if (number[i] == 46 && point == true) {
            cout << "Error 2 in " << ++i << " symbol\n";
            goto enter;
        }
        if (number[i] == 46 && point == false) {
            point = true;
        }
        if (!((number[i] - 48) >= 0 && (number[i] - 48) <= 9 || number[i] == 46)) {
            cout << "Error 3 in " << ++i << " symbol\n";
            goto enter;
        }
    }

    cout << "The number is right\n";

    return 0;//я не знаю, все ли возможные варианты я протестировал. вручную очень напрягает, перебирать варианты
}

