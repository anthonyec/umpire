#ifndef TABLE_TENNIS_GAME_H
#define TABLE_TENNIS_GAME_H

#include "Arduino.h"

class Umpire {
  public:
    Umpire();
    void addScoreForPlayer(uint8_t playerIndex); // t
    void subtractScoreForPlayer(uint8_t playerIndex); // t
    void reset(); // t
    void setInitalServer(uint8_t playerIndex);
    void setServesEach(uint8_t number);
    void flipInitialServer();
    uint8_t getScoreForPlayer(uint8_t playerIndex); // t
    void parse(String data);
    String stringify();
    uint8_t getScoreTotal(); // t
    uint8_t getScoreDifference(); // t
    uint8_t getPlayerServing();

  private:
    uint8_t score[2];
    uint8_t initalServe[2];
    uint8_t numberOfServesEach;
};

#endif
