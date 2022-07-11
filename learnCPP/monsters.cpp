#include <iostream>
#include <string>
#include <string_view>

enum MonsterType {
    ogre, dragon, orc, giantSlime, spider, 
};

constexpr std::string_view getMonsterName(MonsterType t) {
    switch(t){
        case MonsterType::ogre: return "Ogre";
        case MonsterType::dragon: return "Dragon";
        case MonsterType::orc: return "Orc";
        case MonsterType::giantSlime: return "Giant Slime";
        case MonsterType::spider: return "Spider";
        default: return "??";
    }
}

struct Monster {
    MonsterType type {};
    std::string name;
    int hp;
};

void printMonster(Monster m) {
    std::cout << "Monster stats: " << '\n';
    std::cout << "- Type: " << getMonsterName(m.type) << '\n';
    std::cout << "- Name: " << m.name << '\n';
    std::cout << "- Starting Health: " << m.hp << '\n';
}

int main() {
    Monster myOgre {ogre, "Ralph", 100};
    Monster mySlime {giantSlime, "Goop", 120};

    printMonster(myOgre);
    printMonster(mySlime);
}

