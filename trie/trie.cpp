#include "trie.h"


void trie::insert(const std::string& str) {
	trie::insert(str,0,str.length());
}
void trie::insert(const std::string& str, size_t start, size_t end)  {
	assert(end-start<=str.length() && "Length of string is smaller than end-start, will possibly be undefined behavior");
	size_t i=start;
	trieNode *link=&root;
	
	for(;i<end;i++) {
		if(link->mp[str[i]]==nullptr) link->mp[str[i]]=new trieNode;
		link=link->mp[str[i]];
	}
	link->isEnd=true;
}

void trie::insert(const std::vector<std::string> &patterns) {
	for(auto pattern : patterns) trie::insert(pattern);
}


bool trie::search(const std::string& str) {
	size_t i=0;
	trieNode *link=&root;
	for(i=0;i<str.length();i++) {
		if(link->mp[str[i]]==nullptr) return false;
		link=link->mp[str[i]];
	}
	return link->isEnd;
}

void trie::dfs(trieNode* node, std::string& str) {
	trieNode* link = node;
	for(auto it : link->mp){
		//std::cout << it->first << std::endl;
		str.push_back(it.first);
		if(it.second->isEnd) {
			std::cout << str << " ";
		}
		trie::dfs(it.second,str);
		str.pop_back();
	}
	return;
}

void trie::bfs(trieNode* node) {
	trieNode* link=node;
	std::queue<std::pair<char,trieNode*>> q;
	for(auto i : link->mp) {
		q.push(i);
	}
	while(!q.empty()){
		std::cout << q.front().first << std::endl;
		bfs(q.front().second);
		q.pop();
	}

	return;
}