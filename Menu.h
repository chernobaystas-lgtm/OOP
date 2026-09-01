#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

#define T 100


enum class ReservoirType { Sea, Pool, Pond, Lake, River };

inline const char* TypeToStr(ReservoirType t) {
    switch (t) {
    case ReservoirType::Sea:  return "Море";
    case ReservoirType::Pool: return "Басейн";
    case ReservoirType::Pond: return "Ставок";
    case ReservoirType::Lake: return "Озеро";
    case ReservoirType::River:return "Річка";
    }
    return "Невідомо";
}

inline  ReservoirType ChooseTypeMenu() {
    cout << "Оберіть тип водойми:\n";
    cout << "1 - Море\n2 - Басейн\n3 - Ставок\n4 - Озеро\n5 - Річка\nВибір: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: return ReservoirType::Sea;
    case 2: return ReservoirType::Pool;
    case 3: return ReservoirType::Pond;
    case 4: return ReservoirType::Lake;
    case 5: return ReservoirType::River;
    default: return ReservoirType::Pond;
    }
}