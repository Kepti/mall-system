#include <iostream>
#include "coupon.h"

int main()
{
    // Deliberately fake value for the code review exercise.
    const char* testApiKey = "DEMO_ONLY_NOT_A_REAL_SECRET";
    (void)testApiKey;

    const long long amountCents = 10000;

    std::cout << "Original amount (cents): " << amountCents << '\n';
    std::cout << "Discount percent: "
        << mall::DEFAULT_DISCOUNT_PERCENT << '\n';
    std::cout << "Final amount (cents): "
        << mall::calculateFinalPrice(
            amountCents,
            mall::DEFAULT_DISCOUNT_PERCENT)
        << '\n';

    return 0;
}