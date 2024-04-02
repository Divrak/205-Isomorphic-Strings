#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

class Solution {
public:

	bool isIsomorphic(std::string inS, std::string inT) {

		if (inS.length() != inT.length()) return false;

		std::unordered_map<char, std::map<int, int>> charPosRepeatS;
		std::unordered_map<char, std::map<int, int>> charPosRepeatT;

		int pos {};
		for (int i {}; i < inS.length(); ++i)
		{
			//for inS
			std::map<int, int> posRepeatS;
			if (charPosRepeatS.contains(inS[i]))
				//Увеличить количество повторов на указанной позиции
				++charPosRepeatS.find(inS[i])->second.begin()->second;
			//Добавить позицию
			posRepeatS.insert(std::make_pair(pos, 1));
			//Добавить запись в словарь символов
			charPosRepeatS.insert(std::make_pair(inS[i], posRepeatS));

			//for inT
			std::map<int, int> posRepeatT;
			if (charPosRepeatT.contains(inT[i]))
				//Увеличить количество повторов на указанной позиции
				++charPosRepeatT.find(inT[i])->second.begin()->second;
			//Добавить позицию
			posRepeatT.insert(std::make_pair(pos, 1));
			//Добавить запись в словарь символов
			charPosRepeatT.insert(std::make_pair(inT[i], posRepeatT));

			++pos;
		}
		for (int i {}; i < charPosRepeatS.size(); ++i)
		{
			//Сравнить позицию
			if (charPosRepeatS.find(inS[i])->second.begin()->first != charPosRepeatT.find(inT[i])->second.begin()->first)
				return false;

			//Сравнить количество вхождений буквы на позиции
			if (charPosRepeatS.find(inS[i])->second.begin()->second != charPosRepeatT.find(inT[i])->second.begin()->second)
				return false;
		}
		return true;
	}
};

int main(int argc, char **argv)
{
	auto s = Solution();
	std::cout << s.isIsomorphic("bbbaaaba", "aaabbbba") << std::endl;
	std::cout << s.isIsomorphic("title", "paper") << std::endl;
	std::cout << s.isIsomorphic("egg", "add") << std::endl;
	std::cout << s.isIsomorphic("foo", "bar") << std::endl;
	
}
