#include "deck.h"

#include <algorithm>
#include <iostream>
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

Deck Deck::peek(unsigned int n) {
  return Deck{{cards_.begin(), n > cards_.size() ? cards_.end() : cards_.begin() + n}};
}

std::optional<Card> Deck::peek() {
  auto deck = Deck::peek(1);
  if (deck.cards_.empty()) {
    std::cout << "No more cards in deck. Cannot peek." << std::endl;
    return std::nullopt;
  }

  return Deck::peek(1).pop();
}

Deck Deck::pop(unsigned int n) {
  Deck ret{{cards_.begin(), n > cards_.size() ? cards_.end() : cards_.begin() + n}};

  if (n > cards_.size()) {
    cards_.clear();
  } else {
    cards_ = std::vector<Card>{cards_.begin() + n, cards_.end()};
  }

  return ret;
}

std::optional<Card> Deck::pop() {
  auto deck = Deck::pop(1);

  if (deck.cards_.empty()) {
    std::cout << "No more cards in deck. Cannot pop." << std::endl;
    return std::nullopt;
  }

  return deck.cards_.at(0);
}

}  // namespace blackjack::card_properties