#include <iostream>

void print_bits(uint8_t d) {
  uint8_t tmp{1};
  tmp <<= sizeof(d) * 8 - 1;
  while (tmp) {
    if ((tmp & d) > 0)
      std::cout << 1;
    else
      std::cout << 0;
    tmp >>= 1;
  }
  std::cout << std::endl;
}

uint8_t flip_bits(uint8_t d) {
  return ~d;
}

int main(int argc, char* argv[]) {
  print_bits(156);
  print_bits(flip_bits(156));
  return 0;
}
