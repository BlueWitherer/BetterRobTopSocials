#include "SocialsPopup.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool SocialsPopup::setup() {
    setID("popup"_spr);
    setTitle("Follow RobTop Games!");

    auto bg = CCScale9Sprite::create("square02_001.png");
    bg->setAnchorPoint({ 0.5, 0.5 });
    bg->setContentSize({ 225.f, 62.5f });
    bg->setPosition({ m_mainLayer->getScaledContentWidth() / 2.f, (m_mainLayer->getScaledContentHeight() / 2.f) * 0.875f });
    bg->setOpacity(50);

    m_mainLayer->addChild(bg);

    auto layout = RowLayout::create()
        ->setGap(6.25f)
        ->setAxisAlignment(AxisAlignment::Center);

    auto menu = CCMenu::create();
    menu->setID("socials-menu");
    menu->setAnchorPoint(bg->getAnchorPoint());
    menu->setContentSize({ bg->getScaledContentWidth() - 8.75f, bg->getScaledContentHeight() - 8.75f });
    menu->setPosition(bg->getPosition());
    menu->setLayout(layout);

    m_mainLayer->addChild(menu);

    auto fbBtnSprite = CCSprite::createWithSpriteFrameName("gj_fbIcon_001.png");
    fbBtnSprite->setScale(1.25f);

    auto fbBtn = CCMenuItemSpriteExtra::create(
        fbBtnSprite,
        this,
        menu_selector(SocialsPopup::onFacebook)
    );
    fbBtn->setID("facebook-button");

    menu->addChild(fbBtn);

    auto twtBtnSprite = CCSprite::createWithSpriteFrameName("gj_twIcon_001.png");
    twtBtnSprite->setScale(1.25f);

    auto twtBtn = CCMenuItemSpriteExtra::create(
        twtBtnSprite,
        this,
        menu_selector(SocialsPopup::onTwitter)
    );
    twtBtn->setID("twitter-button");

    menu->addChild(twtBtn);

    auto ytBtnSprite = CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png");
    ytBtnSprite->setScale(1.25f);

    auto ytBtn = CCMenuItemSpriteExtra::create(
        ytBtnSprite,
        this,
        menu_selector(SocialsPopup::onYouTube)
    );
    ytBtn->setID("youtube-button");

    menu->addChild(ytBtn);

    auto twBtnSprite = CCSprite::createWithSpriteFrameName("gj_twitchIcon_001.png");
    twBtnSprite->setScale(1.25f);

    auto twBtn = CCMenuItemSpriteExtra::create(
        twBtnSprite,
        this,
        menu_selector(SocialsPopup::onTwitch)
    );
    twBtn->setID("twitch-button");

    menu->addChild(twBtn);

    auto dcBtnSprite = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
    dcBtnSprite->setScale(1.25f);

    auto dcBtn = CCMenuItemSpriteExtra::create(
        dcBtnSprite,
        this,
        menu_selector(SocialsPopup::onDiscord)
    );
    dcBtn->setID("discord-button");

    menu->addChild(dcBtn);

    menu->updateLayout(true);

    auto robBtn = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("robtoplogo_small.png"),
        this,
        menu_selector(SocialsPopup::onWebsite)
    );
    robBtn->setID("robtop-button");
    robBtn->setPosition({ bg->getPositionX(), 0.f });

    m_buttonMenu->addChild(robBtn);

    return true;
};

void SocialsPopup::onFacebook(CCObject*) {};

void SocialsPopup::onTwitter(CCObject*) {};

void SocialsPopup::onYouTube(CCObject*) {};

void SocialsPopup::onTwitch(CCObject*) {};

void SocialsPopup::onDiscord(CCObject*) {};

void SocialsPopup::onWebsite(CCObject*) {};

SocialsPopup* SocialsPopup::create() {
    auto ret = new SocialsPopup();
    if (ret->initAnchored(275.f, 125.f)) {
        ret->autorelease();
        return ret;
    };

    CC_SAFE_DELETE(ret);
    return nullptr;
};