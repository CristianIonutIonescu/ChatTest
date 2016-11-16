/**
 * @file ChatMessage.cpp
 * 
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#include "ChatMessage.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>

bool ChatMessage::DecodeHeader() {
    char header[header_length + 1] = "";
    std::strncat(header, data_, header_length);
    body_length_ = std::atoi(header);
    if (body_length_ > max_body_length) {
        body_length_ = 0;
        return false;
    }
    return true;
}

void ChatMessage::EncodeHeader() {
    char header[header_length + 1] = "";
    std::sprintf(header, "%4d", body_length_);
    std::memcpy(data_, header, header_length);
}

