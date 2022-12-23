#include <iostream>

#include "dealer.h"

int main() {
  blackjack::game_participants::Dealer d;
  std::cout << d.deck() << std::endl;

  d.shuffle();
  std::cout << d.deck() << std::endl;

  auto card = d.deal();
  if (card) {
    std::cout << card.value() << std::endl;
  }
  std::cout << d.deck() << std::endl;

  std::cout << d.deal(5) << std::endl;
  std::cout << d.deck() << std::endl;

  return 0;
}
