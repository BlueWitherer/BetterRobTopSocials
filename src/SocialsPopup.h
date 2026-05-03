#include <Geode/Geode.hpp>

#include <Geode/ui/Button.hpp>

class SocialsPopup final : public geode::Popup {
    struct SocialItem final {
        const char* sprite;
        const char* id;
        geode::Button::ButtonCallback callback;
    };

protected:
    bool init();

public:
    static SocialsPopup* create();
};