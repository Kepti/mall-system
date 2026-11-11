#pragma once


namespace mall {

    inline constexpr int DEFAULT_DISCOUNT_PERCENT = 20;

    // Initial placeholder. The feature branch will implement the calculation.
    inline long long calculateFinalPrice(long long amountCents, int discountPercent)
    {
        (void)discountPercent;
        return amountCents;
    }

}