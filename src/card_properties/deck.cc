#include "deck.h"

#include <algorithm>
#include <random>

namespace blackjack::card_properties {

Deck::Deck() {
  cards_.reserve(kDefaultDeckSize);
  for (const auto value : utility::enum_range(Card::Value::kAce, Card::Value::kKing)) {
    for (const auto suit : utility::enum_range(Card::Suit::kClubs, Card::Suit::kSpades)) {
      cards_.emplace_back(suit, value);
    }
  }
}

template <typename URBG>
void Deck::shuffle(URBG&& rng) {
  std::shuffle(cards_.begin(), cards_.end(), rng);
}

Deck Deck::peek(unsigned int n) {
  return Deck{{cards_.begin(), n > cards_.size() ? cards_.end() : cards_.begin() + n}};
}

Card Deck::peek() { return Deck::peek(1).pop(); }

Deck Deck::pop(unsigned int n) {
  Deck ret{{cards_.begin(), n > cards_.size() ? cards_.end() : cards_.begin() + n}};

  if (n > cards_.size()) {
    cards_.clear();
  } else {
    cards_ = std::vector<Card>{cards_.begin() + n, cards_.end()};
  }

  return ret;
}

Card Deck::pop() { return Deck::pop(1).cards_.at(0); }

}  // namespace blackjack::card_properties