#include <SFML/Graphics.hpp>

int main() {
	// 建一個 800x600 的視窗
	sf::RenderWindow window(sf::VideoMode(800, 600), "My First SFML Window");

	// 限制 FPS（避免 CPU 100%）
	window.setFramerateLimit(60);

	// 一個代表玩家的小圓形
	float radius = 40.f;
	sf::CircleShape player(radius);
	player.setFillColor(sf::Color::Green);

	// 把圓的原點設在中心，方便以中心移動
	player.setOrigin(radius, radius);
	player.setPosition(400.f, 300.f);  // 螢幕中心附近

	const float speed = 200.f; // 每秒 200 pixel
	sf::Clock clock;           // 用來計算 delta time

	// 遊戲主迴圈
	while (window.isOpen()) {
		// 處理事件（關閉視窗等）
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// 計算這一幀過了多少秒
		float dt = clock.restart().asSeconds();

		// 鍵盤輸入 → 計算移動向量
		sf::Vector2f movement(0.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			movement.x -= speed * dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			movement.x += speed * dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			movement.y -= speed * dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			movement.y += speed * dt;
		}

		// 移動玩家
		player.move(movement);

		// 清畫面 → 畫東西 → 顯示到螢幕
		window.clear(sf::Color::Black);
		window.draw(player);
		window.display();
	}

	return 0;
}
