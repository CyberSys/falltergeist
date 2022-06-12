// Project includes
#include "../../VM/Handler/Opcode811DHandler.h"
#include "../../Game/Game.h"
#include "../../State/CritterDialog.h"
#include "../../State/CritterInteract.h"
#include "../../VM/HaltException.h"
#include "../../VM/Script.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode811D::Opcode811D(std::shared_ptr<ILogger> logger) : OpcodeHandler(), _logger(logger)
            {

            }

            void Opcode811D::_run(VM::Script& script)
            {
                _logger->debug() << "[811D] [?] gsay_end" << std::endl;
                auto dialog = dynamic_cast<State::CritterDialog *>(Game::Game::getInstance()->topState());
                if (dialog->hasAnswers()) {
                    script.dataStack()->push(0); // function return value
                    throw HaltException();
                }
                if (auto interact = dynamic_cast<Falltergeist::State::CritterInteract *>(Game::Game::getInstance()->topState(
                        1))) {
                    interact->switchSubState(State::CritterInteract::SubState::NONE);
                }
                //Game::getInstance()->popState(); // dialog state
            }
        }
    }
}


