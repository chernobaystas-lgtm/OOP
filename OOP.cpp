#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

#define T 30

struct Date {
	int day;
	int month;
	int year;

	void input() {
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
	}

	void output() {
		cout << day << "/" << month << "/" << year;
	}
};

class Entity {
protected:
	static void copy_field2(char*& dst, const char* src) {
		delete[] dst;
		dst = new char[T];
		if (src != nullptr) {
			strcpy_s(dst, T, src);
		}
		else {
			dst[0] = '\0';
		}
	}
};

class book : public Entity {
private:
	char* author{ nullptr };
	char* title{ nullptr };
	char* publishing{ nullptr };
	char* annotation{ nullptr };
	Date year{ 0, 0, 0 };
	int counter{ 0 };
	int pages{ 0 };


public:

	book() : year{ 0, 0, 0 }, counter(0), pages(0) {
		copy_field2(author, "Unknown author");
		copy_field2(title, "No title");
		copy_field2(publishing, "Unknown publishing");
		copy_field2(annotation, "No annotation");
	}

    explicit book(const char* a, const char* t) : year{ 0, 0, 0 }, counter(0), pages(0) {
        copy_field2(author, a);
        copy_field2(title, t);
        copy_field2(publishing, "Unknown publishing");
        copy_field2(annotation, "No annotation");
    }

    book(const char* a, const char* t, const char* p, Date y, int c, int pg, const char* ann)
        : year(y), counter(c), pages(pg) {
        copy_field2(author, a);
        copy_field2(title, t);
        copy_field2(publishing, p);
        copy_field2(annotation, ann);
    }

    ~book() {
        delete[] author;
        delete[] title;
        delete[] publishing;
        delete[] annotation;
    }

    book(const book& other) : year(other.year), counter(other.counter), pages(other.pages) {
        copy_field2(author, other.author);
        copy_field2(title, other.title);
        copy_field2(publishing, other.publishing);
        copy_field2(annotation, other.annotation);
    }

    book& operator=(const book& other) {
        if (this == &other) return *this;
        year = other.year;
        counter = other.counter;
        pages = other.pages;
        copy_field2(author, other.author);
        copy_field2(title, other.title);
        copy_field2(publishing, other.publishing);
        copy_field2(annotation, other.annotation);
        return *this;
    }

    void input() {
        cout << "Введіть автора: ";
        cin.getline(author, T);
        cout << "Введіть назву: ";
        cin.getline(title, T);
        cout << "Введіть видавництво: ";
        cin.getline(publishing, T);
        cout << "Введіть рік видання:\n";
        year.input();
        cout << "Введіть кількість: ";
        cin >> counter;
        cout << "Введіть кількість сторінок: ";
        cin >> pages;
        cin.ignore();
        cout << "Введіть анотацію: ";
        cin.getline(annotation, T);
    }

    void output() const {
        cout << "\n--- Інформація про книгу ---\n";
        cout << "Автор: " << author << endl;
        cout << "Назва: " << title << endl;
        cout << "Видавництво: " << publishing << endl;
        cout << "Рік видання: ";
        const_cast<Date&>(year).output();
        cout << endl;
        cout << "Кількість: " << counter << endl;
        cout << "Сторінок: " << pages << endl;
        cout << "Анотація: " << annotation << endl;
    }

    // --- Геттери, потрібні для пошуку ---
    const char* getAuthor() const { return author; }
    const char* getPublishing() const { return publishing; }
    int getYear() const { return year.year; }

    friend istream& operator>>(istream& in, book& b);
    friend ostream& operator<<(ostream& out, const book& b);



};

istream& operator>>(istream& in, book& b) {
    cout << "Введіть автора: ";
    in.getline(b.author, T);

    cout << "Введіть назву: ";
    in.getline(b.title, T);

    cout << "Введіть видавництво: ";
    in.getline(b.publishing, T);

    cout << "Введіть рік видання:\n";
    b.year.input();

    cout << "Введіть кількість: ";
    in >> b.counter;

    cout << "Введіть кількість сторінок: ";
    in >> b.pages;
    in.ignore();

    cout << "Введіть анотацію: ";
    in.getline(b.annotation, T);

    return in;
}

ostream& operator<<(ostream& out, const book& b) {
    out << "\n--- Інформація про книгу ---\n";
    out << "Автор: " << b.author << endl;
    out << "Назва: " << b.title << endl;
    out << "Видавництво: " << b.publishing << endl;
    out << "Рік видання: ";
    const_cast<Date&>(b.year).output();
    out << endl;
    out << "Кількість: " << b.counter << endl;
    out << "Сторінок: " << b.pages << endl;
    out << "Анотація: " << b.annotation << endl;
    return out;
}

void showByAuthor(book* books, int size, const char* targetAuthor) {
    cout << "\n--- Книги автора " << targetAuthor << " ---\n";
    for (int i = 0; i < size; ++i) {
        if (_stricmp(books[i].getAuthor(), targetAuthor) == 0) {
            cout << books[i];
        }
    }
}

void showByPublishing(book* books, int size, const char* targetPublishing) {
    cout << "\n--- Книги видавництва " << targetPublishing << " ---\n";
    for (int i = 0; i < size; ++i) {
        if (_stricmp(books[i].getPublishing(), targetPublishing) == 0) {
            cout << books[i];
        }
    }
}

void showByYearAfter(book* books, int size, int targetYear) {
    cout << "\n--- Книги, випущені після " << targetYear << " ---\n";
    for (int i = 0; i < size; ++i) {
        if (books[i].getYear() > targetYear) {
            cout << books[i];
        }
    }
}



int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    book b1("Tolstoy", "War and Peace");
    cout << b1;

	cout << "\nВведіть дані для другої книги:\n";


    book books[3] = {
        book("Tolstoy", "War and Peace"),
        book("Dostoevsky", "Crime and Punishment"),
        book("Pushkin", "Eugene Onegin")
    };
    int N = 3;

    showByAuthor(books, N, "Tolstoy");
    showByPublishing(books, N, "Unknown publishing");
    showByYearAfter(books, N, 2000);

    return 0;


}


