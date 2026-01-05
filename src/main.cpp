#include "SocialsPopup.hpp"

#include <Geode/Geode.hpp>

#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(SocialsMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        if (auto socialMenu = getChildByID("social-media-menu")) { // hide these buttons
            socialMenu->setVisible(false);

            auto layout = RowLayout::create()
                ->setAutoGrowAxis(0.f);

            auto newSocialMenu = CCMenu::create();
            newSocialMenu->setID("menu"_spr);
            newSocialMenu->setAnchorPoint({ 0, 0.5 });
            newSocialMenu->setContentSize({ 0.f, 0.f });
            newSocialMenu->setPosition({ 13.f, 45.f });
            newSocialMenu->setLayout(layout);

            auto robtopBtn = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("robtoplogo_small.png"),
                this,
                menu_selector(SocialsMenuLayer::onSocials)
            );
            robtopBtn->setID("social-media-button");

            newSocialMenu->addChild(robtopBtn);
            newSocialMenu->updateLayout(true);

            addChild(newSocialMenu);
        } else {
            log::error("Couldn't find social media menu");
        };

        return true;
    };

    void onSocials(CCObject*) {
        if (auto popup = SocialsPopup::create()) return popup->show();
    };
};