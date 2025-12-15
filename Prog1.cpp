#include <iostream>

using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;

public:
    void setTitle(string t)
    {
        title = t;
    }

    void setAuthor(string a)
    {
        author = a;
    }

    void setDueDate(string d)
    {
        dueDate = d;
    }

    string getTitle()
    {
        return title;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string i)
    {
        title = t;
        author = a;
        dueDate = d;
        isbn = i;
    }

    void checkOut()
    {
        cout << "Book checked out" << endl;
    }

    void returnItem()
    {
        cout << "Book returned" << endl;
    }

    void displayDetails()
    {
        cout << endl << "Book Title: " << title;
        cout << endl << "Author: " << author;
        cout << endl << "Due Date: " << dueDate;
        cout << endl << "ISBN: " << isbn << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
    {
        title = t;
        author = a;
        dueDate = d;
        duration = dur;
    }

    void checkOut()
    {
        cout << "DVD checked out" << endl;
    }

    void returnItem()
    {
        cout << "DVD returned" << endl;
    }

    void displayDetails()
    {
        cout << endl << "DVD Title: " << title;
        cout << endl << "Director: " << author;
        cout << endl << "Due Date: " << dueDate;
        cout << endl << "Duration: " << duration << " minutes" << endl;
    }
};

int main()
{
    LibraryItem *items[5];
    int count = 0;
    int choice;

    do
    {
        cout << endl << "1. Add Book";
        cout << endl << "2. Add DVD";
        cout << endl << "3. Show Items";
        cout << endl << "4. Check Out";
        cout << endl << "5. Return Item";
        cout << endl << "0. Exit";
        cout << endl << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            string t, a, d, i;
            cout << "Title: ";
            cin >> t;
            cout << "Author: ";
            cin >> a;
            cout << "Due Date: ";
            cin >> d;
            cout << "ISBN: ";
            cin >> i;

            items[count++] = new Book(t, a, d, i);
            break;
        }

        case 2:
        {
            string t, a, d;
            int dur;

            cout << "Title: ";
            cin >> t;
            cout << "Director: ";
            cin >> a;
            cout << "Due Date: ";
            cin >> d;
            cout << "Duration: ";
            cin >> dur;

            items[count++] = new DVD(t, a, d, dur);
            break;
        }

        case 3:
            for (int i = 0; i < count; i++)
                items[i]->displayDetails();
            break;

        case 4:
        {
            int n;
            cout << "Enter index: ";
            cin >> n;
            items[n]->checkOut();
            break;
        }

        case 5:
        {
            int n;
            cout << "Enter index: ";
            cin >> n;
            items[n]->returnItem();
            break;
        }

        case 0:
            for (int i = 0; i < count; i++)
                delete items[i];
            cout << "Program exited" << endl;
            break;

        default:
            cout << "Wrong choice" << endl;
        }

    } while (choice != 0);

    return 0;
}