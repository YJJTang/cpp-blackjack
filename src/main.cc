#include <iostream>
#include <random>
#include <algorithm>

#include "deck.h"

int main() {
  std::default_random_engine rng;

  blackjack::card_properties::Deck d;
  d.shuffle(rng);
  std::cout << d << std::endl;
  d.shuffle(rng);
  std::cout << d << std::endl;

  std::cout << d.peek(5) << std::endl;
  std::cout << d << std::endl;


  std::cout << d.pop(3) << std::endl;
  std::cout << d << std::endl;

  return 0;
}

