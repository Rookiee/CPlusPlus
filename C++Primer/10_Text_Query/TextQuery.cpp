#include "TextQuery.h"
#include <sstream>
#include <stdexcept>
void TextQuery::StoreFile(std::ifstream & is) {
	std::string textline;
	while( getline(is, textline) )
		LineOfText.push_back(textline);
}

void TextQuery::BuildMap() {
	for(lineNo lineNum = 0; lineNum != LineOfText.size(); ++ lineNum) {
		std::istringstream line(LineOfText[lineNum]);
		std::string word;
		while( line >> word )
			word_map[word].insert(lineNum);
	}
}

std::set<TextQuery::lineNo> TextQuery::RunQuery(const std::string & query_word) const {
	std::map<std::string, std::set<lineNo> >::const_iterator loc = 
		word_map.find(query_word);
	if(loc == word_map.end())
		return std::set<lineNo> ();
	else
		return loc->second;
}

	
std::string TextQuery::TextLine(const lineNo line) const {
	if (line < LineOfText.size())
		return LineOfText[line];
	throw std::out_of_range("Line number out of range");
}

