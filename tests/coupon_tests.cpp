#include <iostream>
#include <stdexcept>
#include <string>
#include "coupon.h"

int failures = 0;

void expectEqual(
    const std::string& name,
    long long actual,
    long long expected)
{
    if (actual == expected) {
        std::cout << "[PASS] " << name << '\n';
    }
    else {
        std::cout << "[FAIL] " << name
            << ": expected " << expected
            << ", got " << actual << '\n';
        ++failures;
    }
}

template <typename Function>
void expectInvalidArgument(
    const std::string& name,
    Function action)
{
    try {
        action();
        std::cout << "[FAIL] " << name
            << ": no exception\n";
        ++failures;
    }
    catch (const std::invalid_argument&) {
        std::cout << "[PASS] " << name << '\n';
    }
    catch (...) {
        std::cout << "[FAIL] " << name
            << ": wrong exception type\n";
        ++failures;
    }
}

int main()
{
    expectEqual(
        "normal discount",
        mall::calculateFinalPrice(10000, 20),
        8000);

    expectEqual(
        "zero amount",
        mall::calculateFinalPrice(0, 20),
        0);

    expectEqual(
        "zero discount",
        mall::calculateFinalPrice(10000, 0),
        10000);

    expectEqual(
        "full discount",
        mall::calculateFinalPrice(10000, 100),
        0);

    expectEqual(
        "round half up",
        mall::calculateFinalPrice(101, 50),
        51);

    expectEqual(
        "maximum amount",
        mall::calculateFinalPrice(1'000'000'000LL, 20),
        800'000'000LL);

    expectInvalidArgument("negative amount", [] {
        mall::calculateFinalPrice(-1, 20);
        });

    expectInvalidArgument("amount above limit", [] {
        mall::calculateFinalPrice(1'000'000'001LL, 20);
        });

    expectInvalidArgument("negative discount", [] {
        mall::calculateFinalPrice(10000, -1);
        });

    expectInvalidArgument("discount above 100", [] {
        mall::calculateFinalPrice(10000, 101);
        });

    if (failures == 0) {
        std::cout << "All 10 checks passed.\n";
        return 0;
    }

    std::cout << failures << " check(s) failed.\n";
    return 1;
}