#pragma once

#include <stdexcept>

namespace mall {

    inline constexpr int DEFAULT_DISCOUNT_PERCENT = 15;

    inline long long calculateFinalPrice(long long amountCents, int discountPercent)
    {
        if (amountCents < 0 || amountCents > 1'000'000'000LL) {
            throw std::invalid_argument("Amount is out of range");
        }

        if (discountPercent < 0 || discountPercent > 100) {
            throw std::invalid_argument("Discount must be between 0 and 100");
        }

        return (amountCents * (100 - discountPercent) + 50) / 100;
    }

}