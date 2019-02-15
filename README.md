# Umpire
Arduino library to track a table tennis match.

**⚠️Warning:** This library currently work in progress. Also I love getting to use the warning emoji.

## Quickstart

```c++
#include <Umpire.h>

Umpire game;

void setup() {
  // Add 1 point for player 1.
  game.addScoreForPlayer(0);
  
  // Add 1 point for player 2
  game.addScoreForPlayer(1);
  
  // Get which player is serving
  game.getPlayerServing();
   
  // Reset the game
  game.reset();
  
  // Set player 2 to start serving
  game.setInitialServer(1);
  
  // Set player 1 to start serving
  game.flipInitialServer();
};

```
