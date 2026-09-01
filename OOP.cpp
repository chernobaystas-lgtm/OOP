#include "Menu.h"
#include "File.h"




int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ReservoirArray arr;
    arr.Add(Reservoir("Чорне море", ReservoirType::Sea, 500, 800, 2, true, true, false));
    arr.Add(Reservoir("Ставок біля дому", ReservoirType::Pond, 10, 15, 2, false, true, true));

    arr.ShowAll();

    cout << "\nПорівняння площ (та сама група): "
        << (arr[0].SameType(arr[1]) ? "однакова група\n" : "різна група, порівняння некоректне\n");

    cout << "\nХочете зберегти дані у файл? (1-так, 0-ні): ";
    int saveChoice;
    cin >> saveChoice;

    if (saveChoice == 1) {
        cout << "1 - текстовий\n2 - бінарний\n3 - обидва\nВибір: ";
        int fileType;
        cin >> fileType;
        if (fileType == 1 || fileType == 3) { SaveToTextFile(arr, "reservoirs.txt"); cout << "Текстовий збережено\n"; }
        if (fileType == 2 || fileType == 3) { SaveToBinaryFile(arr, "reservoirs.dat"); cout << "Бінарний збережено\n"; }
    }

    return 0;
}
