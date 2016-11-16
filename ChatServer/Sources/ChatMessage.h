/**
 * @file ChatMessage.h
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

/*#include <cstring>
#include <cstdio>
#include <cstdlib>*/

class ChatMessage {
public:
    enum {
        header_length = 4
    };
    enum {
        max_body_length = 512
    };

    ChatMessage() : body_length_(0) {
    }

    inline const char* Data() const {
        return data_;
    }

    inline char* Data() {
        return data_;
    }

    inline int Lenght() const {
        return header_length + body_length_;
    }

    inline const char* Body() const {
        return data_ + header_length;
    }

    inline char* Body() {
        return data_ + header_length;
    }

    inline int BodyLength() const {
        return body_length_;
    }

    inline void BodyLength(int new_length) {
        body_length_ = new_length < max_body_length ? new_length : max_body_length;
    }

    bool DecodeHeader();

    void EncodeHeader();

private:
    char data_[header_length + max_body_length];
    int body_length_;
};

#endif // CHAT_MESSAGE_HPP
