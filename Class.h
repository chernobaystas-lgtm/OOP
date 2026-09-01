#pragma once
#include "Menu.h"

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

class Reservoir : public Entity {
private:
    char* name{ nullptr };
    ReservoirType type{ ReservoirType::Pond };
    double width{ 0 };
    double length{ 0 };
    double depth{ 0 };
    bool isMarine{ false };
    bool hasFish{ false };
    bool isPrivate{ false };

public:
    Reservoir() {
        copy_field2(name, "No name");
    }

    explicit Reservoir(const char* n, ReservoirType t) : type(t) {
        copy_field2(name, n);
    }

    Reservoir(const char* n, ReservoirType t, double w, double l, double d,
        bool marine, bool fish, bool priv)
        : type(t), width(w), length(l), depth(d),
        isMarine(marine), hasFish(fish), isPrivate(priv) {
        copy_field2(name, n);
    }

    ~Reservoir() {
        delete[] name;
    }

    Reservoir(const Reservoir& other)
        : type(other.type), width(other.width), length(other.length), depth(other.depth),
        isMarine(other.isMarine), hasFish(other.hasFish), isPrivate(other.isPrivate) {
        copy_field2(name, other.name);
    }

    Reservoir& operator=(const Reservoir& other) {
        if (this == &other) return *this;
        type = other.type;
        width = other.width;
        length = other.length;
        depth = other.depth;
        isMarine = other.isMarine;
        hasFish = other.hasFish;
        isPrivate = other.isPrivate;
        copy_field2(name, other.name);
        return *this;
    }

    double GetVolume() const { return width * length * depth; }
    double GetArea() const { return width * length; }

    bool SameType(const Reservoir& other) const { return type == other.type; }
    bool HasLargerArea(const Reservoir& other) const { return GetArea() > other.GetArea(); }

    const char* GetName() const { return name; }
    ReservoirType GetType() const { return type; }
    double GetWidth() const { return width; }
    double GetLength() const { return length; }
    double GetDepth() const { return depth; }
    bool IsMarine() const { return isMarine; }
    bool HasFish() const { return hasFish; }
    bool IsPrivate() const { return isPrivate; }

    void SetName(const char* n) { copy_field2(name, n); }
    void SetType(ReservoirType t) { type = t; }
    void SetWidth(double w) { width = w; }
    void SetLength(double l) { length = l; }
    void SetDepth(double d) { depth = d; }
    void SetMarine(bool m) { isMarine = m; }
    void SetFish(bool f) { hasFish = f; }
    void SetPrivate(bool p) { isPrivate = p; }

    friend istream& operator>>(istream& in, Reservoir& r);
    friend ostream& operator<<(ostream& out, const Reservoir& r);
};

inline istream& operator>>(istream& in, Reservoir& r) {
    char buf[T];
    cout << "Введіть назву водойми: ";
    in.ignore();
    in.getline(buf, T);
    r.SetName(buf);

    r.type = ChooseTypeMenu();

    cout << "Введіть ширину: ";
    in >> r.width;
    cout << "Введіть довжину: ";
    in >> r.length;
    cout << "Введіть максимальну глибину: ";
    in >> r.depth;

    cout << "Морська водойма? (1-так, 0-ні): ";
    int m; in >> m; r.isMarine = (m == 1);

    cout << "Чи водиться риба? (1-так, 0-ні): ";
    int f; in >> f; r.hasFish = (f == 1);

    cout << "Приватна водойма? (1-так, 0-ні): ";
    int p; in >> p; r.isPrivate = (p == 1);

    return in;
}

inline ostream& operator<<(ostream& out, const Reservoir& r) {
    out << "\n--- Водойма ---\n";
    out << "Назва: " << r.name << endl;
    out << "Тип: " << TypeToStr(r.type) << endl;
    out << "Ширина: " << r.width << ", Довжина: " << r.length << ", Глибина: " << r.depth << endl;
    out << "Обсяг: " << r.GetVolume() << endl;
    out << "Площа поверхні: " << r.GetArea() << endl;
    out << "Морська: " << (r.isMarine ? "так" : "ні") << endl;
    out << "Риба: " << (r.hasFish ? "так" : "ні") << endl;
    out << "Приватна: " << (r.isPrivate ? "так" : "ні") << endl;
    return out;
}

class ReservoirArray {
private:
    Reservoir* data{ nullptr };
    int count{ 0 };
    int capacity{ 0 };

public:
    ReservoirArray() {}
    ~ReservoirArray() { delete[] data; }

    void Add(const Reservoir& r) {
        if (count == capacity) {
            int newCap = (capacity == 0) ? 2 : capacity * 2;
            Reservoir* newData = new Reservoir[newCap];
            for (int i = 0; i < count; ++i) newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCap;
        }
        data[count++] = r;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= count) return;
        for (int i = index; i < count - 1; ++i) data[i] = data[i + 1];
        --count;
    }

    int GetCount() const { return count; }
    Reservoir& operator[](int i) { return data[i]; }

    void ShowAll() const {
        for (int i = 0; i < count; ++i) cout << data[i];
    }
};