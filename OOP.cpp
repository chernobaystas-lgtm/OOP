#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

#define T 30

class student {


public:
	int IS_Student(const char* name_of_study_place) {
		if (name_of_study_place == nullptr || strcmp(name_of_study_place, "Don't study at any place") == 0) {
			cerr << "Помилка: студент не навчається ніде!" << endl;
			return 0;
		}
		cout << "Це студент" << endl;
		return 1;
	}

    void InputInfo();
    void ShowInfo() const;


    // --- Геттери ---
    inline const char* Get_Name_of_study_place() const;
    inline const char* Get_name() const;
    inline const char* Get_surname() const;
    inline const char* Get_lastName() const;
    inline int Get_date_of_birth() const;
    inline int Get_phone() const;
    inline const char* Get_native_city() const;
    inline const char* Get_native_country() const;
    inline int Get_number_of_the_group() const;

    // --- Сеттери ---
    inline int Set_Name_of_study_place(const char* Name_of_study_place);
    inline int Set_name(const char* name);
    inline int Set_surname(const char* surname);
    inline int Set_lastName(const char* lastName);
    inline int Set_date_of_birth(int date_of_birth);
    inline int Set_phone(int phone);
    inline int Set_native_city(const char* native_city);
    inline int Set_native_country(const char* native_country);
    inline int Set_number_of_the_group(int number_of_the_group);
    

private:
    char Name_of_study_place[T]{ "Don't study at any place" };
    char name[T]{ "No name" };
    char surname[T]{ "No surname" };
    char lastName[T]{ "No last name" };
    int date_of_birth{ 0 };
    int phone{ 0 };
    char native_city[T]{ "Without native city" };
    char native_country[T]{ "Without native country" };
    int number_of_the_group{ 0 };

};


// --- Реалізація геттерів ---
const char* student::Get_Name_of_study_place() const { return Name_of_study_place; }
const char* student::Get_name() const { return name; }
const char* student::Get_surname() const { return surname; }
const char* student::Get_lastName() const { return lastName; }
int student::Get_date_of_birth() const { return date_of_birth; }
int student::Get_phone() const { return phone; }
const char* student::Get_native_city() const { return native_city; }
const char* student::Get_native_country() const { return native_country; }
int student::Get_number_of_the_group() const { return number_of_the_group; }

// --- Реалізація сеттерів ---
int student::Set_Name_of_study_place(const char* Name_of_study_place) {
    strcpy_s(this->Name_of_study_place, Name_of_study_place);
    return 0;
}
int student::Set_name(const char* name) {
    strcpy_s(this->name, name);
    return 0;
}
int student::Set_surname(const char* surname) {
    strcpy_s(this->surname, surname);
    return 0;
}
int student::Set_lastName(const char* lastName) {
    strcpy_s(this->lastName, lastName);
    return 0;
}
int student::Set_date_of_birth(int date_of_birth) {
    this->date_of_birth = date_of_birth;
    return 0;
}
int student::Set_phone(int phone) {
    this->phone = phone;
    return 0;
}
int student::Set_native_city(const char* native_city) {
    strcpy_s(this->native_city, native_city);
    return 0;
}
int student::Set_native_country(const char* native_country) {
    strcpy_s(this->native_country, native_country);
    return 0;
}
int student::Set_number_of_the_group(int number_of_the_group) {
    this->number_of_the_group = number_of_the_group;
    return 0;
}



void student::InputInfo() {
    cout << "Введіть ім'я: ";
    cin.getline(name, T);

    cout << "Введіть прізвище: ";
    cin.getline(surname, T);

    cout << "Введіть по батькові: ";
    cin.getline(lastName, T);

    cout << "Введіть дату народження (рік): ";
    cin >> date_of_birth;

    cout << "Введіть номер телефону: ";
    cin >> phone;
    cin.ignore();

    cout << "Введіть місто: ";
    cin.getline(native_city, T);

    cout << "Введіть країну: ";
    cin.getline(native_country, T);

    cout << "Введіть навчальний заклад: ";
    cin.getline(Name_of_study_place, T);

    cout << "Введіть номер групи: ";
    cin >> number_of_the_group;
    cin.ignore();

    cout << "\n Дані успішно введено!\n";
}

void student::ShowInfo() const {
    cout << "\n--- Інформація про студента ---\n";
    cout << "Ім'я: " << name << endl;
    cout << "Прізвище: " << surname << endl;
    cout << "По батькові: " << lastName << endl;
    cout << "Дата народження: " << date_of_birth << endl;
    cout << "Телефон: " << phone << endl;
    cout << "Місто: " << native_city << endl;
    cout << "Країна: " << native_country << endl;
    cout << "Навчальний заклад: " << Name_of_study_place << endl;
    cout << "Номер групи: " << number_of_the_group << endl;
}

int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    student s;
    s.InputInfo();
    s.ShowInfo();


	s.IS_Student(s.Get_Name_of_study_place());
    return 0;


}


