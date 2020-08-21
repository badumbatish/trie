#include "trie.h"


void trie::insert(const std::string& str) {
	trie::insert(str,0,str.length());
}
void trie::insert(const std::string& str, size_t start, size_t end)  {
	assert(end-start<=str.length() && "Length of string is smaller than end-start, will possibly have undefined behavior");
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
bool trie::search(const std::string& str,size_t start, size_t end) {
	size_t i=start;
	trieNode *link=&root;
	for(i=0;i<end;i++) {
		if(link->mp[str[i]]==nullptr) return false;
		link=link->mp[str[i]];
	}
	return link->isEnd;
}

bool trie::search(const std::string& str) {
	return trie::search(str,0,str.length());
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

void trie_matching(const std::string& text,const std::vector<std::string>& patterns, std::vector<int> &ans) {
    trie t;
    char symbol;
    trieNode* link=&(t.root);
    bool restart=false;
    int count=0;
    t.insert(patterns);
    for(size_t i=0;i<text.length();i++,count++) {
        //std::cout << i << " " << count << std::endl;
        symbol = text[i];
        // If the symbol isn't found in the trie or is shorter than suffix of text, then its not there, we restart
        if(link->mp[symbol]==nullptr) {
            restart=true;
        } else if (link->mp[symbol]->isEnd==true) { // if it is there and it is the end of a word then
        //  we can keep going 
            if(ans.empty() || (!ans.empty() && ans.back()!=count)) ans.push_back(i-count);
        }

		if(restart) {
            i=i-count;
            count=-1;
            link=&(t.root);
            restart=false;
        } else {
            link=link->mp[symbol];
        }
    }
}
void trie::suffix_trie(const std::string& str) { 
	for(size_t i=0;i<str.length();i++) {
		trie::insert(str,i,str.length());
	}
	return;
}