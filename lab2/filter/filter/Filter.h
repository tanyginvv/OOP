#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
const std::string ERROR1 = "Sorry, you forgot enter a file with bad words: ";
const std::string ERROR2 = "Sorry, we couldn't open a file with bad words";
std::string ToLowerCase(const std::string& str);
void ReadBannedWords(std::set<std::string>& bannedWords, const std::string& fileName);
void FilterInput(std::set<std::string>& bannedWords);

