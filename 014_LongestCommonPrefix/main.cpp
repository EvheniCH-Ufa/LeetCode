#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	std::string longestCommonPrefix(const std::vector<std::string>& strs) { //14
		if (strs.empty()) {
			return "";
		}

		if (strs.size() == 1) {
			return strs[0];
		}

		int min_len = strs[0].size();
		for (int i = 1; i < strs.size(); ++i) {
			if (min_len > strs[0].size()) {
				min_len = strs[0].size();
			}
		}

		bool sovpad = true;
		for (int i = 0; i < min_len; ++i) {         // po simbols
			for (int j = 1; j < strs.size(); ++j) { // po vectoru
				if (strs[j][i] != strs[j-1][i]) {
					sovpad = false;
					break;
				}
			}
			if (!sovpad) {
				return strs[0].substr(0, i);
			}
		}
		return strs[0].substr(0, min_len);
	}
};



int main() {
	Solution sol;
	{
		std::cout << sol.longestCommonPrefix({"flower", "flowr", "flight"}) << std::endl;    // fl
		std::cout << sol.longestCommonPrefix({"dog", "racecar", "car"}) << std::endl;     	 // ""
	}
}
