#include <stddef.h>
#include <stdio.h>

size_t sum_of_multiple(size_t n, size_t limit);

int main() {
  size_t limit = 1000;
  size_t result = sum_of_multiple(3, limit) + sum_of_multiple(5, limit) -
                  sum_of_multiple(3 * 5, limit);

  printf("Result: %ld\n", result);
  return 0;
}

/**
 * @brief Calculates the sum of all natural numbers less than a given limit
 *        that are divisible by a specified number.
 *
 * @param n     The number whose multiples will be summed.
 * @param limit The upper bound (exclusive) for checking multiples.
 * @return The sum of all natural numbers less than `limit` that are divisible
 *         by `n`.
 *
 * The multiples of `n` less than `limit` form an arithmetic sequence:
 *     n, 2n, 3n, ..., kn  where k = (limit - 1) / n
 *
 * Factor out n: n × (1 + 2 + ... + k)
 * Use formula:   1 + 2 + ... + k = k × (k + 1) / 2
 * Final sum:     n × k × (k + 1) / 2
 */
size_t sum_of_multiple(size_t n, size_t limit) {

  if (n == 0) {
    return 0;
  }

  size_t count = (limit - 1) / n;
  return n * count * (count + 1) / 2;
}
