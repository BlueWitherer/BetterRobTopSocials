#include "SocialsPopup.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool SocialsPopup::init() {
    if (!Popup::init(275.f, 130.f)) return false;

    setID("popup"_spr);
    setTitle("Follow RobTop Games!");

    addSideArt(m_mainLayer, SideArt::All, SideArtStyle::PopupBlue);

    auto bg = CCScale9Sprite::create("square02_001.png");
    bg->setAnchorPoint({ 0.5, 0.5 });
    bg->setContentSize({ m_mainLayer->getScaledContentWidth() - 40.f, 62.5f });
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

    static constexpr SocialItem btns[] = {
        {
            "gj_fbIcon_001.png",
            "facebook-btn",
            +[](CCMenuItem*) {
                createQuickPopup(
                    "Facebook",
                    "Visit official <cl>Facebook</c> page?",
                    "Cancel", "OK",
                    +[](bool, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.facebook.com/geometrydash/");
                    }
                );
            },
        },
        {
            "gj_twIcon_001.png",
            "twitter-btn",
            +[](CCMenuItem*) {
                createQuickPopup(
                    "Twitter",
                    "Visit official <cj>Twitter</c> page?",
                    "Cancel", "OK",
                    +[](bool, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.twitter.com/robtopgames/");
                    }
                );
            },
        },
        {
            "gj_ytIcon_001.png",
            "youtube-btn",
            +[](CCMenuItem*) {
                createQuickPopup(
                    "YouTube",
                    "Visit official <cr>YouTube</c> channel?",
                    "Cancel", "OK",
                    +[](bool, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.youtube.com/@RobTopGames/");
                    }
                );
            },
        },
        {
            "gj_twitchIcon_001.png",
            "twitch-btn",
            +[](CCMenuItem*) {
                createQuickPopup(
                    "Twitch",
                    "Visit <ca>Twitch</c> game category page?",
                    "Cancel", "OK",
                    +[](bool, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.twitch.tv/directory/category/geometry-dash");
                    }
                );
            },
         },
        {
            "gj_discordIcon_001.png",
            "discord-btn",
            +[](CCMenuItem*) {
                createQuickPopup(
                    "Discord",
                    "Join official <cb>Discord</c> server?",
                    "Cancel", "OK",
                    +[](bool, bool ok) {
                        if (ok) web::openLinkInBrowser("https://discord.com/invite/geometrydash");
                    }
                );
            },
        },
        {
            "gj_rdIcon_001.png",
            "reddit-btn",
            +[](CCMenuItem*) {
                createQuickPopup(
                    "Reddit",
                    "Join official <co>Reddit</c> community?",
                    "Cancel", "OK",
                    +[](bool, bool ok) {
                        if (ok) web::openLinkInBrowser("https://www.reddit.com/r/geometrydash/");
                    }
                );
            },
        },
    };

    for (auto const& b : btns) {
        auto btn = CCMenuItemExt::createSpriteExtra(
            CCSprite::createWithSpriteFrameName(b.sprite),
            b.callback
        );
        btn->setID(b.id);

        menu->addChild(btn);
    };

    menu->updateLayout();

    auto robBtn = CCMenuItemExt::createSpriteExtra(
        CCSprite::createWithSpriteFrameName("robtoplogo_small.png"),
        [](auto) {
            createQuickPopup(
                "RobTop Games",
                "Visit <cs>RobTop Games</c> website?",
                "Cancel", "OK",
                +[](bool, bool ok) {
                    if (ok) web::openLinkInBrowser("https://www.robtopgames.com/");
                }
            );
        }
    );
    robBtn->setID("robtop-games-btn");
    robBtn->setPosition({ bg->getPositionX(), 0.f });

    m_buttonMenu->addChild(robBtn, 1);

    auto robProfileBtnSprite = CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png");
    robProfileBtnSprite->setScale(0.5f);

    auto robProfileBtn = CCMenuItemExt::createSpriteExtra(
        robProfileBtnSprite,
        [](auto) {
            if (auto profile = ProfilePage::create(71, false)) profile->show();
        }
    );
    robProfileBtn->setID("robtop-profile-btn");
    robProfileBtn->setPosition({ m_mainLayer->getScaledContentWidth() - 17.5f, 17.5f });

    m_buttonMenu->addChild(robProfileBtn, 9);

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