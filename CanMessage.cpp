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

/*std::array<uint8_t, MAX_DLC> CanMessage::Data()
{
// return une ref sur le champ _Data de l'objt
    return _Data;
}*/

bool CanMessage::isMessageValid()
{
    //Id a un champ variable qui conditionnne ca valeur max 
    //2^11 valeur max id 
    if((getFormat() == canFormat::STANDARD) && (getId() == 11))
    {
        //if(getId() == 11){
        return true; 
        //}*/
    }
    else /*(getFormat() == canFormat::ETENDU)*/
    {
        if(getId() == 29)
        {
          return true;   
        }
    }

    
    if(( getDlc()>=0) && (getDlc() <=8)) 
    {
        if(getType()==canType::DATA)
        {
            //nb octets donnée de trame
            return true;
        }
        //nb octets attendu en retour dans le cas trame REMOTE
    } 
    
    //champ de données (data) entre o et 8 octets
    //identifier les cas problematique 
    
    //voir les can message
    //cas nominal cas d'erreur 
    
    //cas aux limites
    return false;
}

//step 7
std::string CanMessage::toString()
{
    //"STANDARD","DATA","oA5","2","4266", "TRUE"};
    //format 
    //type
    //id 3 std ou 8 ext 
    //dlc value
    //data si dlc = 0 ou REMOTE alors empty
    //validity 
    //return chain_carac[];
}




















    // if(getId() ==11)
    // {
    //     this->format = canFormat::STANDARD;
    // }
    // if ((getId() == 29))
    // {
    //     this->format = canFormat::ETENDU;
    // }