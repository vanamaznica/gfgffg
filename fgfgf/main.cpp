#include <iostream>
#include <cstring>
using namespace std;

struct Book
{
    char name[100];
    char author[100];
    char publisher[100];
    char genre[100];
};

int main()
{
    Book b[10], temp;
    int choice, n;

    for (int i = 0; i < 10; i++)
    {
        cin.ignore(i == 0 ? 0 : 1);
        cout << "name: ";
        cin.getline(b[i].name, 100);
        cout << "author: ";
        cin.getline(b[i].author, 100);
        cout << "publisher: ";
        cin.getline(b[i].publisher, 100);
        cout << "genre: ";
        cin.getline(b[i].genre, 100);
    }

    do
    {
        cout << "1. Show\n2. Search author\n3. Search name\n";
        cout << "4. Edit\n5. Sort name\n6. Sort author\n7. Sort publisher\n0. Exit\n";
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < 10; i++)
                cout << b[i].name << " " << b[i].author << " "
                << b[i].publisher << " " << b[i].genre << endl;
        }

        if (choice == 2 || choice == 3)
        {
            char s[100];
            cin.ignore();
            cout << "enter text: ";
            cin.getline(s, 100);

            for (int i = 0; i < 10; i++)
                if ((choice == 2 && strcmp(b[i].author, s) == 0) ||
                    (choice == 3 && strcmp(b[i].name, s) == 0))
                    cout << b[i].name << " " << b[i].author << " "
                    << b[i].publisher << " " << b[i].genre << endl;
        }

        if (choice == 4)
        {
            cout << "Book number: ";
            cin >> n;
            cin.ignore();

            if (n >= 1 && n <= 10)
            {
                n--;
                n--;
                cout << "name: ";
                cin.getline(b[n].name, 100);
                cout << "author: ";
                cin.getline(b[n].author, 100);
                cout << "publisher: ";
                cin.getline(b[n].publisher, 100);
                cout << "genre: ";
                cin.getline(b[n].genre, 100);
            }
        }

        if (choice >= 5 && choice <= 7)
        {
            for (int i = 0; i < 9; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    char* x = choice == 5 ? b[i].name :
                        choice == 6 ? b[i].author : b[i].publisher;
                    char* y = choice == 5 ? b[j].name :
                        choice == 6 ? b[j].author : b[j].publisher;

                    if (strcmp(x, y) > 0)
                    {
                        temp = b[i];
                        b[i] = b[j];
                        b[j] = temp;
                    }
                }
        }
    } while (choice != 0);
}
