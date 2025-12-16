#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SocialsPopup : public Popup<> {
protected:
    void onFacebook(CCObject*);
    void onTwitter(CCObject*);
    void onYouTube(CCObject*);
    void onTwitch(CCObject*);
    void onDiscord(CCObject*);

    void onWebsite(CCObject*);

    bool setup() override;

public:
    static SocialsPopup* create();
};