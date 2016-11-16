/**
 * @file ChatRoom.cpp
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#include "ChatRoom.h"

namespace server {
void ChatRoom::Join(chat_participant_ptr participant) {
    participants_.insert(participant);
    for (auto msg : recent_msgs_) {
        participant->Deliver(msg);
    }
}
void ChatRoom::Leave(chat_participant_ptr participant) {
    participants_.erase(participant);
}

void ChatRoom::Deliver(const ChatMessage& msg) {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs) {
        recent_msgs_.pop_front();
    }

    for (auto participant : participants_) {
        participant->Deliver(msg);
    }
}
}
