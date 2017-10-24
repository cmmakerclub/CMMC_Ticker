#include "CMMC_Ticker.h"

void CMMC_Ticker::start(uint32_t every_ms) {
    if (every_ms == 0) {
        every_ms = this->_every_ms;
    }
    if (every_ms != this->_every_ms) {
        this->_every_ms = every_ms; 
    } 
    this->_ticker->detach();
    this->_ticker->attach_ms(this->_every_ms, this->_ticker_cb);
}
