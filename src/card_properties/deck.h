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
  explicit Deck(const std::vector<Card>& cards) : cards_(cards){};

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
  std::optional<Card> peek();

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
  std::optional<Card> pop();

  /**
   * Returns a reference to the list of cards in the deck
   * @return a reference to the vector of cards
   */
  std::vector<Card>& cards() { return cards_; };

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
