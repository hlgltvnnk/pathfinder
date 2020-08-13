#include "../inc/libmx.h"

bool mx_isspace(char c) {
 if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == ' ' || c == '\f')
  return true;
 return false;
}
