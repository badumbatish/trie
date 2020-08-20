#pragma once
#include "includer.h"

struct trieNode {
	bool isEnd=false;
	std::map<char,trieNode*> mp;
};

class trie {
private:

public:
	trieNode root;
	bool search(const std::string&);
	void insert(const std::string&, size_t start, size_t end); // end = str.length()
	void insert(const std::string&);
	void insert(const std::vector<std::string>&);

	void dfs() {
		std::string str="";
		dfs(&root,str);
	}
	void dfs(trieNode* node, std::string& str);

	void bfs() {
		bfs(&root);
	}
	void bfs(trieNode* node);

	
};