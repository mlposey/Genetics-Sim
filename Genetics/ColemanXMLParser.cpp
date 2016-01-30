#include "ColemanXMLParser.h"


ColemanXMLParser::ColemanXMLParser(const std::string &filename)
	: _parser(const_cast<char*>(filename.c_str()))
{
}


ColemanXMLParser::~ColemanXMLParser()
{
}

// TODO: Verify that expectedCount should always be 2 for ColemanXML
void ColemanXMLParser::parseFile(std::vector<Organism> &organisms,
								 int expectedCount) {
}
