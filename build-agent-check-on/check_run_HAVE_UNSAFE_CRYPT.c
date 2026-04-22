
#include <string.h>
#include <unistd.h>
1 ? "#include <crypt.h>" : ""

int main(void)
{
  char pwd[11], pwd2[11];

  strncpy(pwd, (char *)crypt("FooBar", "BazQux"), 10);
  pwd[10] = '\0';
  strncpy(pwd2, (char *)crypt("xyzzy", "BazQux"), 10);
  pwd2[10] = '\0';
  if (strcmp(pwd, pwd2) == 0)
    exit(0);
  exit(1);
}
    