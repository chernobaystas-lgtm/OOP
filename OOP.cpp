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
	int annotation{ 0 };


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

};





int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);





    return 0;


}


