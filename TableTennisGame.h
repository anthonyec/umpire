#ifndef TABLE_TENNIS_GAME_H
#define TABLE_TENNIS_GAME_H

#include "Arduino.h"

class TableTennisGame {
  public:
    TableTennisGame();
    void addScoreForPlayer(uint8_t playerIndex);
    void subtractScoreForPlayer(uint8_t playerIndex);
    void reset();
    void setInitalServer(uint8_t playerIndex);
    void flipInitialServer();
    uint8_t getScoreForPlayer(uint8_t playerIndex);
    void parse(String data);
    String stringify();

  private:
    uint8_t score[2];
    uint8_t initalServe[2];
};

#endif
