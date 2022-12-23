#include "dealer.h"

#include <algorithm>

namespace blackjack::game_participants {

void Dealer::shuffle() { std::shuffle(deck_.cards().begin(), deck_.cards().end(), rng_); }

card_properties::Deck Dealer::deal(unsigned int n) { return deck_.pop(n); }

std::optional<card_properties::Card> Dealer::deal() { return deck_.pop(); }

}  // namespace blackjack::game_participants
