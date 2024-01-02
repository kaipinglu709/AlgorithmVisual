// Data_Compression.hpp

#pragma once
#include <string>
#include <sstream>

class DataCompression {
public:
    // Run-Length Encoding (RLE) Compression
    static std::string runLengthEncode(const std::string& input) {
        if (input.empty()) return "";

        std::ostringstream encoded;
        int count = 1;

        for (size_t i = 1; i <= input.length(); ++i) {
            if (i < input.length() && input[i] == input[i - 1]) {
                ++count;
            } else {
                encoded << input[i - 1] << count;
                count = 1;
            }
        }

        return encoded.str();
    }

    // Run-Length Encoding (RLE) Decompression
    static std::string runLengthDecode(const std::string& input) {
        std::ostringstream decoded;
        int count = 0;

        for (size_t i = 0; i < input.length(); ++i) {
            if (isdigit(input[i])) {
                count = count * 10 + (input[i] - '0');
            } else {
                if (count == 0) continue;
                decoded << std::string(count, input[i]);
                count = 0;
            }
        }

        return decoded.str();
    }
};
