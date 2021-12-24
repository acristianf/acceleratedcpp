#ifndef GUARD_string_utils_h
#define GUARD_string_utils_h

#include <string>
#include <vector>

bool space(char c);
bool not_space(char c);
std::vector<std::string> split(const std::string&); 
std::vector<std::string> no_duplicates_split(const std::string& s); 
template<class Out> void split(const std::string& str, Out os);

#endif
