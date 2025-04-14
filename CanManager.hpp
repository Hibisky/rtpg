#ifndef __CANMANAGER_HPP__
#define __CANMANAGER_HPP__

#include "CanMessage.hpp"
#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <algorithm>

/**------------------------------------------------------------------------- */
/**
* @brief  CanManager Class - Pure virtual class
*/

class CanManager
{
    public:
        enum class bitRate_t
        {
            KBPS10,
            KBPS20,
            KBPS62_5,
            KBPS125,
            KBPS250,
            KBPS500,
            KBPS800,
            KBPS1000
        };
    private:
        bitRate_t bitRate{bitRate_t::KBPS20}; /** Default bitrate is 20 kbps */
        /**    
        * @brief Virtual "callback", called after each setbitRate
        * Empty function if not overrided.
        * */
        virtual void bitRateRefresh() {};
    public:
        CanManager() = default; /** Default Ctor is efaulted */
        virtual ~CanManager() = default; /** Dtor is defaulted */
        
        explicit CanManager(bitRate_t br) noexcept : bitRate{br} {}; /** Standard Ctor */
        /**
        * @brief bitRate accessors
        */
        [[nodiscard]] bitRate_t getbitRate() noexcept { return this->bitRate; };

        void setbitRate(bitRate_t br) noexcept
        {
           this->bitRate = br;
           this->bitRateRefresh();
        };

        virtual void Emit(const CanMessage &msg) = 0; /** Tx function - Pure virtual */
        [[nodiscard]] virtual bool Receive(CanMessage &msg) = 0; /** Rx function-Pure virtual */
};
#endif /* __CANMANAGER_HPP__ */