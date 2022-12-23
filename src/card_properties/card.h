#ifndef CPP_BLACKJACK_CARD_H
#define CPP_BLACKJACK_CARD_H

#include <compare>
#include <sstream>

namespace blackjack::card_properties {

class Card {
 public:
  enum class Suit { kClubs, kDiamonds, kHearts, kSpades };
  enum class Value { kAce = 1, kTwo, kThree, kFour, kFive, kSix, kSeven, kEight, kNine, kTen, kJack, kQueen, kKing };

  // Constructor
  Card(const Suit& suit, const Value& value) : suit_(suit), value_(value){};

  // Operators
  auto operator<=>(const Card& other) const { return value_ <=> other.value_; }

  friend std::ostream& operator<<(std::ostream& os, const Card& card) {
    // TODO: Investigate better method for enum value to_string
    os << "[";
    switch (card.value_) {
      case (Value::kAce):
        os << "A";
        break;
      case (Value::kTwo):
        os << "2";
        break;
      case (Value::kThree):
        os << "3";
        break;
      case (Value::kFour):
        os << "4";
        break;
      case (Value::kFive):
        os << "5";
        break;
      case (Value::kSix):
        os << "6";
        break;
      case (Value::kSeven):
        os << "7";
        break;
      case (Value::kEight):
        os << "8";
        break;
      case (Value::kNine):
        os << "9";
        break;
      case (Value::kTen):
        os << "10";
        break;
      case (Value::kJack):
        os << "J";
        break;
      case (Value::kQueen):
        os << "Q";
        break;
      case (Value::kKing):
        os << "K";
        break;
        // Omit default case to trigger compiler warning for missing cases
    }
    switch (card.suit_) {
      case (Suit::kClubs):
        os << "♠";
        break;
      case (Suit::kDiamonds):
        os << "♦";
        break;
      case (Suit::kHearts):
        os << "♥";
        break;
      case (Suit::kSpades):
        os << "♠";
        break;
        // Omit default case to trigger compiler warning for missing cases
    }

    os << "]";
    return os;
  };

  Suit suit() { return suit_; }
  Value value() { return value_; }

 private:
  Suit suit_;
  Value value_;
};

}  // namespace blackjack::card_properties

#endif  // CPP_BLACKJACK_CARD_H
