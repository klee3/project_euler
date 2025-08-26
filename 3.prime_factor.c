#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

size_t largest_prime_factor(size_t n);

int main() {
  size_t number = 600851475143;
  size_t largest_factor = largest_prime_factor(number);
  printf("Largest prime factor is: %zu\n", largest_factor);

  return 0;
}

/**
 * @brief Calculate the largest prime factor of a given number
 *
 * This function finds the largest prime factor of the input number `n`.
 * It first removes all factors of 2, then checks for odd factors up to
 * the square root of the current number. If the remaining number after
 * division is greater than 2, it is itself a prime factor and the largest.
 *
 * @param n The number for which to find the largest prime factor
 * @return The largest prime factor of `n`
 */
size_t largest_prime_factor(size_t n) {
  size_t largest_factor = 0;

  while (n % 2 == 0) {
    n /= 2;
    largest_factor = 2;
  }

  /* handle the odd factor from 3 */
  for (size_t i = 3; i <= (size_t)sqrt((double)n); i += 2) {
    while (n % i == 0) {
      largest_factor = i;
      n /= i;
    }
  }

  if (n > 2) {
    largest_factor = n;
  }

  return largest_factor;
}
