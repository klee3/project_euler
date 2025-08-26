#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_palindrome(int x);
bool has_n_digit_factors(int palindrome, int n);

int main() {
  int n = 3; // change this for number of digits
  int upper = (int)pow(10, n) - 1;
  int lower = (int)pow(10, n - 1);

  // Largest product possible:
  int max_product = upper * upper;

  // Start from max product and go down
  for (int pal = max_product; pal >= lower * lower; pal--) {
    if (is_palindrome(pal)) {
      if (has_n_digit_factors(pal, n)) {
        printf("Largest palindrome product of two %d-digit numbers is %d\n", n,
               pal);
        break;
      }
    }
  }

  return 0;
}

// Check if number is palindrome
bool is_palindrome(int x) {
  int rev = 0, temp = x;
  while (temp > 0) {
    rev = rev * 10 + temp % 10;
    temp /= 10;
  }
  return rev == x;
}

// Check if palindrome has n-digit factors
bool has_n_digit_factors(int palindrome, int n) {
  int lower = (int)pow(10, n - 1);
  int upper = (int)pow(10, n) - 1;

  for (int i = upper; i >= lower; i--) {
    if (palindrome % i == 0) {
      int other = palindrome / i;
      if (other >= lower && other <= upper) {
        return true;
      }
    }
    // Optional optimization: if i * i < palindrome, break early.
    if (i * i < palindrome)
      break;
  }
  return false;
}
