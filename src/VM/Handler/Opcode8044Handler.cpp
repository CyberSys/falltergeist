// Project includes
#include "../../VM/Handler/Opcode8044Handler.h"
#include "../../VM/Script.h"
#include "../../VM/StackValue.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode8044::Opcode8044(std::shared_ptr<ILogger> logger) : OpcodeHandler(), _logger(logger)
            {

            }

            void Opcode8044::_run(VM::Script& script)
            {
                _logger->debug() << "[8044] [*] op_floor" << std::endl;
                auto value = script.dataStack()->pop();
                int result = 0;
                if (value.type() == StackValue::Type::FLOAT) {
                    result = (int) value.floatValue(); // this is how "floor" originally worked..
                } else if (value.type() == StackValue::Type::INTEGER) {
                    result = value.integerValue();
                } else {
                    _error(std::string("op_floor: invalid argument type: ") + value.typeName());
                }
                script.dataStack()->push(result);
            }
        }
    }
}
