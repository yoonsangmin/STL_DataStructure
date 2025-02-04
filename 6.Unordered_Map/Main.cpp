#include <iostream>
// 해시 테이블 사용을 위한 헤더 인클루드.
#include <unordered_map>

// 게임 캐릭터 클래스.
class GameCharacter
{
public:
    // 생성자.
    GameCharacter() = default;
    GameCharacter(int code, int level, int money)
        : code(code), level(level), money(money)
    {
    }

    // Getter.
    const int Code() const {return code;}
    const int Level() const {return level;}
    const int Money() const {return money;}

    // 출력을 위한 연산자 오버로딩.
    friend std::ostream& operator<<(std::ostream& os, const GameCharacter& character)
    {
        return os << "코드: " << character.code << " | 레벨: " << character.level << " | 돈: " << character.money << "\n";
    }

private:
    int code = 0 ;
    int level = 0 ;
    int money = 0 ;
};

int main()
{
    // 해시 테이블 선언.
    std::unordered_map<int, GameCharacter> characters;

    // 데이터 추가 - make_pair.
    GameCharacter character1(10, 1, 30000);
    characters.insert(std::make_pair(character1.Code(), character1));
    
    // 데이터 추가 - 페어 생성자 사용.
    //characters.insert(std::pair<int, GameCharacter>(character1.Code(), character1));
    
    // 데이터 추가 - 페어 만들어서 넣기.
    //std::pair<int, GameCharacter> pair(character1.Code(), character1);
    //characters.insert(pair);

    // 데이터 추가 - 초기화 리스트.
    //characters.insert({ character1.Code(), character1 });

    GameCharacter character2(15, 3, 20000);
    characters.insert(std::make_pair(character2.Code(), character2));

    // 출력.
    for (auto& pair : characters)
    {
        std::cout << pair.second;
    }

    // 검색.
    auto it = characters.find(20);
    // 검색에 성공했는지 확인.
    if (it != characters.end())
    {
        // 캐릭터 정보 출력.
        std::cout << it->second;
    }
    else
    {
        std::cout << "Error: 검색 실패.\n";
    }

    // 검색 - count 함수 사용.
    //if (characters.count(10))
    //{
    //    std::cout << characters[10];
    //}

    // 검색 2 - 값이 없으면 빈 객체 반환.
    auto result = characters[20];
    std::cout << result;

    // 추가 - 인덱서 오퍼레이터 사용.
    characters[20] = GameCharacter(20, 5, 50000);

    // 검색 2.
    result = characters[20];
    std::cout << result;
    
    // 값이 있으면 못 넣음.
    GameCharacter character3(15, 3, 50000);
    characters.try_emplace(character3.Code(), character3);
    std::cout << characters[15];

    // 마찬 가지로 값이 있으면 못 넣음.
    characters.insert({ character3.Code(), character3 });
    std::cout << characters[15];

    // 값 교체.
    characters[15] = character3;
    std::cout << characters[15];

    std::cin.get();
}