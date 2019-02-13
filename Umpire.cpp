#include <math.h>

#include "Umpire.h"

Umpire::Umpire()
// Intialisation list
: numberOfServesEach(2)
{
  // Array can only be assigned by stating the type
  uint8_t score[2] = {0, 0};
  uint8_t initalServe[2] = {0, 1};
}

void Umpire::addScoreForPlayer(uint8_t playerIndex) {
  score[playerIndex] += 1;
};

void Umpire::subtractScoreForPlayer(uint8_t playerIndex) {
  int8_t newScore = score[playerIndex] - 1;
  uint8_t scoreToSubtract = newScore < 0 ? 0 : 1;
  score[playerIndex] -= scoreToSubtract;
};

void Umpire::reset() {
 score[0] = 0;
 score[1] = 0;
};

void Umpire::setServesEach(uint8_t number) {
  numberOfServesEach = number;
};

void Umpire::setInitalServer(uint8_t playerIndex) {
  if (playerIndex == 1) {
    initalServe[0] = 1;
    initalServe[1] = 0;
  } else {
    initalServe[0] = 0;
    initalServe[1] = 1;
  }
};

void Umpire::flipInitialServer() {
  uint8_t temp0 = initalServe[0];
  initalServe[0] = initalServe[1];
  initalServe[1] = temp0;
};

uint8_t Umpire::getScoreDifference() {
  return abs(score[0] - score[1]);
};

uint8_t Umpire::getScoreTotal() {
  return score[0] + score[1];
};

uint8_t Umpire::getPlayerServing() {
  uint8_t scoreTotal = Umpire::getScoreTotal();
  return fmod(floor((double)scoreTotal / numberOfServesEach), 2);
};

uint8_t Umpire::getScoreForPlayer(uint8_t playerIndex) {
  return score[playerIndex];
};

