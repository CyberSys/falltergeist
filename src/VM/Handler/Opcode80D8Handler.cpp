// Project includes
#include "../../VM/Handler/Opcode80D8Handler.h"
#include "../../Game/ContainerItemObject.h"
#include "../../Game/CritterObject.h"
#include "../../Game/Game.h"
#include "../../State/Location.h"
#include "../../VM/Script.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode80D8::Opcode80D8(std::shared_ptr<ILogger> logger) : OpcodeHandler(), _logger(logger)
            {

            }

            void Opcode80D8::_run(VM::Script& script)
            {
                _logger->debug() << "[80D8] [=] void add_obj_to_inven(void* who, void* item)" << std::endl;
                auto item = dynamic_cast<Game::ItemObject *>(script.dataStack()->popObject());
                auto invenObj = script.dataStack()->popObject();

                if (!item) {
                    _error("add_obj_to_inven - item not instanceof GameItemObject");
                    return;
                }

                std::vector<Game::ItemObject *> *inven = nullptr;
                if (auto critterObj = dynamic_cast<Game::CritterObject *>(invenObj)) {
                    inven = critterObj->inventory();
                } else if (auto contObj = dynamic_cast<Game::ContainerItemObject *>(invenObj)) {
                    inven = contObj->inventory();
                } else {
                    _error("add_obj_to_inven - wrong WHO parameter");
                    return;
                }

                inven->push_back(item);

                if (item->hexagon()) {
                    auto location = Game::Game::getInstance()->locationState();
                    if (location) {
                        location->moveObjectToHexagon(item, nullptr);
                    }
                }
            }
        }
    }
}
