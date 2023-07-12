#pragma once
#include "Logics.h"

using namespace std;

void print_f()
{
    cout << "Name: " << products.name_pos << endl;
    cout << "Maker: " << products.producer_pos << endl;
    cout << "Group: " << products.group_pos << endl;
    cout << "Date in storage: " << products.date_pos << endl;
    cout << "Date experience product: " << products.date_experience_pos << endl;
    cout << "Price product: " << products.price_pos << "Uah." << endl << endl;
}

void Search_logic()
{

    ifstream foo2("spisok.dat", ios::binary);

    string search_product;

    cout << "\n\tProduct search:\n\t\t1-Name.\n\t\t2-Manufacturer.\n\t\t3-Price.\n\t\t4-Product group.\n\t\t5-Date of arrival at the warehouse.\n\t\t6-Expiration date.\n\n";

    int check_1;
    cin >> check_1;

    if (check_1 == 1)
    {
        cout << "Enter the name of the product you are looking for: \n";
        cin >> search_product;
        while (foo2.read((char*)&products, sizeof(Product)))
        {
            if (products.name_pos == search_product)
            {
                print_f();
            }
        }
    }
    if (check_1 == 2)
    {
        cout << "Enter the manufacturer of the product you are looking for: \n";
        cin >> search_product;
        while (foo2.read((char*)&products, sizeof(Product)))
        {
            if (products.producer_pos == search_product)
            {
                print_f();
            }
        }
    }
    if (check_1 == 3)
    {
        cout << "Enter the group of the product you are looking for: \n";
        cin >> search_product;
        while (foo2.read((char*)&products, sizeof(Product)))
        {
            if (products.group_pos == search_product)
            {
                print_f();
            }
        }
    }
    if (check_1 == 4)
    {
        cout << "Enter the date of arrival at the warehouse of the product you are looking for: \n";
        cin >> search_product;
        while (foo2.read((char*)&products, sizeof(Product)))
        {
            if (products.date_pos == search_product)
            {
                print_f();
            }
        }
    }
    if (check_1 == 5)
    {
        cout << "Enter the expiration date of the product you are looking for: \n";
        cin >> search_product;
        while (foo2.read((char*)&products, sizeof(Product)))
        {
            if (products.date_experience_pos == search_product)
            {
                print_f();
            }
        }
    }
    if (check_1 == 6)
    {
        cout << "Enter the price of the product you are looking for: \n";
        int search_price;
        cin >> search_price;
        while (foo2.read((char*)&products, sizeof(Product)))
        {
            if (products.price_pos == search_price)
            {
                print_f();
            }
        }
    }
    foo2.close();
}

void Sorting()
{
    ifstream foo3("spisok.dat", ios::binary);

    foo3.seekg(0, ios::end);
    int size = foo3.tellg();
    size = size / sizeof(Product);
    foo3.seekg(0, ios::beg);

    Product* products = new Product[size];

    foo3.read((char*)products, size * sizeof(Product));
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i; ++j)
        {
            if (products[i].price_pos > products[i + 1].price_pos)
            {
                temp = products[i];
                products[i] = products[i + 1];
                products[i + 1] = temp;
                //booble sort=)
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << products[i].name_pos << endl;
        cout << "Maker: " << products[i].producer_pos << endl;
        cout << "Group: " << products[i].group_pos << endl;
        cout << "Date in storage: " << products[i].date_pos << endl;
        cout << "Date experience product: " << products[i].date_experience_pos << endl;
        cout << "Price product: " << products[i].price_pos << "Uah." << endl << endl;
    }

    foo3.close();
}