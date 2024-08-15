#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int sku = 45678;
    char desc[] = "Sleeping Bags";
    int qty = 100;
    int qtyNeed = 200;
    double price = 65.66;
    int count = 35;

    cout << "##### | AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA | #### | #### | ####.## |" << endl;
    //copy from here
    cout << sku << " | ";
    for (int i = 0; i < 35; i++)
    {
        if (desc[i] != '\0')
            cout << desc[i];
        else
            cout << ' ';
    }
    cout << " | ";

    return 0;
}