#pragma once

// Project includes
#include "../Game/SceneryObject.h"
#include "../ILogger.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace Event
    {
        class Event;
    }

    namespace Game
    {
        /**
         * Doors. Can be opened, closed, locked and unlocked.
         */
        class DoorSceneryObject : public SceneryObject
        {
            public:
                DoorSceneryObject(std::shared_ptr<ILogger> logger);
                ~DoorSceneryObject() = default;

                bool opened() const;
                void setOpened(bool value);

                bool locked() const;
                void setLocked(bool value);

                bool canWalkThru() const override;

                void use_p_proc(CritterObject* usedBy) override;

                void onOpeningAnimationEnded(std::shared_ptr<UI::AnimationQueue> target);

                void onClosingAnimationEnded(std::shared_ptr<UI::AnimationQueue> target);

            private:
                std::shared_ptr<ILogger> logger;
                bool _opened = false;
                bool _locked = false;
        };
    }
}
