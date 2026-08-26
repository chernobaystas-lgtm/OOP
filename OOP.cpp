#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;

#define T 20

class book_of_phones {

	public:
		inline void EditInfo(int choice);
        // --- Конструктор по умолчанию ---
        book_of_phones() : Phone_number(0) {
            strcpy_s(Name, T, "No name");
            strcpy_s(Second_name, T, "No second name");
            strcpy_s(Last_name, T, "No last name");

            additional_info = new char[T];
            strcpy_s(additional_info, T, "No additional info");
        }

        book_of_phones(const book_of_phones& other)
            : Phone_number(other.Phone_number)
        {
            strcpy_s(Name, T, other.Name);
            strcpy_s(Second_name, T, other.Second_name);
            strcpy_s(Last_name, T, other.Last_name);

            additional_info = new char[strlen(other.additional_info) + 1];
            strcpy_s(additional_info, strlen(other.additional_info) + 1, other.additional_info);
        }


        // --- Деструктор ---
        ~book_of_phones() {
            delete[] additional_info;
            additional_info = nullptr;
        }

		inline void Get_info() {
            cout << "Введіть ім'я: ";
            cin.getline(Name, T);
			cout << "Name: " << Name << endl;
            cout << "Введітьпрізвище: ";
            cin.getline(Second_name, T);
			cout << "Second name: " << Second_name << endl;
            cout << "Введіть по батькові: ";
            cin.getline(Last_name, T);
			cout << "Last name: " << Last_name << endl;
            cout << "Введіть номер телефону: ";
            cin >> Phone_number;
			cout << "Phone number: " << Phone_number << endl;
            cout << "Введіть додаткову інформацію: ";
            cin.getline(additional_info, T);
			cout << "Additional info: " << additional_info << endl;
		}

		inline  void Set_info(const char* name, const char* second_name, const char* last_name, int phone_number, const char* additional_info_str) {
			strncpy_s(Name, T, name, T - 1);
			strncpy_s(Second_name, T, second_name, T - 1);
			strncpy_s(Last_name, T, last_name, T - 1);
			Phone_number = phone_number;
			delete[] additional_info; // Free the old memory
			additional_info = new char[strlen(additional_info_str) + 1];
			strcpy_s(additional_info, strlen(additional_info_str) + 1, additional_info_str);
		}

	private:
		char Name[T]{"No name"};
		char Second_name[T]{"No second name"};
		char Last_name[T]{"No last name"};
		int Phone_number{ 0 };
		char* additional_info{ nullptr };
};

void book_of_phones::EditInfo(int choice) {
    switch (choice) {
    case 1:
        cout << "Введіть нове ім'я: ";
        cin.getline(Name, T);
        break;
    case 2:
        cout << "Введіть нове прізвище: ";
        cin.getline(Second_name, T);
        break;
    case 3:
        cout << "Введіть нове по батькові: ";
        cin.getline(Last_name, T);
        break;
    case 4:
        cout << "Введіть новий номер телефону: ";
        cin >> Phone_number;
        cin.ignore();
        break;
    case 5:
        cout << "Введіть нову додаткову інформацію: ";
        {
            char temp[T];
            cin.getline(temp, T);
            delete[] additional_info; // звільняємо стару пам'ять
            additional_info = new char[strlen(temp) + 1];
            strcpy_s(additional_info, strlen(temp) + 1, temp);
        }
        break;
    default:
        cout << "Невірний вибір!" << endl;
        break;
    }
}


int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	book_of_phones phone1;
    phone1.Get_info();
    int choice;
    cout << "Що хочете змінити?\n"
        << "1 - Ім'я\n"
        << "2 - Прізвище\n"
        << "3 - По батькові\n"
        << "4 - Телефон\n"
        << "5 - Додаткова інформація\n"
        << "Ваш вибір: ";
    cin >> choice;
    cin.ignore();
    phone1.EditInfo(choice);

}


