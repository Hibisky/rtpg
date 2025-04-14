/**
 *	@file		test_CanManager.cpp
 * 	@brief 		main for the CANMANAGER
 * 	@author		Kenza AIT OUAZZOU 
 * 	@date		04/2025
 * 
 */
#include <memory>
#include <cassert>
#include <iostream>
#include "CanManager.hpp"
#include "CanMessage.hpp"

//#define		TEST_CANMANAGER
#define     TEST_CANMESSAGE


//----------------------------------------------------------------------------
//--------------------- Unit test : CanManager	------------------------------
#ifdef	TEST_CANMANAGER
int main(){

}
#endif
//----------------------------------------------------------------------------
//--------------------- Unit test : CanMessage	------------------------------
#ifdef	TEST_CANMESSAGE
int main(){
    std::cout << "Test unitaire - CanMessage" << std::endl;

    CanMessage canMessage{};

    uint8_t dlc_test = canMessage.getDlc();
    std::cout <<"DLC initial :" << static_cast<int>(dlc_test) << std::endl;
    assert(dlc_test == 0); // Verification mise à jour

    uint8_t id_test = canMessage.getId();
    std::cout <<"ID initial :" << static_cast<int>(id_test) << std::endl;
    assert(id_test == 0); // Verification mise à jour

    canMessage.setDlc(56);
    std::cout <<"DLC APRES SET :" << static_cast<int>(canMessage.getDlc()) << std::endl;
    assert(canMessage.getDlc() == 56); // Verification mise à jour

    canMessage.setId(15);
    std::cout <<"ID APRES SET :" << static_cast<int>(canMessage.getId()) << std::endl;
    assert(canMessage.getId() == 15); // On vérifie  que l'ID a été mis à jour

    //canMessage::canFormat format_test = canMessage.getFormat();
    assert(canMessage.getFormat() == CanMessage::canFormat::STANDARD);

    canMessage.setFormat(CanMessage::canFormat::STANDARD);
    assert(canMessage.getFormat() == CanMessage::canFormat::STANDARD); // On vérifie  que le format a été mis à jour

    assert(canMessage.getType() == CanMessage::canType::DATA);

    canMessage.setType(CanMessage::canType::REMOTE);
    assert(canMessage.getType() == CanMessage::canType::REMOTE); // On vérifie que le type a été mis à jour

    std::cout << "Fin des tests OK" << std::endl;

    return 0;
}
#endif
