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
	bool search(const std::string&,size_t start, size_t end); // insert a string with starting and ending point
	bool search(const std::string&); // search for a full-size string


	void insert(const std::string&); // insert a full-size string

	
	void insert(const std::string&, size_t start, size_t end); // insert a string with starting and ending point // end = str.length()
	void insert(const std::vector<std::string>&);

	void suffix_trie(const std::string& text); // build a trie made out of suffixes of a string
	void trie_matching(const std::string& text ,const std::vector<std::string>& patterns, std::vector<int>& ans); // return indexes of matched patterns found in std::string text

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