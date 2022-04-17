#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"


class Cactus {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string barrier_file_names[];
	size_t score;
public:
	Cactus(float x, float y) {
		std::string barrier_file_names[] = { "spike A.png", "spike B.png" ,"spike C.png" ,"spike D.png" };
		
			size_t num = rand() % CACTUS_TYPE_QTY;
			texture.loadFromFile(IMAGES_FOLDER + barrier_file_names[num]);
			sprite.setTexture(texture);
			sprite.setScale(0.27f, 0.43f);
		sprite.setPosition(x, y);
		score = 0;
	}
	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	void update() {
		sf::Vector2f speed = sf::Vector2f(-8.f, 0.f);
		sprite.move(speed);

		if (sprite.getPosition().x <= -WINDOW_WIDTH) {
			score++;
			size_t line = rand() % 3;
			sprite.setPosition(+WINDOW_WIDTH, WINDOW_HEIGHT / 1.3 - 100);
		}
		spawn();
	}
	void spawn() {
		sf::FloatRect g_bound = sprite.getGlobalBounds();
		float x = WINDOW_WIDTH + 
			static_cast<size_t>(g_bound.width);
		float y = WINDOW_HEIGHT / 1.3 - 100;
		sprite.setPosition(x, y);

	}
	size_t getScore() { return score; }
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};
