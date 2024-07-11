// Name: Max Feng   
// Seneca Student ID: 136141231
// Seneca email: jfeng71@myseneca.ca    
// Date of completion: Jul 11, 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
#include <algorithm>
#include <stdexcept>

namespace seneca {
    char Utilities::m_delimiter = ',';

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        if (next_pos >= str.length()) {
            more = false;
            return "";
        }

        size_t start_pos = next_pos;
        size_t end_pos = str.find(m_delimiter, start_pos);

        if (start_pos == end_pos) {
            more = false;
            throw std::invalid_argument("Delimiter found at next_pos.");
        }

        std::string token;
        if (end_pos == std::string::npos) {
            token = str.substr(start_pos);
            next_pos = str.length();
            more = false;
        } else {
            token = str.substr(start_pos, end_pos - start_pos);
            next_pos = end_pos + 1;
            more = true;
        }

        token.erase(token.begin(), std::find_if(token.begin(), token.end(), [](unsigned char ch) { return !std::isspace(ch); }));
        token.erase(std::find_if(token.rbegin(), token.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), token.end());

        if (m_widthField < token.length()) {
            m_widthField = token.length();
        }

        return token;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}
