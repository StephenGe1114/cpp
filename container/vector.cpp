//
// Created by 14991 on 2022/5/26.
//

#include <iostream>
#include <string>
#include <vector>

template<typename T>
const std::ostream& operator<<(const std::ostream& s, const std::vector<T>& v)
{
    for(auto e: v)
    {
        s << e << " ";
    }
    return s << std::endl;
}

int main() {
    std::vector<std::string> word1{"the", "frogurt", "is", "also", "cursed"};
    std::cout << "word1: " << word1 << std::endl;
    return 0;
}

