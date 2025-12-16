#include "SocialsPopup.hpp"

#include <Geode/Geode.hpp>

#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(SocialsMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        if (auto socialMediaMenu = getChildByID("social-media-menu")) { // hide these buttons
            if (auto fb = socialMediaMenu->getChildByID("facebook-button")) fb->setVisible(false);
            if (auto twt = socialMediaMenu->getChildByID("twitter-button")) twt->setVisible(false);
            if (auto yt = socialMediaMenu->getChildByID("youtube-button")) yt->setVisible(false);
            if (auto tw = socialMediaMenu->getChildByID("twitch-button")) tw->setVisible(false);
            if (auto dc = socialMediaMenu->getChildByID("discord-button")) dc->setVisible(false);

            socialMediaMenu->setPositionY(33.f);
        } else {
            log::error("Couldn't find social media menu");
        };

        return true;
    };

    void onRobTop(CCObject * sender) {
        if (auto popup = SocialsPopup::create()) return popup->show();
        MenuLayer::onRobTop(sender);
    };
};