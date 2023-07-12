#include "Search_logics.h"
#include "Logics.h"


using namespace std;

int main()
{
    int check;
    cout << "\tStorage\n\t\t1-Add new product in storage.\n\t\t2-Show all products." <<
        "\n\t\t3-Search product.\n\t\t4-Sort product.\n\t";
    //Too choise
    cin >> check;
    if (check == 1)
    {
        Add_Product();
    }
    if (check == 2)
    {
        Read_products();
    }
    if (check == 3)
    {
        Search_Product();
    }
    if (check == 4)
    {
        Sort_Product();
    }

}