#ifndef CPP_BLACKJACK_UTIL_H
#define CPP_BLACKJACK_UTIL_H

#include <ranges>
#include <utility>

namespace blackjack::utility {

constexpr inline auto enum_range = [](auto front, auto back) {
  return std::views::iota(std::to_underlying(front), std::to_underlying(back) + 1) |
         std::views::transform([](auto e) { return decltype(front)(e); });
};

}

#endif  // CPP_BLACKJACK_UTIL_H
