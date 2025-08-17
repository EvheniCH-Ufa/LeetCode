#include <iostream>
#include<unordered_map>
#include <string>


struct Solution {
	public:
		int romanToInt(const std::string& str) { //13
			if (str.empty()) {
				return 0;
			}

			if (str.size() == 1) {
				auto it_lib =  libr.find(str);
				if (it_lib != libr.end()) {
					return  it_lib->second;
				}
			}

			int index = 0;
			int result = 0;
			while(index < str.size()) {
				auto it_lib =  libr.find(str.substr(index, 2));
				if (it_lib != libr.end()) {
					result += it_lib->second;
					index += 2;
					continue;
				}

				it_lib =  libr.find(str.substr(index, 1));
				if (it_lib != libr.end()) {
					result += it_lib->second;
					index += 1;
					continue;
				}
				index += 2;
			}

			if (index == str.size()-1) {
				const auto it_lib =  libr.find(str.substr(index, 1));
				if (it_lib != libr.end()) {
					result += it_lib->second;
				}
			}

			return result;
		}

	private:
		const 	  std::unordered_map<std::string, int> libr = {
			{"M", 1000},
			{"D", 500},
			{"C", 100},
			{"L", 50},
			{"X", 10},
			{"V", 5},
			{"I", 1},

			{"MD", 1500},
			{"DC", 600},
			{"CL", 150},
			{"LX", 60},
			{"XV", 15},
			{"VI", 6},

			{"CM", 900},
			{"XC", 90},
			{"IX", 9},
			{"CD", 400},
			{"XL", 40},
			{"IV", 4},
		};
};



int main() {
	Solution sol;


	//RomToInt
	{
		std::cout << sol.romanToInt("III") << std::endl;          // 3
		std::cout << sol.romanToInt("LVIII") << std::endl;        // 58
		std::cout << sol.romanToInt("MCMXCIV") << std::endl;      // 1994
	}


}
