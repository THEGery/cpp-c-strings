#include <cstddef>
#include <sys/types.h>
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


/* // ===== Main only for testing =====
// Consts
char extended[] = "umlauts (äöü) are not.";

int main() {
    str_is_ascii(extended);
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
    // -1 due to "o indexed" char array
    // str[45] = 1-45 -> minus null-term. = 1-44
    // When used as index it's: 0-43!!
    int suffix_length = (int)str_len(suffix);
    int str_length = (int)str_len(str);
    bool state = false;
    if (suffix_length > str_length) {
        return false;
    }
    else if (suffix_length == 0) {
        return true;
    }
    else {
        for (int i = (int)str_length - 1, j = (int)suffix_length - 1; j >= 0; i--, j--) {
            if (str[i] == suffix[j]) {
                state = true;
            }
            else {
                return false;
            }
        }
    }
    return state;
}


unsigned str_count(const char str[], const char sub[]) {
    int sub_len = (int)str_len(sub);
    int occurance = 0;

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] == sub[j]) {
            // j+1 to evaluate 'til above if is true
            if (j + 1 == sub_len) {occurance++;}
            j++;
        }
        else {
            j = 0;
        }
    }
    return static_cast<unsigned>(occurance);
}


bool str_is_ascii(const char str[]) {
    bool state = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((uint)str[i] < 128) {
            state = true;
        }
        else {
            return false;
        }
    }
    return state;
}


bool str_is_digit(const char str[]) {
    bool state = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            state = true;
        }
        else {
            return false;
        }
    }
    return state;
}


long str_index(const char str[], const char sub[]) {
    int sub_len = (int)str_len(sub);
    long first = 0;
    bool found = false;

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] == sub[j]) {
            if (j + 1 == sub_len) {
                first = i - j;
                found = true;
            }
            j++;
        }
        else {
            j = 0;
        }

        if (found == true) {
            break;
        }
    }
    return first;
}


void str_copy(char dst[], const char src[], std::size_t dst_size) {

}


bool str_equal(const char first[], const char second[]) {
    return false;
}


void join(const char* array[], std::size_t count, char str[], const char sep[]) {

}