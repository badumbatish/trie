#include "trie.h"
#include <iostream>
#include <unordered_map>

#include <string>
#include <vector>
#include <fstream>
void trie::input(std::string filename)
{
	std::ifstream f;
	f.open(filename);
	std::string str;
    while (f >> str) this->insert(str);
    f.close();
}

void trie::insert(std::string str)  {
	size_t i=0;
	trieNode *link=&root;
	
	for(;i<str.length();i++) {
		if(link->mp[str[i]]==nullptr) link->mp[str[i]]=new trieNode;
		link=link->mp[str[i]];
	}
	link->isEnd=true;
}

bool trie::search(std::string str) {
	size_t i=0;
	trieNode *link=&root;
	for(i=0;i<str.length();i++) {
		if(link->mp[str[i]]==nullptr) return false;
		link=link->mp[str[i]];
	}
	return link->isEnd;
}

void trie::suggestion() {
	std::cout << "Entering suggestion mode" << std::endl;
	std::string str;
	std::cin >> str;
	while(str!="0")
	{
		this->suggest(str);
		std::cin >> str;
	}
}

void trie::suggest(std::string& str) {
	size_t maximum_words=3;
	size_t max_length=5;
	
	size_t i=0; 
	std::string word;
	trieNode* link=&root;
	for(;i<str.length();i++)
	{	
		if(link->mp[str[i]]==nullptr) {
			std::cout << "Cant find any words" << std::endl;
			return;
		}
		link=link->mp[str[i]];
	}
	
	std::vector<std::string> vec;
	int count=5;
	find(link,str,vec,count);
	
	
	for(auto i : vec) {
		std::cout << "--> " <<  i << std::endl;
	}
	std::cout << std::endl;
}

std::string trie::find(trieNode* link,std::string str,std::vector<std::string>& vec, int& count)
{	
	if(count<=0)
	{
		return "";
	}
	std::string word;
	if(link->isEnd==true)
	{
		vec.push_back(str);
		count--;
	}
	for(auto i : link->mp)
	{
		if(i.second!=nullptr) {
			std::string s(1,i.first);
			word=find(i.second,str+s,vec,count);
			if(word!="")
			{
				count--;
				vec.push_back(word);
			}
		}
	}
	return "";
}
