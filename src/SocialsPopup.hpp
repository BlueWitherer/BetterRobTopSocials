#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SocialsPopup : public Popup {
private:
    using Callback = void(*)(CCMenuItem*);

    struct SocialItem {
        const char* sprite;
        const char* id;
        Callback callback;
    };

protected:
    void onWebsite(CCObject*);
    void onProfile(CCObject*);

    bool init();

public:
    static SocialsPopup* create();
};