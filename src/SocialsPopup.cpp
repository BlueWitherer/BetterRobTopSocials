#include "SocialsPopup.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool SocialsPopup::init() {
    if (!Popup::init(275.f, 130.f)) return false;

    setID("popup"_spr);
    setTitle("Follow RobTop Games!");

    addSideArt(m_mainLayer, SideArt::All, SideArtStyle::PopupBlue);

    auto bg = NineSlice::create("square02_001.png");
    bg->setAnchorPoint({0.5, 0.5});
    bg->setContentSize({m_mainLayer->getScaledContentWidth() - 42.5f, 50.f});
    bg->setPosition({m_mainLayer->getScaledContentWidth() / 2.f, (m_mainLayer->getScaledContentHeight() / 2.f) * 0.875f});
    bg->setOpacity(50);

    m_mainLayer->addChild(bg);

    auto layout = RowLayout::create()
                      ->setGap(5.f)
                      ->setAutoScale(true)
                      ->setAxisAlignment(AxisAlignment::Center);

    auto container = CCNode::create();
    container->setID("socials-container");
    container->setAnchorPoint(bg->getAnchorPoint());
    container->setContentSize({bg->getScaledContentWidth() - 8.75f, bg->getScaledContentHeight() - 8.75f});
    container->setPosition(bg->getPosition());
    container->setLayout(layout);

    m_mainLayer->addChild(container, 1);

    auto btns = std::to_array<SocialItem>({
        {
            "gj_fbIcon_001.png",
            "facebook-btn",
            [](auto) {
                createQuickPopup(
                    "Facebook",
                    "Visit official <cl>Facebook</c> page?",
                    "Cancel",
                    "OK",
                    [](auto, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.facebook.com/geometrydash/");
                    });
            },
        },
        {
            "gj_twIcon_001.png",
            "twitter-btn",
            [](auto) {
                createQuickPopup(
                    "Twitter",
                    "Visit official <cj>Twitter</c> page?",
                    "Cancel",
                    "OK",
                    [](auto, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.twitter.com/robtopgames/");
                    });
            },
        },
        {
            "gj_ytIcon_001.png",
            "youtube-btn",
            [](auto) {
                createQuickPopup(
                    "YouTube",
                    "Visit official <cr>YouTube</c> channel?",
                    "Cancel",
                    "OK",
                    [](auto, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.youtube.com/@RobTopGames/");
                    });
            },
        },
        {
            "gj_twitchIcon_001.png",
            "twitch-btn",
            [](auto) {
                createQuickPopup(
                    "Twitch",
                    "Visit <ca>Twitch</c> game category page?",
                    "Cancel",
                    "OK",
                    [](auto, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.twitch.tv/directory/category/geometry-dash");
                    });
            },
        },
        {
            "gj_discordIcon_001.png",
            "discord-btn",
            [](auto) {
                createQuickPopup(
                    "Discord",
                    "Join official <cb>Discord</c> server?",
                    "Cancel",
                    "OK",
                    [](auto, bool ok) {
                        if (ok) web::openLinkInBrowser("https://discord.com/invite/geometrydash");
                    });
            },
        },
        {
            "gj_rdIcon_001.png",
            "reddit-btn",
            [](auto) {
                createQuickPopup(
                    "Reddit",
                    "Join official <co>Reddit</c> community?",
                    "Cancel",
                    "OK",
                    [](auto, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.reddit.com/r/geometrydash/");
                    });
            },
        },
    });

    for (auto& b : btns) {
        auto btn = Button::createWithSpriteFrameName(
            b.sprite,
            std::move(b.callback));
        btn->setID(b.id);

        container->addChild(btn);
    };

    container->updateLayout();

    auto robBtn = Button::createWithSpriteFrameName(
        "robtoplogo_small.png",
        [](auto) {
            createQuickPopup(
                "RobTop Games",
                "Visit <cs>RobTop Games</c> website?",
                "Cancel",
                "OK",
                [](auto, bool ok) {
                    if (ok) web::openLinkInBrowser("https://www.robtopgames.com/");
                });
        });
    robBtn->setID("robtop-games-btn");
    robBtn->setPosition({bg->getPositionX(), 0.f});

    m_mainLayer->addChild(robBtn, 1);

    auto gdWikiBtn = Button::createWithSpriteFrameName(
        "accountBtn_myLists_001.png",
        [](auto) {
            createQuickPopup(
                "Geometry Dash Wiki",
                "Visit official <cg>Geometry Dash Wiki</c>?",
                "Cancel",
                "OK",
                [](auto, bool ok) {
                    if (ok) web::openLinkInBrowser("https://geometrydash.wiki.gg/");
                });
        });
    gdWikiBtn->setID("geometry-dash-wiki-btn");
    gdWikiBtn->setScale(0.625f);
    gdWikiBtn->setPosition({17.5f, 17.5f});

    m_mainLayer->addChild(gdWikiBtn, 9);

    auto robProfileBtn = Button::createWithSpriteFrameName(
        "GJ_profileButton_001.png",
        [](auto) {
            if (auto profile = ProfilePage::create(71, false)) profile->show();
        });
    robProfileBtn->setID("robtop-profile-btn");
    robProfileBtn->setScale(0.5f);
    robProfileBtn->setPosition({m_mainLayer->getScaledContentWidth() - 17.5f, 17.5f});

    m_mainLayer->addChild(robProfileBtn, 9);

    return true;
};

SocialsPopup* SocialsPopup::create() {
    auto ret = new SocialsPopup();
    if (ret->init()) {
        ret->autorelease();
        return ret;
    };

    delete ret;
    return nullptr;
};