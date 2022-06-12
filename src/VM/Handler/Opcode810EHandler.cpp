// Project includes
#include "../../VM/Handler/Opcode810EHandler.h"
#include "../../Game/CritterObject.h"
#include "../../Game/Object.h"
#include "../../UI/AnimationQueue.h"
#include "../../VM/Script.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode810E::Opcode810E(std::shared_ptr<ILogger> logger) : OpcodeHandler(), _logger(logger)
            {

            }

            void Opcode810E::_run(VM::Script& script)
            {
                _logger->debug() << "[810E] [=] void reg_anim_func(int mode, int arg)" << std::endl;
                auto arg = script.dataStack()->pop(); // pointer or integer
                auto p1 = script.dataStack()->popInteger();
                switch (p1) {
                    case 0x1: // ANIM_BEGIN
                    {
                        // @TODO: implement
                        // auto arg = popDataInteger();
                        // RB_UNRESERVED (1) - unreserved sequence, may not play, if there are no free slots left
                        // RB_RESERVED (2) - reserved sequence, should always play
                        break;
                    }
                    case 0x2: // ANIM_CLEAR
                    {
                        auto object = arg.objectValue();
                        if (auto critterObject = dynamic_cast<Game::CritterObject *>(object)) {
                            critterObject->stopMovement();
                        } else {
                            auto queue = object->ui<UI::AnimationQueue>();
                            if (queue) {
                                queue->stop();
                            }
                        }
                        break;
                    }
                    case 0x3: // ANIMATION_END
                    {
                        // @TODO: implement
                        break;
                    }
                    default: {
                        _error("reg_anim_func - unsupported mode");
                    }
                }
            }
        }
    }
}
