/**
 * @file ChatParticipant.h
 *
 * @author c.ionescu@iquestgroup.com
 * @copyright (c) 2016 iQuest Group
 */

#ifndef CHATPARTICIPANT_H_
#define CHATPARTICIPANT_H_

#include "ChatMessage.h"

#include <memory>


namespace server {
class ChatParticipant {
public:
    virtual ~ChatParticipant() {
    }
    virtual void Deliver(const ChatMessage& msg) = 0;
};

typedef std::shared_ptr<ChatParticipant> chat_participant_ptr;

#endif /* CHATPARTICIPANT_H_ */
}
