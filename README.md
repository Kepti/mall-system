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

cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
.\build\mall.exe