#ifndef CPP_BLACKJACK_PLAYER_H
#define CPP_BLACKJACK_PLAYER_H

#include "deck.h"

namespace blackjack::game_participants {

class Player {
 public:
  explicit Player(unsigned int starting_chips) : chips_(starting_chips) {};

  /**
   * Sets the player's hand with the specified cards.
   * @param deck the cards for the player's hand
   */
  void setHand(card_properties::Deck deck);

  /**
   * Resets the player's hand to be empty.
   */
  void resetHand();

 private:
  unsigned int chips_;
  card_properties::Deck hand_;
};

}  // namespace blackjack::game_participants

#endif  // CPP_BLACKJACK_PLAYER_H
