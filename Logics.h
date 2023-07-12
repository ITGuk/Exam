#pragma once
#include <iostream>
#include <fstream>

#include "Search_logics.h"


using namespace std;

void print_f();
void Search_logic();//add function in Search_Ligics.h
void Sorting();//add function in Search_Ligics.h

struct Product
{
    char name_pos[20];
    char producer_pos[20];
    char group_pos[20];
    char date_pos[20];
    char date_experience_pos[20];
    int price_pos;
}temp;

Product products;

void Add_Product()//add Function
{
    ofstream foo("spisok.dat", ios::app | ios::binary);
    char ch;
    do
    {
        cout << "Enter name product: \n"; cin >> products.name_pos;
        cout << "Enter name producer product: \n"; cin >> products.producer_pos;
        cout << "Enter name group product: \n"; cin >> products.group_pos;
        cout << "Enter date product: \n"; cin >> products.date_pos;
        cout << "Enter date experiense product: \n"; cin >> products.date_experience_pos;
        cout << "Enter price product: \n"; cin >> products.price_pos;

        if (!foo.write((char*)&products, sizeof(Product)))
        {
            cerr << "Error write to file!.\n";
        }
        cout << "Continue ? (y/n)\n"; cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << endl;
    foo.close();
}

void Read_products()//Read function
{
    cout << "\n\n";
    int cont = 1;
    ifstream foo1("spisok.dat", ios::binary);
    while (foo1.read((char*)&products, sizeof(Product)))
    {
        cout << "Product " << cont << endl;
        cout << "Name: " << products.name_pos << endl;
        cout << "Maker: " << products.producer_pos << endl;
        cout << "Group: " << products.group_pos << endl;
        cout << "Date in storage: " << products.date_pos << endl;
        cout << "Date experience product: " << products.date_experience_pos << endl;
        cout << "Price product: " << products.price_pos << "Uah." << endl << endl;
        cont++;
    }

    foo1.close();
}

void Search_Product()//Search function
{
    Search_logic();
}

void Sort_Product()//Sort function
{
    Sorting();

}