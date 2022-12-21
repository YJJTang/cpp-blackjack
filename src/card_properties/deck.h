#ifndef CPP_BLACKJACK_DECK_H
#define CPP_BLACKJACK_DECK_H

#include <vector>

#include "card.h"
#include "util.h"

namespace blackjack::card_properties {

class Deck {
 public:
  /**
   * Constructor. Populates Deck with standard set of 52 cards.
   */
  Deck();

  /**
   * Constructor. Creates a deck object with the specified set of cards.
   * @param cards the set of cards in the new deck
   */
  explicit Deck(const std::vector<Card>& cards) : cards_(cards) {};

  /**
   * Shuffles the deck using the uniform random bit generator.
   * @tparam URBG Uniform Random Bit Generator. The type of RNG engine for shuffling
   * @param rng the specific URBG to be used for this shuffle
   */
  template<typename URBG>
  void shuffle(URBG&& rng);

  /**
   * Peeks the top n cards in order (i.e. top card 1st in output), and returns them in the same order.
   * @param n the number of cards to look at
   * @return the top n cards, in the same order as the main deck
   */
  Deck peek(unsigned int n);

  /**
   * Peeks the top card, and places it back on the top.
   * @return the top card
   */
  Card peek();

  /**
   * Pops the top n cards in order (i.e. top card 1st in output), and removes them from the deck.
   * @param n the number of cards to pop
   * @return the top n cards, in the same order as the main deck
   */
  Deck pop(unsigned int n);

  /**
   * Pops the top card.
   * @return the top card
   */
  Card pop();

  // Operators
  friend std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    for (const auto& card : deck.cards_) {
      os << card;
    }
    os << std::endl;
    return os;
  }

 private:
  std::vector<Card> cards_;

  static const size_t kDefaultDeckSize = 52;
};

}  // namespace blackjack::card_properties

#endif  // CPP_BLACKJACK_DECK_H
