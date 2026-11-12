# mall-system

A small C++ coupon calculator for a GitFlow collaboration lab.

## Roles

- PM-Bob: kepti
- Dev-Alice: weekoffer0-978e687a

## Branches

- main: stable production code
- develop: integration branch
- feature/*: feature development
- release/*: release preparation

## Build

Run in Visual Studio Developer PowerShell:

```powershell
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
.\build\mall.exe
```
## Version 1.0.0

- Implement coupon calculation.
- Validate amount and discount input.
- Use a default discount of 20 percent.
- Add unit checks for normal, boundary, and invalid input.

## Test

Run in Visual Studio Developer PowerShell after building:

.\build\coupon_tests.exe
ctest --test-dir build --output-on-failure