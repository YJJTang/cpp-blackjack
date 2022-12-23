#include <gtest/gtest.h>

#include "card.h"

using Card = blackjack::card_properties::Card;

TEST(CardTest, ConstructionFromArgs) {
  auto suit_1 = Card::Suit::kClubs;
  auto suit_2 = Card::Suit::kHearts;

  auto value_1 = Card::Value::kAce;
  auto value_2 = Card::Value::kJack;

  Card card_1{suit_1, value_1};
  Card card_2{suit_2, value_2};

  EXPECT_EQ(suit_1, card_1.suit()) << "Card 1 incorrect suit.";
  EXPECT_EQ(suit_2, card_2.suit()) << "Card 2 incorrect suit.";

  EXPECT_EQ(value_1, card_1.value()) << "Card 1 incorrect value.";
  EXPECT_EQ(value_2, card_2.value()) << "Card 2 incorrect value.";
}