// Macro test helpers
#define repeat(n) for(int ii = 0; ii < n; ++ ii)

#include <AUnit.h>
using namespace aunit;

#include <Umpire.h>

Umpire game;

// Test helpers
void beforeEach() {
  game.reset();
};

// Tests
test(reset) {
  beforeEach();

  game.addScoreForPlayer(0);
  game.addScoreForPlayer(1);
  game.setInitialServer(1);
  game.reset();

  uint8_t scorePlayer1 = game.getScoreForPlayer(0);
  uint8_t scorePlayer2 = game.getScoreForPlayer(1);
  uint8_t intialServer = game.getPlayerServing();

  assertEqual(scorePlayer1, 0);
  assertEqual(scorePlayer2, 0);
  assertEqual(intialServer, 0);
}

test(addScoreForPlayer) {
  beforeEach();

  repeat(3) {
    game.addScoreForPlayer(0);
  }

  repeat(2) {
    game.addScoreForPlayer(1);
  }

  uint8_t scorePlayer1 = game.getScoreForPlayer(0);
  uint8_t scorePlayer2 = game.getScoreForPlayer(1);

  assertEqual(scorePlayer1, 3);
  assertEqual(scorePlayer2, 2);
}

test(subtractScoreForPlayer) {
  beforeEach();

  repeat(2) {
    game.addScoreForPlayer(0);
  }

  repeat(2) {
    game.addScoreForPlayer(1);
  }

  game.subtractScoreForPlayer(0);

  // Call subtract once extra to test score does not go below zero.
  repeat(3) {
    game.subtractScoreForPlayer(1);
  }

  uint8_t scorePlayer1 = game.getScoreForPlayer(0);
  uint8_t scorePlayer2 = game.getScoreForPlayer(1);

  assertEqual(scorePlayer1, 1);
  assertEqual(scorePlayer2, 0);
}

test(getScoreTotal) {
  beforeEach();

  repeat(2) {
    game.addScoreForPlayer(0);
  }

  repeat(5) {
    game.addScoreForPlayer(1);
  }

  uint8_t totalScore = game.getScoreTotal();

  assertEqual(totalScore, 7);
}

test(getScoreDifference) {
  beforeEach();

  repeat(2) {
    game.addScoreForPlayer(0);
  }

  repeat(5) {
    game.addScoreForPlayer(1);
  }

  uint8_t scoreDifference = game.getScoreDifference();

  assertEqual(scoreDifference, 3);
}

test(getScoreForPlayer) {
  beforeEach();

  repeat(5) {
    game.addScoreForPlayer(0);
  }

  repeat(2) {
    game.addScoreForPlayer(1);
  }

  uint8_t player1Score = game.getScoreForPlayer(0);
  uint8_t player2Score = game.getScoreForPlayer(1);

  assertEqual(player1Score, 5);
  assertEqual(player2Score, 2);
}

test(getPlayerServing_2_serves_each) {
  beforeEach();

  // Game score: 0-0
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 1-0
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 2-0
  assertEqual(game.getPlayerServing(), 1);

  game.addScoreForPlayer(1);

  // Game score: 2-1
  assertEqual(game.getPlayerServing(), 1);

  game.addScoreForPlayer(0);

  // Game score: 3-1
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 3-2
  assertEqual(game.getPlayerServing(), 0);
}

test(getPlayerServing_5_serves_each) {
  beforeEach();

  game.setServesEach(5);

  // Game score: 0-0
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 1-0
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 2-0
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(1);

  // Game score: 2-1
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 3-1
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 3-2
  assertEqual(game.getPlayerServing(), 1);
}

test(getPlayerServing_deuce_2_serves_each) {
  beforeEach();

  repeat(10) {
    game.addScoreForPlayer(0);
  }

  repeat(10) {
    game.addScoreForPlayer(1);
  }

  // Game score: 10-10
  // Player 0 would have 2 serves now usually, but as the
  // score is >= 20, it is now duece. Player 0 only has 1 serve.
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(0);

  // Game score: 11-10
  assertEqual(game.getPlayerServing(), 1);

  game.addScoreForPlayer(1);

  // Game score: 11-11
  assertEqual(game.getPlayerServing(), 0);

  game.addScoreForPlayer(1);

  // Game score: 11-12
  assertEqual(game.getPlayerServing(), 1);
}

void setup() {
  delay(1000);
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  TestRunner::run();
}
