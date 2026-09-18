#include <cstdlib>
#include <new>

typedef unsigned __int64 size_t;
typedef unsigned short uint16_t;

extern "C" {

// __std_replace_copy_2: replaces 16-bit elements from [first, last) to dest
uint16_t* __cdecl __std_replace_copy_2(
    const uint16_t* first,
    const uint16_t* last,
    uint16_t* dest,
    uint16_t old_val,
    uint16_t new_val) noexcept
{
    while (first != last) {
        uint16_t val = *first++;
        if (val == old_val) {
            val = new_val;
        }
        *dest++ = val;
    }
    return dest;
}

// __std_find_first_not_of_trivial_pos_1: find_first_not_of for 1-byte elements
size_t __cdecl __std_find_first_not_of_trivial_pos_1(
    const void* haystack,
    size_t haystack_length,
    const void* needle,
    size_t needle_length) noexcept
{
    const auto* h = static_cast<const unsigned char*>(haystack);
    const auto* n = static_cast<const unsigned char*>(needle);
    for (size_t i = 0; i < haystack_length; ++i) {
        bool found = false;
        for (size_t j = 0; j < needle_length; ++j) {
            if (h[i] == n[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return static_cast<size_t>(-1);
}

// __std_regex_transform_primary_char: transforms string to primary sort key (lowercased)
size_t __cdecl __std_regex_transform_primary_char(
    void* /* str_obj */,
    char* dest,
    const char* first,
    const char* last,
    const void* /* traits */) noexcept
{
    size_t len = static_cast<size_t>(last - first);
    if (dest) {
        for (size_t i = 0; i < len; ++i) {
            unsigned char c = static_cast<unsigned char>(first[i]);
            if (c >= 'A' && c <= 'Z') {
                c += ('a' - 'A');
            }
            dest[i] = static_cast<char>(c);
        }
    }
    return len;
}

} // extern "C"

namespace fmt {
inline namespace v12 {
namespace detail {
    void* allocate(unsigned __int64 size) {
        void* p = std::malloc(size);
        if (!p) throw std::bad_alloc();
        return p;
    }
}
}
}
