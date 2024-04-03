#include <iostream>
#include <map>
#include <vector>

class Solution {
public:

	bool isIsomorphic(std::string inS, std::string inT) {

		//if length string not equal, return false
		if (inS.length() != inT.length()) return false;

		std::map<char, std::vector<int>> charToPosS;
		std::map<char, std::vector<int>> charToPosT;

		for (int i {}; i < inS.length(); ++i)
		{
			//for inS
			if (charToPosS.contains(inS[i])) //if inS[i] already exists
				charToPosS.find(inS[i])->second.push_back(i);
			else
				charToPosS.insert(std::make_pair(inS[i], std::vector<int>{i}));

			//for inT
			if (charToPosT.contains(inT[i])) //if inT[i] already exists
				charToPosT.find(inT[i])->second.push_back(i);
			else
				charToPosT.insert(std::make_pair(inT[i], std::vector<int>{i}));
		}

		//if maps.size not equal, return false
		if (charToPosS.size() != charToPosT.size())
			return false;

		//checks 
		for (int i {}; i < charToPosS.size(); ++i)
		{
			for (int j {}; j < charToPosS.find(inS[i])->second.size(); ++j)
			{
				//if char quantity in current position not equal, return false
				if (charToPosS.find(inS[i])->second.size() != charToPosT.find(inT[i])->second.size())
					return false;

				//if char position not equal, return false
				if (charToPosS.find(inS[i])->second[j] != charToPosT.find(inT[i])->second[j])
					return false;
			}
		}

		return true;
	}
	/* TOP */
	/*
	bool isIsomorphic(std::string s, std::string t) {
		if (s.size() != t.size()) {
			return false;
		}

		std::vector<int> v1(128, -1);
		std::vector<int> v2(128, -1);

		for (int i = 0; i < s.size(); i++) {
			if (v1[s[i]] != v2[t[i]]) {
				return false;
			}
			v1[s[i]] = v2[t[i]] = i;
		}
		return true;
	}
	*/
};

int main(int argc, char **argv)
{
	auto s = Solution();
	std::cout << s.isIsomorphic("bbbaaaba", "aaabbbba") << std::endl;
	std::cout << s.isIsomorphic("papap", "titii") << std::endl;
	std::cout << s.isIsomorphic("title", "paper") << std::endl;
	std::cout << s.isIsomorphic("egg", "add") << std::endl;
	std::cout << s.isIsomorphic("foo", "bar") << std::endl;
	
}
