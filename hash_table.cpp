//Consider an employee database of N employees. Make use of a hash table implementation toquickly look up the employee‟s id number.
//murtuza kapasi

#include <iostream>
#include <iomanip>
using namespace std;
struct employee
{
    int id;
    string name;
};

class hashTable
{
    int id, key, count = 1;
    string name;
    employee e[10];

public:
    hashTable()
    {
        for (int i = 0; i < 10; i++)
        {
            e[i].name = "----";
            e[i].id = -1;
            key = 0;
        }
        for (int i = 2; i < 9; i++)
        {
            e[i].id = i;
            count++;
        }
    }
    void insert();
    void display();
    void collision();
    int hkey(int);
    int search();
    void delet();
};

void hashTable::insert()
{
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    key = hkey(id);
    if (count > 10)
    {
        cout << "Hash table is full!!\n";
        return;
    }

ins:
    if (e[key].id == -1)
    {
        e[key].name = name;
        e[key].id = id;
        count++;
        return;
    }
    else
    {
        cout << "Collision\n";
        // continue;
        // i=i+1;
        key++;
        if (key > 9)
            key = 0;
        goto ins;
    }
}

void hashTable::display()
{
    cout << setw(10) << "ID" << setw(10) << "Name" << setw(10) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << e[i].id << setw(10) << e[i].name << setw(10) << endl;
    }
}

int hashTable::hkey(int id)
{
    id = id % 10;
    return id;
}

int hashTable::search()
{
    int flag = 0;
    cout << "Enter search id: ";
    cin >> id;
    key = hkey(id);
    for (int i = key; i != key - 1; i++)
    {
        if (e[i].id == id)
        {
            cout << "Data found!\n";
            cout << setw(10) << "Name" << setw(10) << "ID" << setw(10) << endl;
            cout << e[i].name << setw(10) << e[i].id << setw(10) << endl;
            flag = 1;
            return i;
            return 0;
        }
        else if (i > 9)
            i = -1;
    }
    if (e[key - 1].id == id)
    {
        cout << "Data found!\n";
        cout << setw(10) << "Name" << setw(10) << "ID" << setw(10) << endl;
        cout << e[key - 1].name << setw(10) << e[key - 1].id << setw(10) << endl;
        flag = 1;
        return key - 1;
        return 0;
    }
    if (flag == 0)
    {
        cout << "data not found!\n";
        return -1;
    }
}

void hashTable::delet()
{
    int pos = search();
    if (pos == -1)
        return;
    e[pos].id = -1;
    e[pos].name = "-----";
    cout << "Record deleted successfully!\n";
}
int main()
{
    int c;
    hashTable h;
    while (1)
    {
        cout << "1.Insert data    2.Display   3.Search record     4.Delete record\n";
        cout << "Entr ur choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.display();
            break;
        case 3:
            h.search();
            break;
        case 4:
            h.delet();
            break;
        default:
            return 0;
        }
    }
}
