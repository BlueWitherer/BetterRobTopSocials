#include "SocialsPopup.h"

#include <Geode/Geode.hpp>

#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(SocialsContainerLayer, MenuLayer) {
    static void onModify(auto& self) {
        (void)self.setHookPriorityPost("MenuLayer::init", Priority::Last);
    };

    bool init() {
        if (!MenuLayer::init()) return false;

        log::trace("Searching for default social media menu...");

        if (auto socialMenu = getChildByID("social-media-menu")) {  // hide these buttons
            log::trace("Default social media menu found");

            auto robtopBtn = Button::createWithSpriteFrameName(
                "robtoplogo_small.png",
                [](auto) {
                    if (auto popup = SocialsPopup::create()) return popup->show();
                });
            robtopBtn->setID("social-media-btn"_spr);
            robtopBtn->setScale(0.875f);
            robtopBtn->setPosition({(robtopBtn->getScaledContentWidth() / 2.f) + 13.f, 45.f});
            robtopBtn->setVisible(socialMenu->isVisible());

            addChild(robtopBtn, socialMenu->getZOrder());
            socialMenu->setVisible(false);

            log::debug("Set up new social media menu");
        } else {
            log::error("Couldn't find default social media menu");
        };

        return true;
    };
};