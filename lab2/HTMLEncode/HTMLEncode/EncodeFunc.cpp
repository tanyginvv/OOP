#include "Encode.h"

std::string HtmlEncode(std::string const& text) {
	std::string result;
	for (auto const& ch : text) {
		switch (ch) {
		case '"': result += "&quot;"; break;
		case '\'': result += "&apos;"; break;
		case '<': result += "&lt;"; break;
		case '>': result += "&gt;"; break;
		case '&': result += "&amp;"; break;
		default: result += ch; break;
		}
	}
	return result;
}