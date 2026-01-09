#include "SocialsPopup.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool SocialsPopup::setup() {
    setID("popup"_spr);
    setTitle("Follow RobTop Games!");

    addSideArt(m_mainLayer, SideArt::All, SideArtStyle::PopupBlue);

    auto bg = CCScale9Sprite::create("square02_001.png");
    bg->setAnchorPoint({ 0.5, 0.5 });
    bg->setContentSize({ 235.f, 62.5f });
    bg->setPosition({ m_mainLayer->getScaledContentWidth() / 2.f, (m_mainLayer->getScaledContentHeight() / 2.f) * 0.875f });
    bg->setOpacity(50);

    m_mainLayer->addChild(bg);

    auto layout = RowLayout::create()
        ->setGap(5.f)
        ->setAxisAlignment(AxisAlignment::Center)
        ->setAutoScale(true);

    auto menu = CCMenu::create();
    menu->setID("socials-menu");
    menu->setAnchorPoint(bg->getAnchorPoint());
    menu->setContentSize({ bg->getScaledContentWidth() - 8.75f, bg->getScaledContentHeight() - 8.75f });
    menu->setPosition(bg->getPosition());
    menu->setLayout(layout);

    m_mainLayer->addChild(menu);

    std::vector<SocialItem> btns = {
        { "gj_fbIcon_001.png", "facebook-btn", menu_selector(SocialsPopup::onFacebook) },
        { "gj_twIcon_001.png", "twitter-btn", menu_selector(SocialsPopup::onTwitter) },
        { "gj_ytIcon_001.png", "youtube-btn", menu_selector(SocialsPopup::onYouTube) },
        { "gj_twitchIcon_001.png", "twitch-btn", menu_selector(SocialsPopup::onTwitch) },
        { "gj_discordIcon_001.png", "discord-btn", menu_selector(SocialsPopup::onDiscord) },
        { "gj_rdIcon_001.png", "reddit-btn", menu_selector(SocialsPopup::onReddit) },
    };

    for (auto const& b : btns) {
        auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName(b.sprite.c_str()),
            this,
            b.selector
        );
        btn->setID(b.id);

        menu->addChild(btn);
    };
    btns.clear();

    menu->updateLayout(true);

    auto robBtn = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("robtoplogo_small.png"),
        this,
        menu_selector(SocialsPopup::onWebsite)
    );
    robBtn->setID("robtop-games-btn");
    robBtn->setPosition({ bg->getPositionX(), 0.f });

    m_buttonMenu->addChild(robBtn);

    return true;
};

void SocialsPopup::onFacebook(CCObject*) {
    createQuickPopup(
        "Facebook",
        "Visit official <cl>Facebook</c> page?",
        "Cancel", "OK",
        [this](bool, bool ok) {
            if (ok) web::openLinkInBrowser("https://www.facebook.com/geometrydash/");
        }, true
    );
};

void SocialsPopup::onTwitter(CCObject*) {
    createQuickPopup(
        "Twitter",
        "Visit official <cj>Twitter</c> page?",
        "Cancel", "OK",
        [this](bool, bool ok) {
            if (ok) web::openLinkInBrowser("https://www.twitter.com/robtopgames/");
        }, true
    );
};

void SocialsPopup::onYouTube(CCObject*) {
    createQuickPopup(
        "YouTube",
        "Visit official <cr>YouTube</c> channel?",
        "Cancel", "OK",
        [this](bool, bool ok) {
            if (ok) web::openLinkInBrowser("https://www.youtube.com/@RobTopGames/");
        }, true
    );
};

void SocialsPopup::onTwitch(CCObject*) {
    createQuickPopup(
        "Twitch",
        "Visit <ca>Twitch</c> game category page?",
        "Cancel", "OK",
        [this](bool, bool ok) {
            if (ok) web::openLinkInBrowser("https://www.twitch.tv/directory/category/geometry-dash");
        }, true
    );
};

void SocialsPopup::onDiscord(CCObject*) {
    createQuickPopup(
        "Discord",
        "Join official <cb>Discord</c> server?",
        "Cancel", "OK",
        [this](bool, bool ok) {
            if (ok) web::openLinkInBrowser("https://discord.com/invite/geometrydash");
        }, true
    );
};

void SocialsPopup::onReddit(CCObject*) {
    createQuickPopup(
        "Reddit",
        "Join official <co>Reddit</c> community?",
        "Cancel", "OK",
        [this](bool, bool ok) {
            if (ok) web::openLinkInBrowser("https://www.reddit.com/r/geometrydash/");
        }, true
    );
};

void SocialsPopup::onWebsite(CCObject*) {
    createQuickPopup(
        "RobTop Games",
        "Visit <cs>RobTop Games</c> website?",
        "Cancel", "OK",
        [this](bool, bool ok) {
            if (ok) web::openLinkInBrowser("https://www.robtopgames.com/");
        }, true
    );
};

SocialsPopup* SocialsPopup::create() {
    auto ret = new SocialsPopup();
    if (ret->initAnchored(275.f, 135.f)) {
        ret->autorelease();
        return ret;
    };

    CC_SAFE_DELETE(ret);
    return nullptr;
};