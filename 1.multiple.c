#include <stddef.h>
#include <stdio.h>

size_t sum_of_multiple(size_t limit);

int main() {
  size_t result = sum_of_multiple(1000);
  printf("Result: %ld\n", result);
  return 0;
}

/**
 * @brief Calculates the sum of all multiples of 3 or 5 below a given limit.
 *
 * @param limit The upper bound (exclusive) for checking multiples
 * @return The sum of all natural numbers below `limit` that are divisible by 3
 * or 5.
 *
 */
size_t sum_of_multiple(size_t limit) {
  size_t sum = 0;

  for (size_t i = 0; i < limit; ++i) {
    if ((i % 3 == 0 || i % 5 == 0)) {
      sum += i;
    }
  }
  return sum;
}
