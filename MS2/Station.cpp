// Name: Max Feng   
// Seneca Student ID: 136141231
// Seneca email: jfeng71@myseneca.ca    
// Date of completion: Jul 11, 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>
#include <sstream>

namespace seneca {
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;


    Station::Station(const std::string& record) : m_id(++id_generator) {
        Utilities util;
        size_t next_pos = 0;
        bool more = true;

        try {
            m_itemName = util.extractToken(record, next_pos, more);
            m_serialNumber = std::stoul(util.extractToken(record, next_pos, more));
            m_quantity = std::stoul(util.extractToken(record, next_pos, more));
            
            size_t utilsWidth = util.getFieldWidth();
            m_widthField = m_widthField > utilsWidth ? m_widthField : utilsWidth;

            m_description = util.extractToken(record, next_pos, more);
        } catch (const std::exception& e) {
            throw std::string("Error parsing record: ") + record;
        }
    }

    const std::string& Station::getItemName() const {
        return m_itemName;
    }

    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const {
        return m_quantity;
    }

    void Station::updateQuantity() {
            --m_quantity;
        }

   void Station::display(std::ostream& os, bool full) const {
        os.width(3);
        os.fill('0');
        os << std::right << m_id << " | ";
        os.fill(' ');

        os.width(m_widthField);
        os << std::left << m_itemName << " | ";

        os.width(6);
        os.fill('0');
        os << std::right << m_serialNumber << " | ";
        os.fill(' ');
        
        if (full) {
            os.width(4);
            os << std::right << m_quantity << " | " << m_description;
        }

        os << std::endl;
    }
}
