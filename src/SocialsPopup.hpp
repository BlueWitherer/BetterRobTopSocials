#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SocialsPopup : public Popup<> {
private:
    struct SocialItem {
        const char* sprite;
        const char* id;
        SEL_MenuHandler selector;
    };

protected:
    void onFacebook(CCObject*);
    void onTwitter(CCObject*);
    void onYouTube(CCObject*);
    void onTwitch(CCObject*);
    void onDiscord(CCObject*);
    void onReddit(CCObject*);

    void onWebsite(CCObject*);

    bool setup() override;

public:
    static SocialsPopup* create();
};