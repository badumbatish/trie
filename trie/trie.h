#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct trieNode {
	bool isEnd=false;
	std::map<char,trieNode*> mp;
};

class trie {
private:
	trieNode root;
public:
	void input(std::string);
	void insert(std::string);
	bool search(std::string);
	void suggestion();
	void suggest(std::string&);
	std::string find(trieNode*, std::string, std::vector<std::string>&, int&);
};