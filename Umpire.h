#ifndef TABLE_TENNIS_GAME_H
#define TABLE_TENNIS_GAME_H

#include "Arduino.h"

class Umpire {
  public:
    Umpire();
    void addScoreForPlayer(uint8_t playerIndex);
    void subtractScoreForPlayer(uint8_t playerIndex);
    void reset();
    void setInitalServer(uint8_t playerIndex);
    void flipInitialServer();
    uint8_t getScoreForPlayer(uint8_t playerIndex);
    void parse(String data);
    String stringify();
    uint8_t getScoreTotal();
    uint8_t getScoreDifference();

    uint8_t getPlayerServing();

  private:
    uint8_t score[2];
    uint8_t initalServe[2];
    uint8_t numberOfServesEach;
};

#endif
