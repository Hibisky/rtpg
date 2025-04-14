#ifndef __CANMESSAGE_HPP__
#define __CANMESSAGE_HPP__

#include "CanMessage.hpp"
#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <algorithm>
#include <array>

//constexpr unsigned uint8_t MAX_DLC{8};
#define MAX_DLC 8
/**------------------------------------------------------------------------- */
/**
* @brief  CanManager Class - Pure virtual class
*/

class CanMessage
{
    public:
        enum class canType
        {
            DATA,
            REMOTE
        };

        enum class canFormat
        {
            STANDARD,
            ETENDU
        };

        CanMessage() = default; /** Default Ctor is efaulted */
        virtual ~CanMessage() = default; /** Dtor is defaulted */


    ///---------------------- ACCESSORS ----------------------//////   
    uint32_t getId(){return this->id;};
    void setId(uint32_t newId);

    uint8_t getDlc(){return this->dlc;};
    void setDlc(uint8_t newDlc);

    canFormat	getFormat(){ return this->format;};
    void setFormat(canFormat format) noexcept;

    canType getType(){ return this->type;};
    void setType(canType type)  noexcept ;


private:
    canFormat format{canFormat::STANDARD};
    canType type{canType::DATA};
    uint32_t id = 0 ;
    uint8_t dlc = 0 ;
    std::array<uint8_t, MAX_DLC>  _Data;


};
#endif /* __CANMESSAGE_HPP__ */