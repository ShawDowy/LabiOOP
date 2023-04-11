#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Type
{
    artistic,
    technical
};

class  Book
{
public:
    Book(const string& name_, const string& author_, const Type& type_)
        :name(name_), author(author_), type(type_)
    {}

    Type get_Type() const
    {
        return type;
    }

private:
    const string name;
    const string author;
    const Type type;


};

class Library
{
public:
    Library(){}

    void add_book(const string& name_, const string& author_, const Type& type_)
    {
        if (name_.empty() or author_.empty())
        {
            throw invalid_argument("invalid");
        }

        library_.emplace_back(name_, author_, type_);
    }

    int books_count(Type type_)
    {
        int count = 0;
        for (const Book& book : library_)
        {
            if (book.get_Type() == type_)
            {
                count++;
            }
        }
        return count;
    }

    void output_without_switch()
    {
        int art_count = books_count(Type::artistic);
        int tech_count = books_count(Type::technical);

        cout << "Without switch" << endl;
        cout << "Artistic: " << art_count << endl;
        cout << "Technical: " << tech_count << endl;

        return;
    }

    void output_switch()
    {
        int tech_count = 0;
        int art_count = 0;

        for (const Book& book : library_)
        {
            switch (book.get_Type())
            {
            case Type::technical:
                tech_count++;
                break;
            case Type::artistic:
                art_count++;
                break;
            }
        }

        cout << "Using switch" << endl;
        cout << "Artistic: " << art_count << endl;
        cout << "Technical: " << tech_count << endl;

        return;
    }

private:
    vector<Book> library_;
};


int main()
{
    Library arr;
    try
    {
        arr.add_book("Sth Mathmetical", "Fon Neiman", Type::technical);
    }
    catch (const invalid_argument& ex)
    {
        cout << ex.what() << endl;
    }

    try
    {
        arr.add_book("Oleg IV", "Chernishevskiy", Type::artistic);
    }
    catch (const invalid_argument& ex)
    {
        cout << ex.what() << endl;
    }

    try
    {
        arr.add_book("What to do", "Chernishevskiy", Type::artistic);
    }
    catch (const invalid_argument& ex)
    {
        cout << ex.what() << endl;
    }

    try
    {
        arr.add_book("Osvoy_samostoytelino_C++_po_odnomu_chasu_v_den", "Siddhartha_Rao", Type::technical);
    }
    catch (const invalid_argument& ex)
    {
        cout << ex.what() << endl;
    }




    arr.output_switch();
    arr.output_without_switch();

    return 0;
}