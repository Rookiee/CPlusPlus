#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <map>
#include <set>
#include <utility>
#include <fstream>
#include <sstream>
class TextQuery {
public:
	//vector的每一个元素是读取的文件中的一行
	typedef std::vector<std::string>::size_type lineNo;
private:
	std::vector<std::string> LineOfText;
	std::map< std::string, std::set<lineNo> > word_map;
private:
	void StoreFile(std::ifstream &);	//store input file
	void BuildMap();	

public:
	void ReadFile(std::ifstream &is) { StoreFile(is); BuildMap(); }
	std::set<lineNo> RunQuery(const std::string &) const;
	std::string TextLine(const lineNo) const;
};


#endif
