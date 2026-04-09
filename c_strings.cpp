#include <cstddef>
#include <iostream>

void capitalize(char string[]);
std::size_t str_len(const char str[]);
void str_invert_case(char str[]);
bool str_starts_with(const char str[], const char prefix[]);
bool str_ends_with(const char str[], const char suffix[]);
unsigned str_count(const char str[], const char sub[]);
bool str_is_ascii(const char str[]);
bool str_is_digit(const char str[]);
long str_index(const char str[], const char sub[]);
void str_copy(char dst[], const char src[], std::size_t dst_size);
bool str_equal(const char first[], const char second[]);
void join(const char* array[], std::size_t count, char str[], const char sep[]);


// ===== Main only for testing =====
// Consts
char special[] = "Some punctuation &;-.: 345 !@# should be ok.";

int main() {
    std::cout << str_len(special) << '\n';
    str_invert_case(special);
    return 0;
}
// ===== End of test main =====


void capitalize(char string[]) {
    // +1 is for null terminator
    std::size_t length = str_len(string) + 1;
    char capitalized[length];
    int i = 0; // to add \0 at the end of capitalized
    for (i = 0; string[i] != '\0'; i++) {
        // check if string[i] is lowercase
        if (string[i] >= 97 && string[i] <= 122) {
            if (i == 0) {
                capitalized[i] = (string[i] - 32);
            }
            // Check begining of string & before current char, is space
            else if (i > 0 && string[i - 1] == ' ') {
                capitalized[i] = (string[i] - 32); // lower are upper +32
            }
            else {
                capitalized[i] = string[i];
            }
        }
        else {
            capitalized[i] = string[i];
        }
    }
    capitalized[i] = '\0'; // add \0 at the end
}


std::size_t str_len(const char str[]) {
    std::size_t length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\0') {
            length--;
        }
        else {
            length++;
        }
    }
    return length;
}


void str_invert_case(char str[]) {
    std::size_t length = str_len(str) + 1;
    char inverted[length];
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        // check if str[i] is lowercase
        if (str[i] >= 97 && str[i] <= 122) {
            inverted[i] = str[i] - 32;
        }
        else if (str[i] >= 65 && str[i] <= 90) {
            inverted[i] = str[i] + 32;
        }
        else {
            inverted[i] = str[i];
        }
    }
    inverted[i] = '\0'; // add \0 at the end
}
