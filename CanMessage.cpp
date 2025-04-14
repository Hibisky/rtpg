#include <thread>
#include <mutex>
#include <array>
#include <chrono>
#include <random>

#include "CanMessage.hpp"

void CanMessage::setDlc(uint8_t newDlc)
{
    //if((newDlc >= 0) && (newDlc <= 8)) //valeur comprise entre 0 et 8 octets
    //{
        dlc = newDlc;
    //}

}

/// @brief permet de changer la valeur de l'id 
/// @param newId 
void CanMessage::setId(uint32_t newId)
{ 
    // if((newId >=0) && (newId <=8)) //valeur comprise entre 11 et 29 bits
    // {
        id = newId;
//}
}

/// @brief Permet de changer la valeur de canType 
/// @param type 
void CanMessage::setType(canType type) noexcept
{
    if(type == canType::DATA)
    {
        this->type = canType::DATA;
    }
    if(type == canType::REMOTE)
    {
        this->type = canType::REMOTE;
    } 
}

void CanMessage::setFormat(canFormat format) noexcept
{   
     if(format == canFormat::STANDARD)
    {
        this->format = canFormat::STANDARD;
    }
    if(format == canFormat::ETENDU)
    {
        this->format = canFormat::ETENDU;
    } 
}
























    // if(getId() ==11)
    // {
    //     this->format = canFormat::STANDARD;
    // }
    // if ((getId() == 29))
    // {
    //     this->format = canFormat::ETENDU;
    // }