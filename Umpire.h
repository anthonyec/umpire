#ifndef TABLE_TENNIS_GAME_H
#define TABLE_TENNIS_GAME_H

#include "Arduino.h"

class Umpire {
  public:
    static const uint8_t kEventChange = 1;
    static const uint8_t kEventReset = 2;
    static const uint8_t kEventUndo = 3;
    static const uint8_t kEventDeuce = 4;

    // Function pointer definition for event handler
    typedef void(*EventHandler)(uint8_t);

    Umpire();
    void setEventHandler(EventHandler callback);
    void addScoreForPlayer(uint8_t playerIndex); // t
    void subtractScoreForPlayer(uint8_t playerIndex); // t
    void reset(); // t
    void setInitialServer(uint8_t playerIndex); // t
    void setServesEach(uint8_t number); // t
    void flipInitialServer(); // t
    uint8_t getScoreForPlayer(uint8_t playerIndex); // t
    uint8_t getScoreTotal(); // t
    uint8_t getScoreDifference(); // t
    uint8_t getPlayerServing(); // t

  private:
    uint8_t score[2];
    uint8_t initialSideToServe = 0;
    uint8_t numberOfServesEach;
    EventHandler mEventHandler;
};

#endif
