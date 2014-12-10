class InputHandler {
private:
	bool mouseClicked, mouseDown;
	int x, y;
	static InputHandler* instance;
	InputHandler();

public:
	static InputHandler* getInstance();
	void update();
	bool isMouseDown(){
		return mouseClicked;
	}
	int getMouseX(){return x;}
	int getMouseY(){return y;}
};