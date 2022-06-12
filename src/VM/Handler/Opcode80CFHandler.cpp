// Project includes
#include "../../VM/Handler/Opcode80CFHandler.h"
#include "../../VM/Script.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode80CF::Opcode80CF(std::shared_ptr<ILogger> logger) : OpcodeHandler(), _logger(logger)
            {

            }

            void Opcode80CF::_run(VM::Script& script)
            {
                _logger->debug()
                    << "[80CF] [=] int tile_in_tile_rect(int tile1, int tile2, int tile3, int tile4, int tile)"
                    << std::endl
                ;
                auto dataStack = script.dataStack();

                int targetHex = dataStack->popInteger();
                int bottomRight = dataStack->popInteger();
                /*int bottomLeft = */dataStack->popInteger();
                /*int upperRight = */dataStack->popInteger();
                int upperLeft = dataStack->popInteger();

                // That's how original engine does this:
                int targetX = targetHex % 200;
                int targetY = targetHex / 200;

                int upperLeftX = upperLeft % 200;
                int upperLeftY = upperLeft / 200;

                int bottomRightX = bottomRight % 200;
                int bottomRightY = bottomRight / 200;

                bool in = (targetX <= upperLeftX && targetY >= upperLeftY && targetX >= bottomRightX &&
                           targetY <= bottomRightY);
                script.dataStack()->push(in);
            }
        }
    }
}


