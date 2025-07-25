/**
 * In the Fibonacci sequence, every third term is even.
 *
 * This is because the parity (even/odd) of Fibonacci numbers follows a
 * repeating pattern:
 *
 *     Index:       0  1  2  3  4  5  6  7  8 ...
 *     Fibonacci:   0, 1, 1, 2, 3, 5, 8,13,21,...
 *     Parity:      E, O, O, E, O, O, E, O, O,...
 *
 * You can observe that: Even, Odd, Odd, Even, Odd, Odd, ...
 * → Every 3rd Fibonacci number (starting from F(0)) is even.
 *
 * Therefore, we can skip computing the full sequence and directly generate only
 * the even terms using a recurrence relation:
 *
 *     E(n) = 4 * E(n-1) + E(n-2)
 *
 * This gives us:
 *     E(1) = 2
 *     E(2) = 8
 *     E(3) = 34
 *     E(4) = 144
 *     ...
 *
 * This optimization significantly reduces the number of computations
 * while producing the same result.
 */

#include <stddef.h>
#include <stdio.h>

size_t sum_of_fibonacci(size_t limit);

int main(void) {
  size_t result = sum_of_fibonacci(4000000);
  printf("Sum of even Fibonacci numbers below 4 million: %zu\n", result);
  return 0;
}

/**
 * @brief Calculate the sum of even fibonacci with upper bound
 *
 * @param limit The upper bound (exclusive) for calculating sum
 * @return Sum of even element of fibonacci till upper bound
 */
size_t sum_of_fibonacci(size_t limit) {
  size_t sum = 0;

  size_t a = 2; // first even fibonnaci number
  size_t b = 8; // second even fibonnaci number

  sum += a;

  while (b < limit) {
    sum += b;

    size_t next = 4 * b + a;
    a = b;
    b = next;
  }

  return sum;
}
