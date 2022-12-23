#include "player.h"

namespace blackjack::game_participants {

void Player::setHand(card_properties::Deck deck) { hand_ = std::move(deck); }

void Player::resetHand() { hand_.cards().clear(); }

}  // namespace blackjack::game_participants
