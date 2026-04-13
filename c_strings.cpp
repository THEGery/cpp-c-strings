#include <cstddef>
// #include <iostream>

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
/* char lower[] = "abcdef ghijklmnopqrstuvwxyz";
char upper[] = "ABCDEF GHIJK";
char mixed[] = "The quick brown Fox jumps over the lazy Dog.";
char special[] = "Some punctuation &;-.: 345 !@# should be ok."; */

/* int main() {
    // capitalize(special);
    // std::cout << "Length: " << str_len(special) << '\n';
    str_invert_case(lower);
    str_invert_case(upper);
    str_invert_case(mixed);
    str_invert_case(special);
    // std::cout << "Starts with: " << str_starts_with(special, "Some p") << '\n';
    return 0;
}
// ===== End of test main ===== */


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

    // std::cout << "Capitalize: " << capitalized << '\n';
}


std::size_t str_len(const char str[]) {
    std::size_t length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}


void str_invert_case(char str[]) {
    // std::size_t length = str_len(str) + 1;
    // char inverted[length];
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        // check if str[i] is lowercase
        if (str[i] >= 97 && str[i] <= 122) {
            // inverted[i] = str[i] - 32;
            str[i] -= 32;
        }
        else if (str[i] >= 65 && str[i] <= 90) {
            // inverted[i] = str[i] + 32;
            str[i] += 32;
        }
        else {
            // inverted[i] = str[i];
        }
    }
    // inverted[i] = '\0'; // add \0 at the end
    // TESTING
    // std::cout << "Inverted: " << inverted << '\n';
}


bool str_starts_with(const char str[], const char prefix[]) {
    int pref_length = (int)str_len(prefix);
    int str_length = (int)str_len(str);
    bool state = false;
    if (pref_length > str_length) {
        return false;
    }
    else if (pref_length == 0) {
        return true;
    }
    else {
        for (int i = 0; i < pref_length; i++) {
            if (str[i] == prefix[i]) {
                state = true;
            }
            else {
                return false;
            }
        }
    }
    return state;
}


bool str_ends_with(const char str[], const char suffix[]) {
    return false;
}


unsigned str_count(const char str[], const char sub[]) {
    return 0;
}


bool str_is_ascii(const char str[]) {
    return false;
}


bool str_is_digit(const char str[]) {
    return false;
}


long str_index(const char str[], const char sub[]) {
    return 0;
}


void str_copy(char dst[], const char src[], std::size_t dst_size) {

}


bool str_equal(const char first[], const char second[]) {
    return false;
}


void join(const char* array[], std::size_t count, char str[], const char sep[]) {

}