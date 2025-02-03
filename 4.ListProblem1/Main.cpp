#include <iostream>
#include <list>

using namespace std;

struct Vector2
{
    Vector2(string name, int x, int y)
        : name(name), x(x), y(y)
    {
    }

    string name;
    //int x = 0;
    //int y = 0;
    // 언리얼 스타일 익명 union.
    // Deprecated라서 권장되지 않음.
    union
    {
        struct
        {
            int x;
            int y;
        };
        int xy[2];
    };

    inline int& operator[](int index)
    {
        return xy[index];
    }

    inline int operator[](int index) const
    {
        return xy[index];
    }
};

ostream& operator<<(ostream& os, const Vector2& vector)
{
    //return os << vector.name << " (" << vector.x << ", " << vector.y << ")\n";
    return os << vector.name << " (" << vector[0] << ", " << vector[1] << ")\n";
}

void Print(const list<Vector2>& polygon)
{
    cout << "====== 출력 ======\n";
    for (const Vector2& edge : polygon)
    {
        cout << edge;
    }
    cout << "==== 출력 완료 ====\n";
}

int main()
{
    // 리스트 생성.
    list<Vector2> polygon;
    
    // 점 추가.
    polygon.emplace_back(Vector2("A", 50, 200));
    polygon.emplace_back(Vector2("B", 20, 80));
    polygon.emplace_back(Vector2("C", 75, 10));
    polygon.emplace_back(Vector2("D", 130, 80));
    polygon.emplace_back(Vector2("E", 100, 200));

    // 출력.
    Print(polygon);

    std::cin.get();
}