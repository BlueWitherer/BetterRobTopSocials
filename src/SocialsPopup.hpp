#include <Geode/Geode.hpp>

#include <Geode/ui/Button.hpp>

using namespace geode::prelude;

class SocialsPopup final : public Popup {
private:
    struct SocialItem final {
        const char* sprite;
        const char* id;
        Button::ButtonCallback callback;
    };

protected:
    bool init();

public:
    static SocialsPopup* create();
};