// Map (Key, Value).
#include <iostream>
#include <string>
#include <map>
#include <Windows.h>

// 구조체.
struct Item
{
    std::string name;
    unsigned int kind = 0;
    int price = 0;
    int code = 0;
};

// 출력을 위한 연산자 오버로딩.
std::ostream& operator<<(std::ostream& os, const Item& item)
{
    return os << "이름: " << item.name << ", 가격: " << item.price << ", 코드: " << item.code;
}

bool Comparer(const std::string& str1, const std::string& str2)
{
    return str1 < str2;
}

template <class T = void>
struct TComparer
{
    bool operator()(const T& str1, const T& str2) const
    {
        return str1 < str2;
    }
};

// less, greater 참고한 코드.
template <>
struct TComparer<void> {
    template <class T1, class T2>
    constexpr auto operator()(T1&& _Left, T2&& _Right) const
        noexcept(noexcept(static_cast<T1&&>(_Left) < static_cast<T2&&>(_Right))) // strengthened
        -> decltype(static_cast<T1&&>(_Left) < static_cast<T2&&>(_Right)) {
        return static_cast<T1&&>(_Left) < static_cast<T2&&>(_Right);
    }

    using is_transparent = int;
};

int main()
{
    // 맵 생성.
    std::map<std::string, Item, TComparer<>> items;
    //std::map<std::string, Item, TComparer<std::string>> items;
    //std::map<std::string, Item, bool(*)(const std::string&, const std::string&)> items(Comparer);
    //std::map<std::string, Item, std::greater<std::string>> items;
    //std::map < std::string, Item, std::less<std::string>> items;

    // 데이터 추가.
    items.insert({ "장검", { "장검", 1, 200, 0 } });
    items.insert({ "해머", { "해머", 1, 1000, 4 } });
    items.insert({ "방패", { "방패", 2, 5000, 3 } });

    // 개수 확인 및 출력.
    if (!items.empty())
    {
        std::cout << "저장된 아이템 수: " << items.size() << "\n";
    }

    // 출력.
    for (auto& pair : items)
    {
        std::cout << pair.second << "\n";
    }

    // 검색.
    auto it = items.find("해머");
    if (it != items.end())
    {
        std::cout << "해머 아이템이 있습니다. 해머의 가격은 " << it->second.price << "입니다.\n";
    }

    // 삭제
    if (it != items.end())
    {
        items.erase(it);

        std::cout << "해머 아이템 삭제 후 출력\n";

        for (auto& pair : items)
        {
            std::cout << pair.second << "\n";
        }
    }

    std::cin.get();
}