#include <thread>
#include <mutex>
#include <array>
#include <chrono>
#include <random>

#include "CanMessage.hpp"

/// @brief permet de changer la valeur de le dlc 
/// @param newDlc
void CanMessage::setDlc(uint8_t newDlc)
{
    dlc = newDlc;
}

/// @brief permet de changer la valeur de l'id 
/// @param newId 
void CanMessage::setId(uint32_t newId)
{ 
    id = newId;
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

CanMessage::CanMessage(CanMessage::canType type ,CanMessage::canFormat format)
:type(type), format(format)
{
}

CanMessage::CanMessage(uint32_t id, CanMessage::canType type ,CanMessage::canFormat format, uint8_t dlc)
: id(id), type(type), format(format), dlc(dlc)
{
}


CanMessage::CanMessage (uint32_t id, CanMessage::canType type ,CanMessage::canFormat format)
: id(id), type(type), format(format)
{
}

std::array<uint8_t, MAX_DLC>& CanMessage::Data()
{
// return une ref sur le champ _Data de l'objt
    return _Data;
}

bool CanMessage::isMessageValid()
 {
    uint32_t MAX_ID_11;
    MAX_ID_11 = pow(2, 11);
    uint32_t MAX_ID_29;
    MAX_ID_29 = pow(2, 29);

    //Id a un champ variable qui conditionnne ca valeur max 
    //2^11 valeur max id 

    //Soit le format est SDT et l'ID est 2^11 
    //Soit le format est ETD et l'ID est 2^29
    
    if(((getFormat() == canFormat::STANDARD) && (getId() == MAX_ID_11)) || ((getFormat() == canFormat::ETENDU) &&(getId() == MAX_ID_29)))
    {
        //Soit le TYPE est Remote et on verifie que le dlc est a 0 => pas de DATA 
        //Soit le type est DATA et on verifie que le dlc est bien compris entre 0 et 8 
        //nb octets attendu en retour dans le cas trame REMOTE
        if(((getType() == canType::REMOTE) && (getDlc() == 0)) || ((getType() == canType::DATA) && ((getDlc() >0) && (getDlc() <= 8 ))))
        {
            return true ;
        }
    }
    return false;
}

/////////////////// FORMAT TRAME CAN ///////////////////////////
            //  ID // FORMAT // TYPE // DLC // DATAAAAAAAAAA //


//step 7
std::string CanMessage::toString()
{
    std::string res;
    //format 
    std::string format = " NOK";
    if (getFormat() == CanMessage::canFormat::STANDARD)
    {
        format = "STD";
    }
    else 
    {
        format = "EXT";
    }
    
    //"STANDARD","DATA","oA5","2","4266", "TRUE"};

    //type
    std::string type;
    if (getType() == CanMessage::canType::REMOTE)
    {
        type = "RMT";
    }
    else 
    {
        type = "DATA";
    }
    
    //id 3 std ou 8 ext 
    std::string idstring;
    if(getFormat() == CanMessage::canFormat::STANDARD) 
    {
        idstring = "3";
    }
    else
    {
        idstring = "8";
    }

    //validity 
    std::string validate;
    if( isMessageValid() == true)
    {
        validate = "true";
    }
    else
    {
        validate = "false";
    }
    
    
    //dlc value
    //data si dlc = 0 ou REMOTE alors empty
    std::string dlcstring;
    if((getDlc() == 0) || (getType() == CanMessage::canType::REMOTE) )
    {
        dlcstring = "empty";
        res= format + ","+ type +","+ idstring +","+ std::to_string(static_cast<int>(this->getDlc()))+","+dlcstring +","+ validate;
    }
    else
    {
        dlcstring = ;
        res= format + ","+ type +","+ idstring +","+ std::to_string(static_cast<int>(this->getDlc()))+","+dlcstring +","+ validate;
    }
    
    return res;
}
