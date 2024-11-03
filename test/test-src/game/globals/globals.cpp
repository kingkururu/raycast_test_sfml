//
//  globals.cpp
//
//

#include "globals.hpp" 

namespace MetaComponents {
    sf::Clock clock;
    sf::View view; 
}   

/* constant variables defined here */
namespace Constants {
    // make random position function (random from upper right corner)
    sf::Vector2f makeRandomPosition(){
        float xPos = static_cast<float>(SCREEN_WIDTH - std::rand() % static_cast<int>(SCREEN_WIDTH / 2));
        float yPos = 0.0f;
        return sf::Vector2f{ xPos, yPos }; 
    }
    
    //initializer function
    void initialize() {
        init_logging();
        
        setup_signal_handlers();

        log_info("\tConstants initialized ");

        if (!BACKGROUND_TEXTURE->loadFromFile(BACKGROUNDSPRITE_PATH)) {
            log_warning("Failed to load background texture");
        }

        if (!BACKGROUND_TEXTURE2->loadFromFile(BACKGROUNDSPRITE_PATH2)) {
            log_warning("Failed to load background2 texture");
        }

        if (!BUTTON1_TEXTURE->loadFromFile(BUTTON1_PATH)) {
            log_warning("Failed to load button texture");
        }

        if (!SPRITE1_TEXTURE->loadFromFile(SPRITE1SPRITE_PATH)) {
            log_warning("Failed to load sprite1 texture");
        }

        if (!TILE1_TEXTURE->loadFromFile(TILE1_PATH)) {
            log_warning("Failed to load tile1 texture");
        }

        if (!BACKGROUNDMUSIC_MUSIC->openFromFile(BACKGROUNDMUSIC_PATH)) {
            log_warning("Failed to load background music");
        }

        if (!PLAYERJUMP_SOUNDBUFF->loadFromFile(PLAYERJUMPSOUND_PATH)) {
            log_warning("Failed to load player jump sound");
        }

        if (!TEXT_FONT->loadFromFile(TEXT_PATH)) {
            log_warning("Failed to load text font");
        }
     
        //make rects for animations     
        for(int i = 0; i < BUTTON1_INDEXMAX; ++i ){
            BUTTON1_ANIMATIONRECTS.emplace_back(sf::IntRect{ 170 * i, 0, 170, 170 }); 
        }

        // make bitmasks
        for (const auto& rect : BUTTON1_ANIMATIONRECTS ) {
            BUTTON1_BITMASK.emplace_back(createBitmask(BUTTON1_TEXTURE, rect));
        }

    }

    std::shared_ptr<sf::Uint8[]> createBitmask( const std::shared_ptr<sf::Texture>& texture, const sf::IntRect& rect) {
        if (!texture) {
            log_warning("\tfailed to create bitmask ( texture is empty )");
            return nullptr;
        }

        // Ensure the rect is within the bounds of the texture
        sf::Vector2u textureSize = texture->getSize();
        if (rect.left < 0 || rect.top < 0 || 
            rect.left + rect.width > static_cast<int>(textureSize.x) || 
            rect.top + rect.height > static_cast<int>(textureSize.y)) {
            log_warning("\tfailed to create bitmask ( rect is out of bounds)");
            return nullptr;
        }

        sf::Image image = texture->copyToImage();
        unsigned int width = rect.width;
        unsigned int height = rect.height;

        unsigned int bitmaskSize = (width * height) / 8 + ((width * height) % 8 != 0); // rounding up
        std::shared_ptr<sf::Uint8[]> bitmask(new sf::Uint8[bitmaskSize](), std::default_delete<sf::Uint8[]>());

         for (unsigned int y = 0; y < height; ++y) {
            for (unsigned int x = 0; x < width; ++x) {
                sf::Color pixelColor = image.getPixel(x, y);
                unsigned int bitIndex = y * width + x;
                unsigned int byteIndex = bitIndex / 8;
                unsigned int bitPosition = bitIndex % 8;

                if (pixelColor.a > 128) {
                    bitmask[byteIndex] |= (1 << bitPosition);
                }
            }
        }

        return bitmask; 
    }

    void printBitmaskDebug(const std::shared_ptr<sf::Uint8[]>& bitmask, unsigned int width, unsigned int height) {
        unsigned int bitmaskSize = (width * height + 7) / 8;
        
        std::stringstream bitmaskStream; // Use a stringstream to accumulate the bitmask output

        for (unsigned int i = 0; i < bitmaskSize; ++i) {
            for (int bit = 7; bit >= 0; --bit) { // Print bits from high to low
                bitmaskStream << ((bitmask[i] & (1 << bit)) ? '1' : '0');
            }
            if ((i + 1) % (width / 8) == 0) { // New line after each row
                bitmaskStream << std::endl;
            }
        }
        
        // Log the accumulated bitmask
        log_info(bitmaskStream.str());
    }
}


