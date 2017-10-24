#ifndef CMMC_Ticker_H
#define CMMC_Ticker_H

#include <Arduino.h>
#include <Ticker.h>

typedef void (*cmmc_ticker_cb_t)(void);
class CMMC_Ticker
{
    public:
      // constructor
      CMMC_Ticker(uint8_t *state, uint32_t every_ms) { 
        static CMMC_Ticker *that = this;
        this->_user_state_ptr = state;
        this->_every_ms = every_ms;
        this->_ticker = new Ticker;
        this->_ticker_cb = []() {
          // that->_state = !that->_state;
          // *that->_user_state_ptr = that->_state;
          *that->_user_state_ptr = 1;
        };
      }
      ~CMMC_Ticker() {} 
      void start(uint32_t every_ms = 0); 
    private:
      uint8_t *_user_state_ptr = NULL;
      uint32_t _every_ms;
      Ticker *_ticker = NULL;
      cmmc_ticker_cb_t _ticker_cb;
};

#endif //CMMC_Ticker_H
