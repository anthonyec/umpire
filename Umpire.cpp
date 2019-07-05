#include <math.h>

#include "Umpire.h"

Umpire::Umpire()
// Intialisation list
: numberOfServesEach(2),
  initialSideToServe(0),
  winScore(11)
{
  // Array can only be assigned by stating the type
  uint8_t score[2] = {0, 0};
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
 initialSideToServe = 0;
};

void Umpire::setServesEach(uint8_t number) {
  numberOfServesEach = number;
};

void Umpire::setInitialServer(uint8_t playerIndex) {
  initialSideToServe = playerIndex;
};

void Umpire::flipInitialServer() {
  initialSideToServe = initialSideToServe ^ 1;
};

uint8_t Umpire::getScoreDifference() {
  return abs(score[0] - score[1]);
};

uint8_t Umpire::getScoreTotal() {
  return score[0] + score[1];
};

uint8_t Umpire::getPlayerServing() {
  uint8_t scoreTotal = Umpire::getScoreTotal();
  bool deuce = scoreTotal >= ((winScore * 2) - 2);
  uint8_t servesEach = deuce ? 1 : numberOfServesEach;
  uint8_t serving = fmod(floor((double)scoreTotal / servesEach), 2);

  return serving ^ initialSideToServe;
};

uint8_t Umpire::getScoreForPlayer(uint8_t playerIndex) {
  return score[playerIndex];
};

