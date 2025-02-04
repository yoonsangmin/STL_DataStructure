// 덱 사용을 위한 헤더 인클루드.
#include <deque>
#include <iostream>

int main()
{
    // 덱 선언.
    std::deque<int> deque;

    // 데이터 추가.
    deque.emplace_back(100);
    deque.emplace_front(200);

    // 출력.
    for (int ix = 0; ix < deque.size(); ++ix)
    {
        std::cout << deque[ix] << "\n";
    }
    std::cout << '\n';

    // 출력.
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
    {
        std::cout << *it << "\n";
    }
    std::cout << '\n';

    // 출력 Ranged Loop.
    // int는 레퍼런스로 받아도 주소는 복사가 일어나므로 이점이 없음.
    for (auto& value : deque)
    {
        std::cout << value << "\n";
    }
    std::cout << '\n';

    // 데이터 추출 후 제거.
    auto data = deque.back();
    deque.pop_back();

    std::cout << data << "\n";

    deque.clear();
    // 비었는지 확인.
    if (deque.empty())
    {
        std::cout << "덱이 비었습니다.\n";
    }

    std::cin.get();
}