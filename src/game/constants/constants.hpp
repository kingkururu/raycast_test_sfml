//
//  constants.hpp
//  sfmlgame3
//
//  Created by Sunmyoung Yun on 2024/08
//


#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream> 

namespace Constants {
    // basic game components
    constexpr unsigned short SCREEN_WIDTH = 960;
    constexpr unsigned short SCREEN_HEIGHT = 540;
    constexpr unsigned short FRAME_LIMIT = 60;
    constexpr const char* GAME_TITLE = "SFML game 3";

    // score components
    constexpr unsigned short INITIAL_SCORE = 0;

    // basic animation standards
    constexpr float ANIMATION_CHANGE_TIME = 0.1f;

    // screen buffers for sprites and texts
    constexpr unsigned short SPRITE_OUT_OF_BOUNDS_OFFSET = 200;
    constexpr unsigned short SPRITE_OUT_OF_BOUNDS_ADJUSTMENT = 200;

    // background components (static)
    extern const sf::Vector2f BACKGROUND_POSITION;
    extern const sf::Vector2f BACKGROUND_SCALE;
    constexpr const char* BACKGROUNDSPRITE_PATH = "src/assets/sprites/png/background.png";
    extern std::shared_ptr<sf::Texture> BACKGROUND_TEXTURE;  

    // player components (non-static) / animated 
    extern const sf::Vector2f PLAYER_POSITION;
    extern const sf::Vector2f PLAYER_SCALE;
    extern std::vector<sf::IntRect> PLAYERSPRITE_RECTS;
    constexpr float PLAYER_SPEED = 200.0f;
    extern const sf::Color PLAYER_DEAD_COLOR;
    constexpr const char* PLAYERSPRITE_PATH = "src/assets/sprites/png/player_run.png";
    extern std::shared_ptr<sf::Texture> PLAYER_TEXTURE;
    constexpr unsigned short PLAYERANIM_MAX_INDEX = 4; 
    extern std::shared_ptr<sf::Uint8[]> PLAYER_BITMASK;

    // bullet components (non-static) / non-animated
    extern const sf::Vector2f BULLET_POSITION;
    extern const sf::Vector2f BULLET_SCALE;
    extern std::vector<sf::IntRect> BULLETSPRITES_RECTS;
    constexpr float BULLET_SPEED = 200.0f;
    constexpr float BULLET_ACCELERATION = -20.0f;
    constexpr const char* BULLETSPRITE_PATH = "src/assets/sprites/png/bullet.png";
    extern std::shared_ptr<sf::Texture> BULLET_TEXTURE;
    constexpr short BULLETANIM_MAX_INDEX = 0; 
    extern std::shared_ptr<sf::Uint8[]> BULLET_BITMASK;

    // slime components (non-static) / animated
    extern const sf::Vector2f SLIME_POSITION;
    extern const sf::Vector2f SLIME_SCALE;
    extern std::vector<sf::IntRect> SLIMESPRITE_RECTS;
    constexpr const char* SLIMESPRITE_PATH = "src/assets/sprites/png/slime.png";
    extern std::shared_ptr<sf::Texture> SLIME_TEXTURE;
    constexpr unsigned short SLIMEANIM_MAX_INDEX = 4; 
    constexpr float SLIME_SPEED = 200.0f;
    constexpr float SLIME_ACCELERATION = -20.0f;
    extern std::shared_ptr<sf::Uint8[]> SLIME_BITMASK;

    // bush components (non-static) / non-animated
    extern const sf::Vector2f BUSH_POSITION;
    extern const sf::Vector2f BUSH_SCALE;
    extern std::vector<sf::IntRect> BUSHSPRITES_RECTS;
    constexpr float BUSH_SPEED = 200.0f;
    constexpr float BUSH_ACCELERATION = -20.0f;
    constexpr const char* BUSHSPRITE_PATH = "src/assets/sprites/png/bush1.png";
    extern std::shared_ptr<sf::Texture> BUSH_TEXTURE;
    constexpr unsigned short BUSHANIM_MAX_INDEX = 0; 
    extern std::shared_ptr<sf::Uint8[]> BUSH_BITMASK;

    // text components
    extern const sf::Vector2f TEXT_POSITION;
    constexpr unsigned short TEXT_SIZE = 40;
    extern const sf::Color TEXT_COLOR;
    constexpr const char* TEXT_PATH = "src/assets/fonts/ttf/font1.ttf";
    extern std::shared_ptr<sf::Font> TEXT_FONT; 
    constexpr const char* TEXT_MESSAGE = "blank message in text";

    // music components 
    constexpr const char* BACKGROUNDMUSIC_PATH = "src/assets/sound/mp3,flac,wav/bgm.mp3";
    extern std::unique_ptr<sf::Music> BACKGROUNDMUSIC_MUSIC;
    constexpr float BACKGROUNDMUSIC_VOLUME = 100.0f; 

    // sound components
    constexpr const char* PLAYERDEADSOUND_PATH = "src/assets/sound/mp3,flac,wav/gameEnd.flac";
    extern std::shared_ptr<sf::SoundBuffer> PLAYERDEAD_SOUNDBUFF;
    constexpr float PLAYERDEADSOUND_VOLUME = 100.0f; 

    constexpr const char* PLAYERJUMPSOUND_PATH = "src/assets/sound/mp3,flac,wav/jump.wav";
    extern std::shared_ptr<sf::SoundBuffer> PLAYERJUMP_SOUNDBUFF;
    constexpr float PLAYERJUMPSOUND_VOLUME = 100.0f; 

    constexpr const char* BULLETSOUND_PATH = "";
    extern std::shared_ptr<sf::SoundBuffer> BULLET_SOUNDBUFF;
    constexpr float BULLETSOUND_VOLUME = 100.0f; 

    constexpr const char* OBSTHITSOUND_PATH = "";
    extern std::shared_ptr<sf::SoundBuffer> OBSTHIT_SOUNDBUFF;
    constexpr float OBSTHITSOUND_VOLUME = 100.0f;

    // load textures, fonts, music, and sound
    extern void initialize(); 
}
