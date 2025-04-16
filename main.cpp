/**
*            @file                    test_CanManager.cpp
*           @brief                 main for the CANMANAGER
*           @author                            Kenza AIT OUAZZOU
 *           @date                 04/2025
*
 */
 
#include <memory>
#include <cassert>
#include <iostream>
#include <boost/type_index.hpp>
#include <typeinfo>
#include <stdint.h>
//#include "CanManager.hpp"
#include "CanMessage.hpp"

//#define                           TEST_CANMANAGER
#define     TEST_CANMESSAGE
using boost::typeindex::type_id_with_cvr;

//----------------------------------------------------------------------------
//--------------------- Unit test : CanMessage            ------------------------------
#ifdef    TEST_CANMESSAGE
int main() {

	std::cout << "Test unitaire - CanMessage" << std::endl;

	CanMessage canMessage{};

	uint8_t dlc_test = canMessage.getDlc();
	std::cout <<"dlc_test "<< type_id_with_cvr<decltype(canMessage.getDlc())>().pretty_name() << '\n'<< std::endl;
	std::cout <<"dlc_test "<< type_id_with_cvr<decltype(dlc_test)>().pretty_name() << '\n'<< std::endl;

	std::cout <<"DLC initial :" << static_cast<int>(dlc_test) << std::endl;
	assert(dlc_test == 0); // Verification mise C  jour

	uint8_t id_test = canMessage.getId();
	std::cout <<"ID initial :" << static_cast<int>(id_test) << std::endl;
	assert(id_test == 0); // Verification mise C  jour

	canMessage.setDlc(255);
	std::cout <<"dlc_test "<< type_id_with_cvr<decltype(canMessage.getDlc())>().pretty_name() << '\n'<< std::endl;
	std::cout <<"DLC APRES SET :" << +dlc_test << std::endl;
	assert(canMessage.getDlc() == 255); // Verification mise C  jour

	canMessage.setId(15);
	std::cout <<"ID APRES SET :" << canMessage.getId() << std::endl;
	assert(canMessage.getId() == 15); // On vC)rifie  que l'ID a C)tC) mis C  jour

	//canMessage::canFormat format_test = canMessage.getFormat();
	assert(canMessage.getFormat() == CanMessage::canFormat::STANDARD);

	canMessage.setFormat(CanMessage::canFormat::STANDARD);
	assert(canMessage.getFormat() == CanMessage::canFormat::STANDARD); // On vC)rifie  que le format a C)tC) mis C  jour

	assert(canMessage.getType() == CanMessage::canType::DATA);

	canMessage.setType(CanMessage::canType::REMOTE);
	assert(canMessage.getType() == CanMessage::canType::REMOTE); // On vC)rifie que le type a C)tC) mis C  jour

	CanMessage constructeur1(CanMessage::canType::DATA,CanMessage::canFormat::STANDARD);
	assert(constructeur1.getType() == CanMessage::canType::DATA);
	assert(constructeur1.getFormat() == CanMessage::canFormat::STANDARD);

	CanMessage constructeur2(15, CanMessage::canType::DATA,CanMessage::canFormat::STANDARD, 29);
	assert(constructeur2.getType() == CanMessage::canType::DATA);
	assert(constructeur2.getFormat() == CanMessage::canFormat::STANDARD);
	assert(constructeur2.getId() == 15);
    assert(constructeur2.getDlc() == 29);
    
    CanMessage constructeur3(9, CanMessage::canType::DATA,CanMessage::canFormat::STANDARD);
	assert(constructeur3.getType() == CanMessage::canType::DATA);
	assert(constructeur3.getFormat() == CanMessage::canFormat::STANDARD);
	assert(constructeur3.getId() == 9);

    //std::array<uint8_t, MAX_DLC> data = constructeur1.Data();
	std::cout << "Fin des tests OK" << std::endl;

    //identifier les cas problematiques pour isValid
    
    //cas nominal 
	//STD, DATA ID 11 DLC 2 , data=4266


    //cas d'erreur 
      //DATA mais type = REMOTE
    
    //cas aux limites
	//si DLC =9 
	//ID different de 11 ou 29
	

	return 0;
}
#endif
