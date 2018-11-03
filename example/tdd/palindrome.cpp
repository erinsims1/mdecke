#include "palindrome.hpp"

/** first empty */
// bool is_palindrome(const std::string & str) {
//     return true;    
// }

/** second, two diff char */
// bool is_palindrome(const std::string & str) {
//     return str.size() == 0;    
// }

/** single char, closer to a solution */
// bool is_palindrome(const std::string & str) {
//     if(str.size() == 2) return false;

//     return true;    
// }


/** forks for two char */
// bool is_palindrome(const std::string & str) {
//     if(str.size() == 2) return str[0] == str[1];

//     return true;    
// }

/** three char, maybe show breaking old tests having >= 3 */
// bool is_palindrome(const std::string & str) {
//     if(str.size() >= 2) return str.front() == str.back();

//     return true;    
// }

/** generic loop version */
bool is_palindrome(const std::string & str) {
    size_t length = str.size();
    size_t num_checks = length / 2;
    for(int offset = 0; offset < num_checks; ++offset) {
        if(str[offset] != str[length - offset - 1])
            return false;
    }

    return true;    
}
