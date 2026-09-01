#include "Menu.h"
#include "Class.h"
#include "File.h"

void SaveToTextFile(const ReservoirArray& arr, const char* filename) {
    ofstream file(filename);
    if (!file) { cout << "Помилка відкриття файлу\n"; return; }
    for (int i = 0; i < arr.GetCount(); ++i) file << const_cast<ReservoirArray&>(arr)[i];
    file.close();
}

void SaveToBinaryFile(const ReservoirArray& arr, const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file) { cout << "Помилка відкриття файлу\n"; return; }
    for (int i = 0; i < arr.GetCount(); ++i) {
        Reservoir& r = const_cast<ReservoirArray&>(arr)[i];
        int nameLen = (int)strlen(r.GetName()) + 1;
        file.write(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        file.write(r.GetName(), nameLen);

        ReservoirType t = r.GetType();
        file.write(reinterpret_cast<char*>(&t), sizeof(t));

        double w = r.GetWidth(), l = r.GetLength(), d = r.GetDepth();
        file.write(reinterpret_cast<char*>(&w), sizeof(w));
        file.write(reinterpret_cast<char*>(&l), sizeof(l));
        file.write(reinterpret_cast<char*>(&d), sizeof(d));

        bool marine = r.IsMarine(), fish = r.HasFish(), priv = r.IsPrivate();
        file.write(reinterpret_cast<char*>(&marine), sizeof(marine));
        file.write(reinterpret_cast<char*>(&fish), sizeof(fish));
        file.write(reinterpret_cast<char*>(&priv), sizeof(priv));
    }
    file.close();
}