/**
 * @file ChatRoom.h
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#ifndef CHATROOM_H_
#define CHATROOM_H_

#include "ChatParticipant.h"

#include <deque>
#include <set>

namespace server {

typedef std::deque<ChatMessage> chat_message_queue;

//----------------------------------------------------------------------

//----------------------------------------------------------------------

class ChatRoom {
public:
    void Join(chat_participant_ptr participant);

    void Leave(chat_participant_ptr participant);

    void Deliver(const ChatMessage& msg);

private:
    std::set<chat_participant_ptr> participants_;
    enum {
        max_recent_msgs = 100
    };
    chat_message_queue recent_msgs_;
};
}
#endif /* CHATROOM_H_ */
