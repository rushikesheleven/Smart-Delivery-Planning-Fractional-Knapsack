# Smart Delivery Planning - Fractional Knapsack

## Problem Statement

A delivery company has a vehicle with a fixed carrying capacity and several packages. Each package has a specific weight and value/profit.

The vehicle can carry packages up to its maximum capacity. A complete package or a fraction of a package can be selected. The objective is to maximize the total value carried by the vehicle.

This problem is solved using the **Fractional Knapsack Greedy Algorithm**.

## Objectives

- Understand the Greedy Method.
- Calculate the Value/Weight ratio of each package.
- Sort packages in decreasing order of Value/Weight ratio.
- Select complete packages whenever possible.
- Select a fraction of a package when the remaining capacity is insufficient.
- Calculate the maximum achievable value.
- Analyze the time and space complexity.

## Algorithm

1. Enter the number of packages.
2. Enter the value and weight of each package.
3. Calculate the Value/Weight ratio for every package.
4. Sort the packages in decreasing order of their Value/Weight ratio.
5. Start selecting packages from the highest ratio.
6. If the complete package fits in the remaining capacity, select it completely.
7. Otherwise, select the fraction of the package that can fit.
8. Calculate the total value obtained.
9. Display the selected packages, total weight used, and maximum value.

## Example

### Input

| Package | Value | Weight |
|--------:|------:|-------:|
| 1 | 40 | 5 |
| 2 | 30 | 10 |
| 3 | 50 | 5 |
| 4 | 20 | 4 |

Vehicle Capacity:

```text
15
