/**
* @file        test_CanManager.cpp
* @brief       Main for the CANMANAGER
* @author      Kenza AIT OUAZZOU
* @date        04/2025
*/

#include <memory>
#include <cassert>
#include <iostream>
#include <boost/type_index.hpp>
#include <typeinfo>
#include <cstdint>
#include "CanMessage.hpp"

#define TEST_CANMESSAGE

using boost::typeindex::type_id_with_cvr;

#ifdef TEST_CANMESSAGE
int main() {

    std::cout << "Test unitaire - CanMessage" << std::endl;

    CanMessage canMessage{};

    uint8_t dlc_test = canMessage.getDlc();
    std::cout << "Type of canMessage.getDlc(): " << type_id_with_cvr<decltype(canMessage.getDlc())>().pretty_name() << '\n' << std::endl;
    std::cout << "Type of dlc_test: " << type_id_with_cvr<decltype(dlc_test)>().pretty_name() << '\n' << std::endl;

    std::cout << "Initial DLC: " << static_cast<int>(dlc_test) << std::endl;
    assert(dlc_test == 0); // Initial DLC should be 0

    uint32_t id_test = canMessage.getId();
    std::cout << "Initial ID: " << id_test << std::endl;
    assert(id_test == 0); // Initial ID should be 0

    canMessage.setDlc(255);
    dlc_test = canMessage.getDlc(); // Update dlc_test after setting new DLC
    std::cout << "DLC after set: " << static_cast<int>(dlc_test) << std::endl;
    assert(canMessage.getDlc() == 255); // DLC should be updated to 255

    canMessage.setId(15);
    id_test = canMessage.getId(); // Update id_test after setting new ID
    std::cout << "ID after set: " << id_test << std::endl;
    assert(id_test == 15); // ID should be updated to 15

    assert(canMessage.getFormat() == CanMessage::canFormat::STANDARD); // Check initial format

    canMessage.setFormat(CanMessage::canFormat::STANDARD);
    assert(canMessage.getFormat() == CanMessage::canFormat::STANDARD); // Format should remain STANDARD

    assert(canMessage.getType() == CanMessage::canType::DATA); // Check initial type

    canMessage.setType(CanMessage::canType::REMOTE);
    assert(canMessage.getType() == CanMessage::canType::REMOTE); // Type should be updated to REMOTE

    CanMessage constructeur1(CanMessage::canType::DATA, CanMessage::canFormat::STANDARD);
    assert(constructeur1.getType() == CanMessage::canType::DATA);
    assert(constructeur1.getFormat() == CanMessage::canFormat::STANDARD);

    CanMessage constructeur2(2048, CanMessage::canType::DATA, CanMessage::canFormat::STANDARD, 2);
    assert(constructeur2.getType() == CanMessage::canType::DATA);
    assert(constructeur2.getFormat() == CanMessage::canFormat::STANDARD);
    assert(constructeur2.getId() == 2048);
    assert(constructeur2.getDlc() == 2);
    
    CanMessage constructeur3(9, CanMessage::canType::DATA, CanMessage::canFormat::STANDARD);
    assert(constructeur3.getType() == CanMessage::canType::DATA);
    assert(constructeur3.getFormat() == CanMessage::canFormat::STANDARD);
    assert(constructeur3.getId() == 9);

    // Validate data function/field (optional)
    std::array<uint8_t, MAX_DLC> &data = constructeur1.Data();
	
    //cas nominal
    constructeur2.isMessageValid();
    assert(constructeur2.isMessageValid() == true);
    
    //cas aux limites dlc trop grand 
    CanMessage constructeur5(2048, CanMessage::canType::DATA, CanMessage::canFormat::STANDARD, 9);
    assert(constructeur5.isMessageValid() == false);
    
    //cas aux limites id different de 2^11 ou 2^29
    CanMessage constructeur6(9, CanMessage::canType::DATA, CanMessage::canFormat::STANDARD, 2);
    assert(constructeur6.isMessageValid() == false);

    //cas d'erreur Remote mais presence de data 
    CanMessage constructeur6(2048, CanMessage::canType::REMOTE, CanMessage::canFormat::STANDARD, 2);
    assert(constructeur6.isMessageValid() == false);

	std::cout << "Fin des tests OK" << std::endl;
	return 0;
}
#endif
