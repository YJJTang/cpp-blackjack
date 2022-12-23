#ifndef CPP_BLACKJACK_DEALER_H
#define CPP_BLACKJACK_DEALER_H

#include <random>

#include "deck.h"

namespace blackjack::game_participants {

class Dealer {
 public:
  Dealer() : rng_(rd_()){};

  /**
   * Shuffles the deck using a uniform random bit generator.
   */
  void shuffle();

  /**
   * Deals the top n cards of the deck, if the deck contains cards.
   * @param n the number of cards to be dealt
   * @return the top n cards from the deck
   */
  card_properties::Deck deal(unsigned int n);

  /**
   * Deals the top card of the deck, if the deck contains cards.
   * @return the top card from the deck
   */
  std::optional<card_properties::Card> deal();

  /**
   * Returns a copy of the dealer's deck.
   * @return a copy of the dealer's deck
   */
  card_properties::Deck deck() { return deck_; }

 private:
  card_properties::Deck deck_;

  std::random_device rd_;
  std::mt19937 rng_;
};

}  // namespace blackjack::game_participants

#endif  // CPP_BLACKJACK_DEALER_H
