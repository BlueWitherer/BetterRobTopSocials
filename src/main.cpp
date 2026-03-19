#include "SocialsPopup.hpp"

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
            log::debug("Default social media menu found");

            auto layout = RowLayout::create()
                              ->setAutoGrowAxis(0.f);

            auto newSocialContainer = CCNode::create();
            newSocialContainer->setID("container"_spr);
            newSocialContainer->setAnchorPoint({0, 0.5});
            newSocialContainer->setContentSize({0.f, 0.f});
            newSocialContainer->setPosition({13.f, 45.f});
            newSocialContainer->setVisible(socialMenu->isVisible());
            newSocialContainer->setLayout(layout);

            auto robtopBtn = Button::createWithNode(
                CCSprite::createWithSpriteFrameName("robtoplogo_small.png"),
                [](auto) {
                    if (auto popup = SocialsPopup::create()) return popup->show();
                });
            robtopBtn->setID("social-media-btn");

            newSocialContainer->addChild(robtopBtn);
            newSocialContainer->updateLayout();

            socialMenu->setVisible(false);

            addChild(newSocialContainer, socialMenu->getZOrder());

            log::info("Set up new social media menu");
        } else {
            log::error("Couldn't find social media menu");
        };

        return true;
    };
};