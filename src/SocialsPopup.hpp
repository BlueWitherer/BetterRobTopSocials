#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SocialsPopup : public Popup<> {
private:
    struct SocialItem {
        std::string sprite;
        std::string id;
        SEL_MenuHandler selector;

        SocialItem(
            std::string spr,
            std::string i,
            SEL_MenuHandler sel
        ) : sprite(std::move(spr)),
            id(std::move(i)),
            selector(sel) {};
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