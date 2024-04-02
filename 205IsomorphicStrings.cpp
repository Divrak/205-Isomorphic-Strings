#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::pair<char, int>> getCharsQuantity(std::vector <std::pair<char, int>> inS)
    {
        
    }
    bool isIsomorphic(std::string s, std::string t) {
        std::vector<std::pair<char, int>> charQuantityS;
        std::vector<std::pair<char, int>> charQuantityT;
        
        for (auto &el : charQuantityS)
        {
        }


        return false;
    }
};

int main(int argc, char **argv)
{
    auto s = Solution();
    std::cout << s.isIsomorphic("title", "paper") << std::endl;
    std::cout << s.isIsomorphic("egg", "add") << std::endl;
    std::cout << s.isIsomorphic("foo", "bar") << std::endl;
}
