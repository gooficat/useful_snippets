#include <cstdint>
#include <string>

uint32_t str_to_binary_uint32(const std::string& s) {
    uint32_t result = 0;
    int mult = 1; 
    for (int i = s.length() - 1;i != -1; i--) {
        if (s.at(i) == '1') {
            result += mult;
        }
        mult *= 2;
    }

    return result;
}