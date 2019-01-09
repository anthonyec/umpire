#include "TableTennisGame.h"

TableTennisGame::TableTennisGame() {
  uint8_t score[2] = {0, 0};
  uint8_t initalServe[2] = {0, 1};
};

void TableTennisGame::addScoreForPlayer(uint8_t playerIndex) {
  score[playerIndex] += 1;
};

void TableTennisGame::subtractScoreForPlayer(uint8_t playerIndex) {
  uint8_t newScore = score[playerIndex] - 1;
  score[playerIndex] -= (newScore > 0) ? 1 : 0;
};

void TableTennisGame::reset() {
 score[0] = 0;
 score[1] = 0;
};

void TableTennisGame::setInitalServer(uint8_t playerIndex) {

};

void TableTennisGame::flipInitialServer() {
  uint8_t temp0 = initalServe[0];
  initalServe[0] = initalServe[1];
  initalServe[1] = temp0;
};

uint8_t TableTennisGame::getScoreForPlayer(uint8_t playerIndex) {
  return score[playerIndex];
}

