//
// Created by  Роман on 24.11.2022.
//

#ifndef HOFFMAN_LZ78_H
#define HOFFMAN_LZ78_H

#include <vector>
#include <iostream>
#include "string"
#include "unordered_map"

class lz78 {
public:
	int i;
	char c;


public:
	lz78(int i, char c){
		this->i = i;
		this->c= c;
	}
};


std::vector<lz78> encode_78(std::string input_str){
	std::vector<lz78> ret;
	std::string prev_sub = "";
	std::unordered_map<std::string, int> sub_dict;
	sub_dict.insert(std::make_pair("", 0));
	for (auto c : input_str){
		std::string next_sub = prev_sub + c;
		for (auto c : sub_dict){
			std::cout << c.first << " " << c.second << std::endl;
		}
		if (sub_dict.find(next_sub) == sub_dict.end()){
			std::cout << "!!!!?" << std::endl;

			int i = sub_dict[prev_sub];
			lz78 code(i, c);
			ret.push_back(code);
			sub_dict[next_sub] = sub_dict.size();
			prev_sub = "";
		}else {
			prev_sub = next_sub;
		}
	}
	return ret;
}


std::string decode_78(std::vector<lz78> inp){
	std::string ret = "";
	std::vector<std::string> sub_dict;
	sub_dict.push_back("");
	for (auto code : inp){
		std:: string sub = sub_dict[code.i] + code.c;
		sub_dict.push_back(sub);
		ret += sub;
	}
	return ret;
}

#endif //HOFFMAN_LZ78_H
