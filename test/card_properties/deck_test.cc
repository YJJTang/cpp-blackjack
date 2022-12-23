#include <gtest/gtest.h>

#include "card.h"
#include "deck.h"

using Card = blackjack::card_properties::Card;
using Deck = blackjack::card_properties::Deck;

TEST(DeckTest, DefaultConstruction) {
  Deck deck{};

  // Expect default construction creates standard 52 card deck size
  EXPECT_EQ(52, deck.cards().size());
  EXPECT_EQ(Card::Suit::kClubs, deck.cards().front().suit());
  EXPECT_EQ(Card::Value::kAce, deck.cards().front().value());
  EXPECT_EQ(Card::Suit::kSpades, deck.cards().back().suit());
  EXPECT_EQ(Card::Value::kKing, deck.cards().back().value());
}

TEST(DeckTest, ConstructionFromArgs) {
  std::vector<Card> cards;
  Deck empty_deck{cards};

  // Expect empty deck to be created if empty vector provided
  EXPECT_EQ(0, empty_deck.cards().size());

  cards.emplace_back(Card::Suit::kDiamonds, Card::Value::kEight);
  cards.emplace_back(Card::Suit::kSpades, Card::Value::kQueen);

  Deck two_card_hand{cards};
  EXPECT_EQ(2, two_card_hand.cards().size());
//  EXPECT_EQ(cards.at(0), two_card_hand.cards().front());
//  EXPECT_EQ(cards.at(1), two_card_hand.cards().back());

}